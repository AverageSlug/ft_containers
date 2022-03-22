/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:48:05 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:12:33 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_set/map_set.hpp"
#include "ms_main.hpp"
#include <map>
#include <utility>
#include "../../containers/map.hpp"
#include "../../containers/utils/utility.hpp"

int	map(void)
{
#ifndef NOPRINT
	std::cout << std::setw(48) << std::string(PURPLE) + "map" + EOC << std::endl;
#endif
	map_set<NAMESPACE::map<int, int> >();
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "compare:" << std::endl;
#endif
	n_map_set::insert<NAMESPACE::map<int, int, std::greater<int> > >(-1);
	return 0;
}