/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:11:03 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 08:34:46 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_stack
{
static void	comp_op(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(18) << "compare operator:" << std::endl;
	#endif
	NAMESPACE::stack<int>	s;
	NAMESPACE::stack<int>	s2;

	s.push(68);
	s2.push(86);

	all_compare(s, s2, true);

	s2.pop();

	all_compare(s, s2, true);
}

static void	assign_op(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(18) << "assignation operator:" << std::endl;
	#endif
	NAMESPACE::stack<int>	s;
	NAMESPACE::stack<int>	s2;

	s.push(99);
	s.push(99);
	s.pop();

	s2 = s;
	s.pop();
	printSize(s2);
}

int	all_operator(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "operator:" << std::endl;
	#endif
	assign_op();
	comp_op();
	return 1;
}
}