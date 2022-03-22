#ifndef STACK_HPP
# define STACK_HPP

# include <stdexcept>
# include <deque>
# include "utils.hpp"

namespace ft
{
	template <class T, class Container = std::deque<T> > class stack
	{
		public:
			/*MEMBER TYPES*/
			typedef T			value_type;
			typedef Container	container_type;
			typedef	size_t		size_type;

		protected:
			/*variables*/
			container_type	_c;

		public:
			/*MEMBER FUNCTIONS*/
			explicit stack(const container_type& ctnr = container_type()) :
				_c(ctnr)
			{}

			bool				empty() const
			{
				return (_c.empty());
			}

			size_type			size() const
			{
				return (_c.size());
			}

			value_type&			top()
			{
				return(_c.back());
			}

			const value_type&	top() const
			{
				return (_c.back());
			}

			void				push(const value_type& val)
			{
				_c.push_back(val);
			}

			void				pop()
			{
				_c.pop_back();
			}

			/*FRIENDS*/
			friend bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c == rhs._c);
			}

			friend bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
			{
				return (lhs._c < rhs._c);
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class T, class Container> bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, class Container> bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class Container> bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Container> bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
