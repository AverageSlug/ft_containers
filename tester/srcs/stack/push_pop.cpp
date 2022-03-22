/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:59:50 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 08:34:25 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#define SIZE 12

namespace	n_stack
{

void	s_insert(NAMESPACE::stack<int>& s, int val)
{ s.push(val); }

void	s_erase(NAMESPACE::stack<int>& s)
{ s.pop(); }

int	test_push_pop(void)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "push/pop:" << std::endl;
#endif
	push_pop(s_insert, s_erase, SIZE);
	return 1;
}
}