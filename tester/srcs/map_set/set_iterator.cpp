/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_iterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:04:36 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:42:48 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common_shared.hpp"
#include <set>
#include "../../../containers/set.hpp"

namespace	n_set
{

int	iterator(void)
{
	NAMESPACE::set<foo<int> >	s;
	NAMESPACE::set<int>::const_iterator	const_it;
	NAMESPACE::set<int>::iterator		it;

	it = const_it;
	std::cout << (const_it == it) << std::endl;

	for (int i = 0; i < 12; ++i)
		s.insert(foo<int>(i));

	std::cout << (--s.end())->getValue() << std::endl;
	std::cout << (*(++s.begin())).getValue() << std::endl;
	return 1;
}

int	r_iterator(void)
{
	NAMESPACE::set<foo<int> >	s;
	NAMESPACE::set<int>::const_reverse_iterator	const_it;
	NAMESPACE::set<int>::reverse_iterator		it;

	it = const_it;
	std::cout << (const_it == it) << std::endl;

	for (int i = 0; i < 12; ++i)
		s.insert(foo<int>(i));

	std::cout << (--s.rend())->getValue() << std::endl;
	std::cout << (*(++s.rbegin())).getValue() << std::endl;
	return 1;
}

}