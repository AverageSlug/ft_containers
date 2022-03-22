/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_temp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 02:02:08 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:42:04 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_vec
{

void	v_insert(NAMESPACE::vector<int>& v, int val)
{ v.push_back(val); }

void	v_erase(NAMESPACE::vector<int>& v)
{ v.pop_back(); }

int	test_push_pop(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "push/pop back:" << std::endl;
#endif
	push_pop(v_insert, v_erase, size);
	return 1;
}

int	test_clear(void)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "clear:" << std::endl;
#endif
	clear(v_insert, v_erase);
	return 1;
}
}