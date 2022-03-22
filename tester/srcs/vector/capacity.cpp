/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 01:35:34 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 14:47:58 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#define SIZE 10

namespace	n_vec
{
int	capacity(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "capacity/max_size/empty/reserve: " << std::endl;
	#endif
	NAMESPACE::vector<TYPE>	v;

	std::cout << v.max_size() << std::endl;

	v.reserve(2);

	std::cout << v.capacity() << std::endl;
	std::cout << v.empty() << std::endl;
	std::cout << v.max_size() << std::endl;

	for (int i = 0; i < SIZE; ++i)
		v.push_back(TYPE());

	std::cout << v.capacity() << std::endl;
	std::cout << v.empty() << std::endl;

	try
	{
		//v.reserve(4611686018427387903);
		//v.reserve(-1);
		std::cout << v.capacity() << std::endl;
	}
	catch (const std::exception& e)
	{ std::cout << e.what() << std::endl; }

	v.reserve(0);
	std::cout << v.capacity() << std::endl;
	std::cout << v.empty() << std::endl;
	return 1;
}

}