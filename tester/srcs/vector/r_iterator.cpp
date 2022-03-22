/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_iterator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:05:08 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:41:50 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_vec
{

typedef foo<int>										t_foo;
typedef NAMESPACE::vector<t_foo>::const_reverse_iterator		t_cfrit;
typedef NAMESPACE::vector<int>::reverse_iterator		t_rit;
typedef NAMESPACE::vector<int>::const_reverse_iterator	t_const_rit;

static void	r_iterator_arrow(void)
{
	NAMESPACE::vector<t_foo>	v;
	v.push_back(t_foo(1));

	t_cfrit	cfrit = --v.rend();

	std::cout << cfrit->getValue() << std::endl;
}

int	r_iterator(void)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "reverse_iterator:" << std::endl;
#endif
	NAMESPACE::vector<int>	v;
	t_rit	rit = v.rbegin();

	for (int i = 0; i < 8; ++i)
		v.push_back(i);

	std::cout << *(v.begin() + 4) << std::endl;
	std::cout << v.begin() - v.end() << std::endl;

	t_rit	rite = v.rend();

	for (rit = v.rbegin(); rit != rite - 4; ++rit) 
		*rit = 42;
	printSize(v);

	for (rit = v.rend() - 1; rit != v.rbegin(); --rit) 
		*rit = -2;
	printSize(v);

	r_iterator_arrow();
	all_compare(v.rbegin(), --v.rend(), true);
	return 1;
}
}