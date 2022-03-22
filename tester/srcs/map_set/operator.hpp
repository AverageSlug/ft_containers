/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 19:50:55 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 16:03:35 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_HPP
# define OPERATOR_HPP
# include "ms_test.hpp"

namespace n_map_set
{

template <class Cont>
static void	comp_op(void)
{
	std::cout << std::endl << std::setw(18) << "compare operator:" << std::endl;
	Cont	c;
	Cont	c2;

	all_compare(c, c2, true);

	ms_insert(c, 12);
	ms_insert(c, 68);
	ms_insert(c2, 86);
	all_compare(c, c2, true);

	c.swap(c2);
	all_compare(c, c2, true);

	c2.erase(c2.begin());
	all_compare(c, c2, true);
}

template <class Cont>
static void	assign_op(void)
{
	std::cout << std::endl << std::setw(18) << "assignation operator:" << std::endl;
	Cont	c;
	Cont	c2;

	ms_insert(c, 99);
	ms_insert(c, 9);

	c2 = c;
	printSize(c2);

	c.erase(c.begin());
	printSize(c2);
}

template <class Cont>
int	all_operator(void)
{
	std::cout << std::endl << std::setw(48) << "operator:" << std::endl;
	assign_op<Cont>();
	comp_op<Cont>();
	return 1;
}

}
#endif