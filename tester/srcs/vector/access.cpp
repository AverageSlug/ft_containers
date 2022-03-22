/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:19:57 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:40:13 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#define SIZE 3

namespace	n_vec
{

void	at(NAMESPACE::vector<int> v, int index)
{ std::cout << v.at(index) << std::endl; }

void	op_at_assign(NAMESPACE::vector<int> v, int index)
{ v[index] = 12; }

void	op_at(NAMESPACE::vector<int> v, int index)
{ std::cout << v[index] << std::endl; }

int access(void)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "access:" << std::endl;
#endif
	NAMESPACE::vector<int>	v;

	for (int i = 0; i < SIZE; ++i)
		v.push_back(i);

	access_test(v, at, 1);
	access_test(v, op_at_assign, 0);
	access_test(v, op_at, 0);
	std::cout << v.front() << std::endl;
	std::cout << v.back() << std::endl;

	v.pop_back();
	v.erase(v.begin());
	std::cout << v.front() << std::endl;
	std::cout << v.back() << std::endl;

	std::cout << *(v.data()) << std::endl;
	return 1;
}

}