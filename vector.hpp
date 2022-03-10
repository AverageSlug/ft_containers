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
		private:
			/*MEMBER TYPES*/
			typedef T																	value_type;
			typedef Alloc																allocator_type;
			typedef typename allocator_type::reference									reference;
			typedef typename allocator_type::const_reference							const_reference;
			typedef typename allocator_type::pointer									pointer;
			typedef typename allocator_type::const_pointer								const_pointer;
			typedef	std::iterator<std::random_access_iterator_tag, value_type>			iterator;
			typedef std::iterator<const std::random_access_iterator_tag, value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type				difference_type;
			typedef typename allocator_type::size_type									size_type;

			allocator_type							allocator;
			pointer									vector_array;
			size_type								size;
			size_type								capacity;
		public:
			/*MEMBER FUNCTIONS*/
			explicit								vector(const allocator_type& alloc = allocator_type())
			{
				allocator = alloc;
				vector_array = allocator.allocate(0);
				size = 0;
				capacity = 0;
			}

			explicit								vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				allocator = alloc;
				vector_array = allocator.allocate(n);
				size = n;
				capacity = n;
				for (size_type i = 0; i < n; i++)
					allocator.construct(vector_array + i, val);
			}

			template <class InputIterator>			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				allocator = alloc;
				size_type	i;
				for (i = 0; first[i] != *last; i++);
				vector_array = allocator.allocate(i);
				size = i;
				capacity = i;
				for (int i = 0; first != last; first++, i++)
					allocator.construct(vector_array + i, *first);
			}

			vector(const vector& x)
			{
				allocator = x.get_allocator();
				*this = x;
			}

			~vector()
			{
				clear();
				allocator.deallocate(vector_array, size);
			}

			vector&									operator=(const vector& x)
			{
				size = x.size();
				capacity = x.capacity();
				vector_array = allocator.allocate(size);
				for (int i = 0; x[i]; i++)
					allocator.construct(vector_array + i, x[i])
			}

			/*iterators*/
			iterator								begin();
			const_iterator							begin() const;
			iterator								end();
			const_iterator							end() const;
			reverse_iterator						rbegin();
			const_reverse_iterator					rbegin() const;
			reverse_iterator						rend();
			const_reverse_iterator					rend() const;

			/*capacity*/
			size_type								size() const
			{
				return size;
			}

			size_type								max_size() const
			{
				return allocator.max_size();
			}

			void									resize(size_type n, value_type val = value_type())
			{
				if (n <= size)
					for (int i = size - 1; i > n - 1; i--, size--)
						erase(i);
				else
				{
					reserve(n);
					for (int i = size - 1; i < n - 1; i++, size++)
						allocator.construct(vector_array + i, val);
				}
			}

			size_type								capacity() const
			{
				return capacity;
			}

			bool									empty() const
			{
				if (size)
					return true;
				return false;
			}

			void									reserve(size_type n)
			{
				if (n > max_size())
					throw length_error;
				capacity = n;
				allocator.deallocate(vector_array, size);
				vector_array = allocator.allocate(capacity);
			}

			/*element access*/
			reference								operator[](size_type n)
			{
				return vector_array[n];
			}

			const_reference							operator[](size_type n) const
			{
				return vector_array[n];
			}

			reference								at(size_type n)
			{
				if (n >= size)
					throw out_of_range;
				return vector_array[n];
			}

			const_reference							at(size_type n) const
			{
				if (n >= size)
					throw out_of_range;
				return vector_array[n];
			}

			reference								front()
			{
				return vector_array[0];
			}

			const_reference							front() const
			{
				return vector_array[0];
			}

			reference								back()
			{
				return vector_array[size - 1];
			}

			const_reference							back() const
			{
				return vector_array[size - 1];
			}

			/*modifiers*/
			template <class InputIterator> void		assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(0, first, last);
			}

			void									assign (size_type n, const value_type& val)
			{
				clear();
				insert(0, n, val);
			}

			void									push_back(const value_type& val)
			{
				insert(size, val);
			}

			void									pop_back()
			{
				erase(size - 1);
			}

			iterator								insert(iterator position, const value_type& val)
			{
				reserve(size + 1);
				for (int i = size++; i > position; i--)
					vector_array[i] = vector_array[i - 1];
				vector_array[i] = val;
			}

			void									insert(iterator position, size_type n, const value_type& val)
			{
				while (--n)
					insert(position, val);
			}

			template <class InputIterator> void		insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
					insert(position, *first++);
			}

			iterator								erase(iterator position)
			{
				allocator.destroy(vector_array + position);
				size -= 1;
				for (int i = position - 1; i < size; i++)
					vector_array[i] = vector_array[i + 1];
			}

			iterator								erase(iterator first, iterator last)
			{
				while (first != last--)
					erase(first);
			}

			void									swap(vector& x)
			{
				vector	tmp(x);
				x = *this;
				*this = tmp;
			}

			void									clear()
			{
				for (int i = size - 1; i >= 0; i--)
					erase(i);
			}

			/*allocator*/
			allocator_type							get_allocator() const
			{
				return allocator;
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class T, class Alloc> bool				operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template<class T, class Alloc> bool				operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs == rhs));
	}
	template<class T, class Alloc> bool				operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc> bool				operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T, class Alloc> bool				operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc> bool				operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T, class Alloc> void				swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		vector	tmp(x);
		x = y;
		y = tmp;
	}
}

#endif
