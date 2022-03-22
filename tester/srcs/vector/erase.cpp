/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 22:02:24 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 15:20:25 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_vec
{

typedef NAMESPACE::vector<int>::iterator	t_it;

static void	erase_one(int size)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(18) << "erase_one:" << std::endl;
	#endif
	NAMESPACE::vector<int>	c;

	for (int i = 0; i < size; ++i)
		c.push_back(i);
	printSize(c);

	for (t_it it = c.begin(); it != c.end(); ++it)
		c.erase(it);
	printSize(c);
}

static void	erase_it(int size)
{

	#ifndef NOPRINT
		std::cout << std::endl << std::setw(18) << "erase_it:" << std::endl;
	#endif
	NAMESPACE::vector<int>	c;

	for (int i = 0; i < size; ++i)
		c.push_back(i);
	printSize(c);

	if (size > 3)
	{
		c.erase(++c.begin(), --(c.end()));
		printSize(c);
	}

	if (size > 1)
	{
		c.erase(++(++c.begin()), c.end());
		printSize(c);
	}

	if (size > 0)
	{
		c.erase(++c.begin(), c.end());
		printSize(c);
	}
	c.erase((c.begin()), c.end());
	printSize(c);

}

int	erase(int size)
{
	if (size < 0)
		size = 12;
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "erase: (size = " << size << ")" << std::endl;
	#endif
	erase_one(size);
	erase_it(size);
	return 1;
}
}