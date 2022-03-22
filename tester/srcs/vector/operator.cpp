/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:11:03 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 14:31:15 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_vec
{

static void	comp_op(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(18) << "compare operator:" << std::endl;
	#endif
	NAMESPACE::vector<int>	v;
	NAMESPACE::vector<int>	v2;

	v.push_back(68);
	v2.push_back(86);
	all_compare(v, v2, true);

	v.swap(v2);
	all_compare(v, v2, true);

	v2.pop_back();
	all_compare(v, v2, true);

	std::cout << NAMESPACE::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end()) << std::endl;
	std::cout << NAMESPACE::lexicographical_compare(v.begin(), v.end(), v2.begin(), v2.end(), std::greater<int>()) << std::endl;
	std::cout << NAMESPACE::equal(v2.begin(), v2.end(), v.begin()) << std::endl;
	std::cout << NAMESPACE::equal(v2.begin(), v2.end(), v.begin(), std::equal_to<int>()) << std::endl;
}

static void	assign_op(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(18) << "assignation operator:" << std::endl;
	#endif
	NAMESPACE::vector<int>	v;
	NAMESPACE::vector<int>	v2;

	v.push_back(99);
	v.push_back(99);
	v.push_back(99);
	v.push_back(99);
	v.push_back(99);

	v2 = v;
	v.pop_back();
	printSize(v2);
}

int	all_operator(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "operator:" << std::endl;
	#endif
	assign_op();
	std::cout << "aa" << std::endl;
	comp_op();
	std::cout << "aa" << std::endl;
	return 1;
}
}