/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_count.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:41:01 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 14:39:48 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_COUNT_HPP
# define FIND_COUNT_HPP
# include "ms_test.hpp"

namespace	n_map_set
{

template <class Cont>
static void	_find_count(Cont& c, int key)
{
	ms_print_it(c.find(key));
#ifndef NOPRINT
	std::cout << c.count(key) << std::endl;
#endif
}

template <class Cont>
void	find_count(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "find_count: (size = " << size << ")" << std::endl;
#endif
	if (size < 0)
		size = 8;
	Cont	c;

	for (int i = 0; i < size; ++i)
		ms_insert(c, i);
	_find_count((const Cont)c, size - 1);
	_find_count(c, 1);
	_find_count(c, size / 2);
	_find_count(c, 0);
}

}
#endif