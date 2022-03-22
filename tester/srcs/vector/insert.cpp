/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 11:58:26 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 12:39:49 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include <list>

namespace	n_vec
{

static void	one_insert(int size)
{
	NAMESPACE::vector<foo<int> >	v;	

#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "one_insert:" << std::endl;
#endif
	for (int i = 0; i < size; ++i)
		v.insert(v.begin(), foo<int>(12));
	printSize(v);
}

static void	count_insert(int size)
{
	NAMESPACE::vector<int>	v;	

#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "count_insert:" << std::endl;
#endif
	v.insert(v.end(), 1, 9);
	printSize(v);
	v.insert(--v.end(), size, 12);
	printSize(v);
}

static void	it_insert(int size)
{
	std::list<int>			lst;
	NAMESPACE::vector<int>	v;	

#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "it_insert:" << std::endl;
#endif
	for (int i = 0; i < size; ++i)
		lst.push_back(i);
	v.insert(v.begin(), lst.begin(), lst.end());
	printSize(v);
}

int	insert(int size)
{
	if (size < 0)
		size = 12;	
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "insert: (size = " << size << ")" << std::endl;
#endif
	one_insert(size);
	it_insert(size);
	count_insert(size);
	return 1;
}
}