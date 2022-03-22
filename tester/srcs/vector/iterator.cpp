/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:05:08 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:41:34 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_vec
{

typedef foo<int>								t_foo;
typedef NAMESPACE::vector<t_foo>::const_iterator	t_cfit;
typedef NAMESPACE::vector<int>::iterator		t_it;
typedef NAMESPACE::vector<int>::const_iterator	t_const_it;

static void	iterator_arrow(void)
{
	NAMESPACE::vector<t_foo>	v;
	v.push_back(t_foo(1));

	t_cfit	cfit = --v.end();

	std::cout << cfit->getValue() << std::endl;
}

int	iterator(void)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "iterator:" << std::endl;
#endif
	NAMESPACE::vector<int>	v;
	t_it	it = v.begin();

	for (int i = 0; i < 8; ++i)
		v.push_back(i);

	std::cout << *(v.begin() + 4) << std::endl;
	std::cout << v.end() - v.begin() << std::endl;
	std::cout << *(v.end() - 1) << std::endl;

	t_it	ite = v.end();

	for (it = v.begin(); it != ite - 4; ++it) 
		*it = 42;
	printSize(v);

	for (it = v.end() - 1; it != v.begin(); --it) 
		*it = -2;
	printSize(v);

	iterator_arrow();
	all_compare(v.begin(), --v.end(), true);
	return 1;
}
}