/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 22:27:20 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 08:33:42 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <deque>
#define SIZE 8

namespace	n_stack
{
typedef	foo<std::string>	t_foo;
typedef	std::deque<t_foo>	t_deq;

void	cont_constructor(void)
{
	NAMESPACE::stack<t_foo, t_deq>		s((t_deq()));

	s.push(t_foo());
	s.push(t_foo());
	s.pop();
	s.push(t_foo());
	printSize(s);
}

void	copy_constructor(void)
{
	NAMESPACE::stack<int>		s;

	for (int i = 0; i < SIZE; ++i)
		s.push((i * 12) >> 1);

	NAMESPACE::stack<int>		s_cpy(s);
	printSize(s_cpy);
}

int	constructor(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "constructor:" << std::endl;
	#endif
	cont_constructor();
	copy_constructor();
	return 1;
}
}