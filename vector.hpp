#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include "utils.hpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> > class	vector
	{
		public:
			//MEMBER TYPES
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef	a														iterator;				//todo
			typedef b														const_iterator;			//todo
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;

			//MEMBER FUNCTIONS
			explicit								vector(const allocator_type& alloc = allocator_type());
			explicit								vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
			vector(const vector& x);
			~vector();
			vector&									operator=(const vector& x);

			//iterators
			iterator								begin();
			const_iterator							begin() const;
			iterator								end();
			const_iterator							end() const;
			reverse_iterator						rbegin();
			const_reverse_iterator					rbegin() const;
			reverse_iterator						rend();
			const_reverse_iterator					rend() const;

			//capacity
			size_type								size() const;
			size_type								max_size() const;
			void									resize(size_type n, value_type val = value_type());
			size_type								capacity() const;
			bool									empty() const;
			void									reserve(size_type n);

			//element access
			reference								operator[](size_type n);
			const_reference							operator[](size_type n) const;
			reference								at(size_type n);
			const_reference							at(size_type n) const;
			reference								front();
			const_reference							front() const;
			reference								back();
			const_reference							back() const;

			//modifiers
			template <class InputIterator> void		assign(InputIterator first, InputIterator last);
			void									assign (size_type n, const value_type& val);
			void									push_back(const value_type& val);
			void									pop_back();
			iterator								insert(iterator position, const value_type& val);
			void									insert(iterator position, size_type n, const value_type& val);
			template <class InputIterator> void		insert (iterator position, InputIterator first, InputIterator last);
			iterator								erase(iterator position);
			iterator								erase(iterator first, iterator last);
			void									swap(vector& x);
			void									clear();

			//allocator
			allocator_type							get_allocator() const;
	};
	//NON-MEMBER FUNCTION OVERLOADS
	template<class T, class Alloc> bool				operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<class T, class Alloc> bool				operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<class T, class Alloc> bool				operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<class T, class Alloc> bool				operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<class T, class Alloc> bool				operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<class T, class Alloc> bool				operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	template<class T, class Alloc>	void			swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}

#endif
