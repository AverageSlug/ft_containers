/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_bound.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 21:02:35 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 14:44:36 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANGE_BOUND_HPP
# define RANGE_BOUND_HPP
# include "ms_test.hpp"

namespace	n_map_set
{

template <class T>
static void	equal_print(NAMESPACE::pair<T, T> p)
{
	ms_print_it(p.first);
	ms_print_it(p.second);
}

template <class Cont>
static void	_range_bound(Cont c, int key)
{
	ms_print_it(c.lower_bound(key));
	ms_print_it(c.upper_bound(key));
	equal_print(c.equal_range(key));
}

template <class Cont>
void	range_bound(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "range_bound: (size = " << size << ")" << std::endl;
#endif
	if (size < 0)
		size = 8;
	Cont	c;

	for (int i = 0; i < size; ++i)
		ms_insert(c, i);
	_range_bound((const Cont)c, size / 2);
	ms_print_it(c.lower_bound(size - 2));
	ms_print_it(c.upper_bound(1));
}

}
#endif