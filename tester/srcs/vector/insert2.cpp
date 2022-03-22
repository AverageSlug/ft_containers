/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 12:00:30 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:41:24 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <list>

namespace	n_vec
{

static void	one_insert(int size)
{
	NAMESPACE::vector<foo<int> >	v;	

	std::cout << std::endl << std::setw(18) << "one_insert:" << std::endl;
	for (int i = 0; i < size; ++i)
		v.insert(v.begin(), foo<int>());
	printSize(v);
}

static void	count_insert(int size)
{
	NAMESPACE::vector<foo<int> >	v;	

	std::cout << std::endl << std::setw(18) << "count_insert:" << std::endl;
	v.insert(v.end(), 1, foo<int>());
	printSize(v);
	v.insert(--v.end(), size, foo<int>());
	printSize(v);
}

static void	it_insert(int size)
{
	std::list<foo<int> >			lst;
	NAMESPACE::vector<foo<int> >	v;	

	std::cout << std::endl << std::setw(18) << "it_insert:" << std::endl;
	for (int i = 0; i < size; ++i)
		lst.push_back(foo<int>());
	v.insert(v.begin(), lst.begin(), lst.end());
	printSize(v);
}

int	insert2(int size)
{
	if (size < 0)
		size = 12;	
	std::cout << std::endl << std::setw(48) << "insert2: (size = " << size << " )" << std::endl;
	one_insert(size);
	count_insert(size);
	it_insert(size);
	return 1;
}
}