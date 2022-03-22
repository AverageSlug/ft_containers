#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iterator>
# include <stdexcept>
# include "utils.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > class map
	{
		public:
			/*MEMBER TYPES*/
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			class												value_compare
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;
				protected:
					Compare			comp;
					value_compare(Compare c) : comp(c) {}
				public:
					bool	operator()(const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
			};
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef ft::map_iterator<value_type>				iterator;
			typedef ft::map_iterator<const value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:
			/*variables*/
			key_compare		_key;
			value_compare	_value;
			allocator_type	_allocator;
			size_type		_size;

		public:
			/*MEMBER FUNCTIONS*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_key(comp),
				_value(std::less<key_type>(comp)),
				_allocator(alloc),
				_size(0),
				_root(t_list())
			{}

			template<class InputIterator> map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_key(comp),
				_value(std::less<key_type>(comp)),
				_allocator(alloc),
				_size(0),
				_root(t_list())
			{
				while (first != last)
				{
					insert(*first);
					_allocator.construct(&(*_root), *first++);
					_size++;
				}
			}

			map(const map& x) :
				_key(x._key),
				_value(x._value),
				_allocator(x._allocator),
				_size(0),
				_root(t_list())
			{
				*this = x;
			}

			~map()
			{
				clear();
				while ((*lower_bound()).first != (*_root).first)
					_allocator.deallocate(*lower_bound(), 1);
				while ((*upper_bound()).first != (*_root).first)
					_allocator.deallocate(*upper_bound(), 1);
				_allocator.deallocate(&(*_root), 1);
			}

			map&								operator=(const map& x)
			{
				clear();
				for (iterator it = x.begin(); it != x.end(); it++)
					insert(*it);
				return (*this);
			}

			/*iterators*/
			iterator							begin()
			{
				return (lower_bound());
			}

			const_iterator						begin() const
			{
				return (lower_bound());
			}

			iterator							end()
			{
				return (upper_bound());
			}

			const_iterator						end() const
			{
				return (upper_bound());
			}

			reverse_iterator					rbegin()
			{
				if (empty())
					return (reverse_iterator());
				return (reverse_iterator(--end()));
			}

			const_reverse_iterator				rbegin() const
			{
				if (empty())
					return (const_reverse_iterator());
				return (const_reverse_iterator(--end()));
			}

			reverse_iterator					rend()
			{
				if (empty())
					return (reverse_iterator());
				return (reverse_iterator(--begin()));
			}

			const_reverse_iterator				rend() const
			{
				if (empty())
					return (const_reverse_iterator());
				return (const_reverse_iterator(--begin()));
			}

			/*capacity*/
			bool								empty() const
			{
				if (size())
					return (false);
				return (true);
			}

			size_type							size() const
			{
				return _size;
			}

			size_type							max_size() const
			{
				return _allocator.max_size();
			}

			/*element access*/
			mapped_type&						operator[](const key_type& k)
			{
				return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
			}

			/*modifiers*/
			pair<iterator, bool>				insert(const value_type& val)
			{
				iterator	it = find(val.first);
				if (it != end())
					return (pair<iterator, bool>(it, false));
				t_list		lit = _root;
				while (1)
				{
					if (val.first > (*lit).first)
					{
						lit = lit.right;
						if (lit)
							continue ;
						lit = t_list(val);
						break ;
					}
					else if (val.first < (*lit).first)
					{
						lit = lit.left;
						if (lit)
							continue ;
						lit = t_list(val);
						break ;
					}
				}
				size++;
				return (pair<iterator, bool>(iterator(*lit), true));
			}//

			iterator							insert(iterator position, const value_type& val)
			{
				iterator	it = find(val.first);
				if (it != end())
					return (it);
				size_type	p = &(*position) - _begin;
				pointer		b = _allocator.allocate(size() + 1);
				pointer		e = b + size() + 1;
				for (size_type i = 0; i < p; i++)
					_allocator.construct(b + i, *(_begin + i));
				_allocator.construct(b + p, val);
				for (size_type i = 0; i < size() - p; i++)
					_allocator.construct(e - i - 1, *(_end - i - 1));
				for (size_type i = 0; i < size(); i++)
					_allocator.destroy(_begin + i);
				if (_begin)
					_allocator.deallocate(_begin, size());
				_begin = b;
				_end = e;
				return (position);
			}//

			template<class InputIterator> void	insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(_root, *first++);
			}//

			void								erase(iterator position)
			{
				iterator	p(position);
				_allocator.destroy(&(*position));
				while (position != end())
					_allocator.construct(&(*position), *(++position));
				_allocator.destroy(&(*position));
				_end--;
			}//

			size_type							erase(const key_type& k)
			{
				iterator	it = find(k);
				if (it != end())
					erase(it);
				return (1);
			}//

			void								erase(iterator first, iterator last)
			{
				while (first != last--)
					erase(first);
			}//

			void								swap(map& x)
			{
				map<Key, T>	tmp(x);
				x = *this;
				*this = tmp;
			}

			void								clear()
			{
				erase(begin(), end());
			}

			/*observers*/
			key_compare							key_comp() const
			{
				return _key;
			}//

			value_compare						value_comp() const
			{
				return _value;
			}//

			/*operations*/
			iterator							find(const key_type& k)
			{
				iterator	b(_begin);
				iterator	e(_end);
				while (b != e)
				{
					if ((*b).first == k)
						return (b);
					b++;
				}
				return (b);
			}//

			const_iterator						find(const key_type& k) const
			{
				const_iterator	b(_begin);
				const_iterator	e(_end);
				while (b != e)
				{
					if ((*b).first == k)
						return (b);
					b++;
				}
				return (b);
			}//

			size_type							count(const key_type& k) const
			{
				if (find(k) != end())
					return (1);
				return (0);
			}

			iterator							lower_bound(const key_type& k)
			{
				t_list	t = _root;
				while (t.left)
					t = t.left;
				return (iterator(*t));
			}

			const_iterator						lower_bound(const key_type& k) const
			{
				t_list	t = _root;
				while (t.left)
					t = t.left;
				return (const_iterator(*t));
			}

			iterator							upper_bound(const key_type& k)
			{
				t_list	t = _root;
				while (t.right)
					t = t.right;
				return (iterator(*t));
			}

			const_iterator						upper_bound(const key_type& k) const
			{
				t_list	t = _root;
				while (t.right)
					t = t.right;
				return (const_iterator(*t));
			}

			pair<const_iterator, const_iterator>equal_range(const key_type& k) const
			{
				(void)k;
				return (pair<const_iterator, const_iterator>(begin(), end()));
			}//

			pair<iterator,iterator>				equal_range(const key_type& k)
			{
				(void)k;
				return (pair<iterator, iterator>(begin(), end()));
			}//

			/*allocator*/
			allocator_type						get_allocator() const
			{
				return _allocator;
			}
	};
}

#endif