/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_shared.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:22:40 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:45:16 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_SHARED_HPP
# define COMMON_SHARED_HPP
# include "test_shared.hpp"

template <class Cont>
void	printSize(const Cont& c)
{
#ifndef NOPRINT
	std::cout << "size: " << c.size() << std::endl;
	for (typename Cont::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << std::endl;
#endif
	(void)c;
}

template <class T, class U>
void	printSize(const NAMESPACE::map<T, T, U>& c)
{
#ifndef NOPRINT
	std::cout << "size: " << c.size() << std::endl;
	for (typename NAMESPACE::map<T, T>::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << it->first << " . " << it->second << std::endl;
#endif
	(void)c;
}

template <class T, class U>
void	printSize(NAMESPACE::stack<T, U>& s)
{
#ifndef NOPRINT
	std::cout << "size: " << s.size() << std::endl;
	while (s.size() != 0)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
#endif
	(void)s;
}

template <class Cont>
void	push_pop(void (*push)(Cont&, int), void (*pop)(Cont&), int size)
{
	Cont	c;

	for (int i = 0; i < size; ++i)
	{
		push(c, i);
		if ((i % 2))
			pop(c);
	}
	printSize(c);

	while (c.size())
		pop(c);
	printSize(c);
}

template <class Cont>
void	clear(void (*insert)(Cont&, int), void (*erase)(Cont&))
{
	Cont	c;

	c.clear();
	for (int i = 0; i < 2; ++i)
		insert(c, i);
	printSize(c);

	erase(c);
	c.clear();
	printSize(c);

	for (int i = 0; i < 8; ++i)
		insert(c, i);
	printSize(c);

	c.clear();
	printSize(c);
}

template <class Cont>
int	access_test(Cont c, void (*f)(Cont, int), typename Cont::size_type more)
{
	for (typename Cont::size_type i = 0; i < c.size() + more; ++i)
	{
		try
		{ f(c, i); }
		catch (const std::exception& e)
		{ std::cout << e.what() << std::endl; }
	}
	return 1;
}

template <class T>
static void	all_compare(T lhs, T rhs, bool repeat)	
{
#ifndef NOPRINT
	std::cout << (lhs == rhs) << std::endl;
	std::cout << (lhs != rhs) << std::endl;
	std::cout << (lhs < rhs) << std::endl;
	std::cout << (lhs <= rhs) << std::endl;
	std::cout << (lhs > rhs) << std::endl;
	std::cout << (lhs >= rhs) << std::endl;
#endif
	if (repeat)
		all_compare(rhs, lhs, false);
}

template <typename T>
class	foo
{
private:
	T	value;
public:
	foo(const T& value = T()) : value(value) {}
	~foo(void) {}
	T getValue(void) const { return this->value; }
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, const foo<T>& bar) { return o << bar.getValue(); }

template <typename T>
bool	operator<(const foo<T> &lhs, const foo<T> &rhs) { return lhs.getValue() < rhs.getValue(); }


#endif

