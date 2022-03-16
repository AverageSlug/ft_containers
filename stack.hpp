#ifndef STACK_HPP
# define STACK_HPP

# include <stdexcept>
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

			/*MEMBER FUNCTIONS*/
			explicit stack(const container_type& ctnr = container_type());
			bool				empty() const;
			size_type			size() const;
			value_type&			top();
			const value_type&	top() const;
			void				push(const value_type& val);
			void				pop();
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class T, class Container> bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.top() == rhs.top());
	}

	template<class T, class Container> bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.top() != rhs.top());
	}

	template<class T, class Container> bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.top() < rhs.top());
	}

	template<class T, class Container> bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.top() <= rhs.top());
	}

	template<class T, class Container> bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.top() > rhs.top());
	}

	template<class T, class Container> bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.top() >= rhs.top());
	}
}

#endif
