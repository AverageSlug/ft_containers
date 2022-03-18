#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iterator>
# include <stdexcept>
# include "utils.hpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> > class	vector
	{
		public:
			/*MEMBER TYPES*/
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef	ft::vector_iterator<value_type>				iterator;
			typedef ft::vector_iterator<value_type const>		const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		private:
			/*variables*/
			allocator_type							_allocator;
			pointer									_begin;
			pointer									_end;
			size_type								_capacity;
		public:
			/*MEMBER FUNCTIONS*/
			explicit								vector(const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_begin(NULL),
				_end(NULL),
				_capacity(0)
			{}

			explicit								vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_begin(NULL),
				_end(NULL),
				_capacity(0)
			{
				_begin = _allocator.allocate(n);
				_end = _begin;
				_capacity = n;
				while (n--)
					_allocator.construct(_end++, val);
			}

			template <class InputIterator>			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) :
				_allocator(alloc),
				_begin(NULL),
				_end(NULL),
				_capacity(0)
			{
				size_type	i;
				for (i = 0; &(*last) - &(first[i]); i++);
				_begin = _allocator.allocate(i);
				_end = _begin;
				_capacity = i;
				while (first != last)
					_allocator.construct(_end++, *first++);
			}

			vector(const vector& x) :
				_allocator(x.get_allocator()),
				_begin(NULL),
				_end(NULL),
				_capacity(0)
			{
				*this = x;
			}

			~vector()
			{
				clear();
				_allocator.deallocate(_begin, _capacity);
			}

			vector&									operator=(const vector& x)
			{
				_begin = _allocator.allocate(x.size());
				_capacity = x.capacity();
				_end = _begin;
				for (size_type i = 0; i < x.size(); i++)
					_allocator.construct(_end++, x[i]);
				return (*this);
			}

			/*iterators*/
			iterator								begin()
			{
				return (_begin);
			}

			const_iterator							begin() const
			{
				return (_begin);
			}

			iterator								end()
			{
				if (empty())
					return (_begin);
				return (_end);
			}

			const_iterator							end() const
			{
				if (empty())
					return (_begin);
				return (_end);
			}

			reverse_iterator						rbegin()
			{
				if (empty())
					return (reverse_iterator());
				return (reverse_iterator(end() - 1));
			}

			const_reverse_iterator					rbegin() const
			{
				if (empty())
					return (const_reverse_iterator());
				return (const_reverse_iterator(end() - 1));
			}

			reverse_iterator						rend()
			{
				if (empty())
					return (reverse_iterator());
				return (reverse_iterator(begin() - 1));
			}

			const_reverse_iterator					rend() const
			{
				if (empty())
					return (const_reverse_iterator());
				return (const_reverse_iterator(begin() - 1));
			}

			/*capacity*/
			size_type								size() const
			{
				return (_end - _begin);
			}

			size_type								max_size() const
			{
				return _allocator.max_size();
			}

			void									resize(size_type n, value_type val = value_type())
			{
				if (n <= size())
					while (n < size())
						erase(_begin + n);
				else
				{
					reserve(n);
					while (size() < n)
						_allocator.construct(_end++, val);
				}
			}

			size_type								capacity() const
			{
				return _capacity;
			}

			bool									empty() const
			{
				if (size())
					return false;
				return true;
			}

			void									reserve(size_type n)
			{
				if (n > max_size())
					throw std::length_error("L");
				if (n <= _capacity)
					return ;
				pointer		t_b = _begin;
				pointer		t_e = _end;
				size_type	s = size();
				size_type	c = capacity();
				_begin = _allocator.allocate(n);
				_capacity = n;
				_end = _begin;
				while (t_b != t_e)
				{
					_allocator.construct(_end, *t_b);
					_end++;
					t_b++;
				}
				_allocator.deallocate(t_b - s, c);
			}

			/*element access*/
			reference								operator[](size_type n)
			{
				return _begin[n];
			}

			const_reference							operator[](size_type n) const
			{
				return _begin[n];
			}

			reference								at(size_type n)
			{
				if (n >= size())
					throw std::out_of_range("OOB");
				return _begin[n];
			}

			const_reference							at(size_type n) const
			{
				if (n >= size())
					throw std::out_of_range("OOB");
				return _begin[n];
			}

			reference								front()
			{
				return (*_begin);
			}

			const_reference							front() const
			{
				return (*_begin);
			}

			reference								back()
			{
				return (*(_end - 1));
			}

			const_reference							back() const
			{
				return (*(_end - 1));
			}

			/*modifiers*/
			template <class InputIterator> void		assign(InputIterator first, InputIterator last)
			{
				clear();
				_allocator.deallocate(_begin, _capacity);
				size_type	i;
				for (i = 0; &(*last) - &first[i] > 0; i++);
				_begin = _allocator.allocate(i);
				_end = _begin;
				_capacity = i;
				while (first != last)
					_allocator.construct(_end++, *first++);
			}

			void									assign(size_type n, const value_type& val)
			{
				clear();
				_allocator.deallocate(_begin, _capacity);
				_begin = _allocator.allocate(n);
				_end = _begin;
				_capacity = n;
				while (n--)
					_allocator.construct(_end++, val);
			}

			void									push_back(const value_type& val)
			{
				insert(_end, val);
			}

			void									pop_back()
			{
				erase(_end - 1);
			}

			iterator								insert(iterator position, const value_type& val)
			{
				size_type	p = &(*position) - _begin;
				if (_capacity >= size() + 1)
				{
					for (size_type i = 0; i < size() - p; i++)
						_allocator.construct(_end - i, *(_end - i - 1));
					_end++;
					_allocator.construct(&(*position), val);
				}
				else
				{
					int		new_capacity;
					if (size())
						new_capacity = size() * 2;
					else
						new_capacity = 1;
					pointer		b = _allocator.allocate(new_capacity);
					pointer		e = b + size() + 1;
					for (size_type i = 0; i < p; i++)
						_allocator.construct(b + i, *(_begin + i));
					_allocator.construct(b + p, val);
					for (size_type i = 0; i < size() - p; i++)
						_allocator.construct(e - i - 1, *(_end - i - 1));
					for (size_type i = 0; i < size(); i++)
						_allocator.destroy(_begin + i);
					if (_begin)
						_allocator.deallocate(_begin, _capacity);
					_begin = b;
					_end = e;
					_capacity = new_capacity;
				}
				return (iterator(_begin + p));
			}

			void									insert(iterator position, size_type n, const value_type& val)
			{
				while (n > 0)
				{
					position = insert(position, val);
					n--;
				}
			}

			template <class InputIterator> void		insert(iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
					position = insert(position, *first++) + 1;
			}

			iterator								erase(iterator position)
			{
				iterator	p(position);
				_allocator.destroy(&(*position));
				while (position != end())
				{
					_allocator.construct(&(*position), *(position + 1));
					position++;
				}
				_allocator.destroy(&(*position));
				_end--;
				return (p);
			}

			iterator								erase(iterator first, iterator last)
			{
				while (first != last--)
					erase(first);
				return (first);
			}

			void									swap(vector& x)
			{
				vector<T>	tmp(x);
				x = *this;
				*this = tmp;
			}

			void									clear()
			{
				erase(begin(), end());
			}

			/*allocator*/
			allocator_type							get_allocator() const
			{
				return _allocator;
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class T, class Alloc> bool				operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Alloc> bool				operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template<class T, class Alloc> bool				operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc> bool				operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc> bool				operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc> bool				operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T, class Alloc> void				swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}
}

#endif
