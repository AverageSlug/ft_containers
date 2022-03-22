/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:18:25 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:40:53 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <list>

namespace	n_vec
{

static int	inputItAssign(void)
{
	std::list<std::string>	strLst;
	NAMESPACE::vector<std::string>	strV;

	for (int i = 0; i < 5; ++i)
		strLst.push_back("a" + std::to_string(i));

	strV.assign(strLst.begin(), strLst.end());
	printSize(strV);
	return 1;
}

static int	inputItAssign2(int size)
{
	std::list<int>	lst;

	for (int i = 0; i < size; ++i)
		lst.push_back(i);

	NAMESPACE::vector<int>	inputItC;

	inputItC.assign(lst.begin(), lst.end());
	printSize(inputItC);
	return 1;
}

int	assign(int size)
{
	if (size < 0)
		size = 19;
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "assign: (size = " << size << ")" << std::endl;
	#endif
	NAMESPACE::vector<TYPE>	c;

	c.assign(size, 42);
	printSize(c);

	inputItAssign();
	inputItAssign2(size);
	return 1;
}
}