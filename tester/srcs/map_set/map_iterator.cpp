/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:04:36 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:42:07 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common_shared.hpp"
#include <map>
#include "../../../containers/set.hpp"

namespace	n_map
{

int	iterator(void)
{
	NAMESPACE::map<int, int>					m;
	NAMESPACE::map<int, int>::const_iterator	const_it;
	NAMESPACE::map<int, int>::iterator			it;

	std::cout << (const_it == it) << std::endl;

	for (int i = 0; i < 12; ++i)
		m.insert(NAMESPACE::make_pair(i, i));

	std::cout << (--m.end())->first << std::endl;
	std::cout << (*(++m.begin())).first << std::endl;
	
	return 1;
}

int	r_iterator(void)
{
	NAMESPACE::map<int, int>					m;
	NAMESPACE::map<int, int>::const_reverse_iterator	const_it;
	NAMESPACE::map<int, int>::reverse_iterator			it;

	std::cout << (const_it == it) << std::endl;

	for (int i = 0; i < 12; ++i)
		m.insert(NAMESPACE::make_pair(i, i));

	std::cout << (--m.rend())->first << std::endl;
	std::cout << (*(++m.rbegin())).first << std::endl;
	
	return 1;
}

}