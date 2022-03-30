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
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::bst<value_type>												bst_type;
			typedef bst_type*															bst_pointer;
			typedef typename allocator_type::template rebind<bst_type>::other			bst_allocator;
			typedef ft::map_iterator<value_type, bst_type>							iterator;
			typedef ft::map_iterator<const value_type, bst_type>				const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t										size_type;

		private:
			/*variables*/
			allocator_type	_allocator;
			bst_allocator	_bst_allocator;
			size_type		_size;
			bst_pointer		_root;
			key_compare		_comp;

			/*functions*/
			bst_pointer		_bst_insert(bst_pointer bst, const value_type& val, bst_pointer parent = NULL)
			{
				if (!bst)
				{
					bst = _bst_allocator.allocate(1);
					_bst_allocator.construct(bst, bst_type(val, NULL, NULL, parent));
					if (!_root)
						_root = bst;
					else if (key_comp()(parent->val.first, bst->val.first))
						parent->right = bst;
					else
						parent->left = bst;
					_size++;
				}
				else if (key_comp()(val.first, bst->val.first))
					return (_bst_insert(bst->left, val, bst));
				else
					return (_bst_insert(bst->right, val, bst));
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
						_bst_allocator.destroy(bst);
						return (NULL);
					}
					else if (!bst->left)
					{
						bst_pointer	t = bst->right;
						t->parent = bst->parent;
						_bst_allocator.destroy(bst);
						return (t);
					}
					else if (!bst->right)
					{
						bst_pointer	t = bst->left;
						t->parent = bst->parent;
						_bst_allocator.destroy(bst);
						return (t);
					}
					bst_pointer	t = smallest_leaf(bst->right);
					bst_pointer	l = bst->left;
					bst_pointer	r = bst->right;
					_bst_allocator.destroy(bst);
					_bst_allocator.construct(bst, bst_type(t->val, l, r));
					bst->right = _bst_erase(bst->right, t->val);
				}
				return (bst);
			}

		public:
			/*MEMBER FUNCTIONS*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_bst_allocator(bst_allocator(_allocator)),
				_size(0),
				_root(NULL),
				_comp(comp)
			{}

			template<class InputIterator> map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_bst_allocator(bst_allocator(_allocator)),
				_size(0),
				_root(NULL),
				_comp(comp)
			{
				insert(first, last);
			}

			map(const map& x) :
				_allocator(x._allocator),
				_bst_allocator(x._bst_allocator),
				_size(x._size),
				_root(x._root),
				_comp(x._comp)
			{
				*this = x;
			}

			~map()
			{
				clear();
				if (_root)
					_bst_allocator.deallocate(_root, _size);
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
				return (iterator(smallest_leaf(_root), _root));
			}

			const_iterator						begin() const
			{
				return (const_iterator(smallest_leaf(_root), _root));
			}

			iterator							end()
			{
				return (iterator(NULL, _root));
			}

			const_iterator						end() const
			{
				return (const_iterator(NULL, _root));
			}

			reverse_iterator					rbegin()
			{
				return (reverse_iterator(iterator(largest_leaf(_root), _root, 1)));
			}

			const_reverse_iterator				rbegin() const
			{
				return (const_reverse_iterator(const_iterator(largest_leaf(_root), _root, 1)));
			}

			reverse_iterator					rend()
			{
				return (reverse_iterator(iterator(NULL, _root, 1)));
			}

			const_reverse_iterator				rend() const
			{
				return (const_reverse_iterator(const_iterator(NULL, _root, 1)));
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
				return _bst_allocator.max_size();
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
				return (pair<iterator, bool>(iterator(_bst_insert(_root, val), _root), true));
			}

			iterator							insert(iterator position, const value_type& val)
			{
				(void)position;
				return ((insert(val)).first);
			}

			template<class InputIterator> void	insert(InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(*first++);
			}

			void								erase(iterator position)
			{
				erase(position->first);
			}

			size_type							erase(const key_type& k)
			{
				iterator	it = find(k);
				if (!_root || it == end())
					return (0);
				_size--;
				_root = _bst_erase(_root, value_type(k, it->second));
				return (1);
			}

			void								erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}

			void								swap(map& x)
			{
				allocator_type	a = x._allocator;
				bst_allocator	b = x._bst_allocator;
				size_type		s = x._size;
				bst_pointer		r = x._root;
				key_compare		c = x._comp;

				x._allocator = _allocator;
				x._bst_allocator = _bst_allocator;
				x._size = _size;
				x._root = _root;
				x._comp = _comp;

				_allocator = a;
				_bst_allocator = b;
				_size = s;
				_root = r;
				_comp = c;
			}

			void								clear()
			{
				for (size_type i = 0; i < _size; i++)
					_bst_allocator.destroy(_root);
				_size = 0;
				_root = NULL;
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
					if (!key_comp()(it->first, k) && !key_comp()(k, it->first))
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
					if (!key_comp()(it->first, k) && !key_comp()(k, it->first))
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
					if (key_comp()(k, it->first))
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
					if (key_comp()(k, it->first))
						break ;
					it++;
				}
				return (it);
			}

			pair<const_iterator, const_iterator>equal_range(const key_type& k) const
			{
				return (pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}

			pair<iterator,iterator>				equal_range(const key_type& k)
			{
				return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			/*allocator*/
			allocator_type						get_allocator() const
			{
				return _allocator;
			}
	};
	template<class Key, class T, class Compare, class Alloc> bool	operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class Key, class T, class Compare, class Alloc> bool	operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class Key, class T, class Compare, class Alloc> bool	operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Alloc> bool	operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc> bool	operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Alloc> bool	operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template<class Key, class T, class Compare, class Alloc> void	swap(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif