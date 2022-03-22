/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:48:05 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:37:10 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_main.hpp"
#include <functional>

int	set(void)
{
#ifndef NOPRINT
	std::cout << std::setw(48) << std::string(PURPLE) + "set" + EOC << std::endl;
#endif
	n_set::iterator();
	n_set::r_iterator();
	map_set<NAMESPACE::set<int> >();
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "compare:" << std::endl;
#endif
	n_map_set::insert<NAMESPACE::set<int, std::greater<int> > >(-1);
	return 0;
}