/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:23:20 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:41:02 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <list>
#define SIZE 12
namespace	n_vec
{


static void	inputItConstructor(void)
{
	std::list<int>	lst;

	for (int i = 0; i < SIZE; ++i)
		lst.push_back(i);

	NAMESPACE::vector<int>	inputItC(lst.begin(), lst.end());
	printSize(inputItC);
}

static void	copyConstructor(void)
{
	NAMESPACE::vector<int>	c;

	for (int i = 0; i < SIZE; ++i)
		c.push_back(i);

	NAMESPACE::vector<int>	copyC(c);
	printSize(copyC);
}

int	constructor(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "constructor: " << std::endl;
	#endif
	NAMESPACE::vector<TYPE>	defaultC = NAMESPACE::vector<TYPE>();
	printSize(defaultC);

	NAMESPACE::vector<TYPE>	allocC((std::allocator<int>()));
	printSize(allocC);

	NAMESPACE::vector<TYPE>	sizeC(SIZE, 19);
	printSize(sizeC);

	inputItConstructor();
	copyConstructor();
	return 1;
}

}