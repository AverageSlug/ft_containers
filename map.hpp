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
			typedef Alloc									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::bst<value_type>											bst_type;
			typedef bst_type*														bst_pointer;
			typedef typename allocator_type::template rebind<bst_type>::other		bst_allocator;
			typedef ft::map_iterator<value_type, bst_type>						iterator;
			typedef ft::map_iterator<const value_type, bst_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t									size_type;

		private:
			/*typedefs*/


			/*variables*/
			allocator_type	_allocator;
			size_type		_size;
			bst_pointer		_root;
			key_compare		_comp;

			/*functions*/
			bst_pointer		_bst_insert(bst_pointer bst, const value_type& val)
			{
				if (!_root)
					_root = bst;
				if (!bst)
				{
					bst = bst_allocator().allocate(1);
					bst_allocator().construct(bst, bst_type(val));
				}
				else if (key_comp()(val.first, bst->val.first))
				{
					bst->left = _bst_insert(bst->left, val);
					bst->left->parent = bst;
				}
				else
				{
					bst->right = _bst_insert(bst->right, val);
					bst->right->parent = bst;
				}
				return (bst);
			}

			bst_pointer		_bst_erase(bst_pointer bst, const value_type& val)
			{
				if (!bst)
					return (bst);
				else if (key_comp()(val.first, bst->val.first))
					bst->left = _bst_erase(bst->left, val);
				else if (key_comp()(bst->val.first, val.first))
					bst->right = _bst_erase(bst->right, val);
				else
				{
					if (!bst->left && !bst->right)
					{
						_allocator.destroy(&bst->val);
						return (NULL);
					}
					else if (!bst->left)
					{
						bst_pointer	t = bst->right;
						t->parent = bst->parent;
						_allocator.destroy(&bst->val);
						return (t);
					}
					else if (!bst->right)
					{
						bst_pointer	t = bst->left;
						t->parent = bst->parent;
						_allocator.destroy(&bst->val);
						return (t);
					}
					bst_pointer	t = smallest_leaf(bst->right);
					_allocator.destroy(&bst->val);
					_allocator.construct(&bst->val, t->val);
					bst->right = _bst_erase(bst->right, t->val);
				}
				return (bst);
			}

		public:
			/*MEMBER FUNCTIONS*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_size(0),
				_root(NULL),
				_comp(comp)
			{}

			template<class InputIterator> map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_size(0),
				_root(NULL),
				_comp(comp)
			{
				insert(first, last);
			}

			map(const map& x) :
				_allocator(x._allocator),
				_size(x._size),
				_root(x._root),
				_comp(x._comp)
			{
				*this = x;
			}

			~map()
			{
				clear();
				while (smallest_leaf(_root) != _root)
					bst_allocator().deallocate(smallest_leaf(_root), 1);
				while (largest_leaf(_root) != _root)
					bst_allocator().deallocate(largest_leaf(_root), 1);
				bst_allocator().deallocate(_root, 1);
			}

			map&								operator=(const map& x)
			{
				clear();
				insert(x.begin(), x.end());
				return (*this);
			}

			/*iterators*/
			iterator							begin()
			{
				return (iterator(smallest_leaf(_root)));
			}

			const_iterator						begin() const
			{
				return (const_iterator(smallest_leaf(_root)));
			}

			iterator							end()
			{
				if (!_root || !size())
					return (iterator(largest_leaf(_root)));
				return (iterator(largest_leaf(_root)->right));
			}

			const_iterator						end() const
			{
				if (!_root || !size())
					return (const_iterator(largest_leaf(_root)));
				return (const_iterator(largest_leaf(_root)->right));
			}

			reverse_iterator					rbegin()
			{
				return (reverse_iterator(end()));
			}

			const_reverse_iterator				rbegin() const
			{
				return (const_reverse_iterator(end()));
			}

			reverse_iterator					rend()
			{
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator				rend() const
			{
				return (const_reverse_iterator(begin()));
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
				_size++;
				return (pair<iterator, bool>(iterator(_bst_insert(_root, val)), true));
			}

			iterator							insert(iterator position, const value_type& val)
			{
				(void)position;
				return ((insert(val)).first);
			}//

			template<class InputIterator> void	insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*first++);
			}

			void								erase(iterator position)
			{
				if (!_root)
					return ;
				_size--;
				_root = _bst_erase(_root, value_type(position->first, position->second));
			}

			size_type							erase(const key_type& k)
			{
				iterator	it = find(k);
				if (!_root)
					return (0);
				_size--;
				_root = _bst_erase(_root, value_type(k, it->second));
				return (1);
			}

			void								erase(iterator first, iterator last)
			{
				while (first != last--)
					erase(first);
			}

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
				return _comp;
			}

			value_compare						value_comp() const
			{
				return value_compare(key_compare());
			}

			/*operations*/
			iterator							find(const key_type& k)
			{
				iterator	it = begin();
				while (it != end())
				{
					if (key_comp()(it->first, k) && key_comp()(k, it->first))
						break ;
					it++;
				}
				return (it);
			}

			const_iterator						find(const key_type& k) const
			{
				const_iterator	it = begin();
				while (it != end())
				{
					if (key_comp()(it->first, k) && key_comp()(k, it->first))
						break ;
					it++;
				}
				return (it);
			}

			size_type							count(const key_type& k) const
			{
				if (!_root)
					return (0);
				const_iterator	it = begin();
				if (!key_comp()(it->first, k) && !key_comp()(k, it->first))
					return (1);
				while (it != end())
				{
					if (!key_comp()(it->first, k) && !key_comp()(k, it->first))
						return (1);
					it++;
				}
				return (0);
			}

			iterator							lower_bound(const key_type& k)
			{
				iterator	it = begin();
				while (it != end())
				{
					if (!key_comp()(it->first, k))
						break ;
					it++;
				}
				return (it);
			}

			const_iterator						lower_bound(const key_type& k) const
			{
				const_iterator	it = begin();
				while (it != end())
				{
					if (!key_comp()(it->first, k))
						break ;
					it++;
				}
				return (it);
			}

			iterator							upper_bound(const key_type& k)
			{
				iterator	it = begin();
				while (it != end())
				{
					if (key_comp()(it->first, k))
						break ;
					it++;
				}
				return (it);
			}

			const_iterator						upper_bound(const key_type& k) const
			{
				const_iterator	it = begin();
				while (it != end())
				{
					if (key_comp()(it->first, k))
						break ;
					it++;
				}
				return (it);
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