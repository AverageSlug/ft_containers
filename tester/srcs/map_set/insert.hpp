/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:24:53 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:19:54 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERT_HPP
# define INSERT_HPP
# include "ms_test.hpp"
# include <list>

namespace	n_map_set
{

template <class Cont>
static void	it_insert(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "it_insert:" << std::endl;
#endif
	std::list<typename Cont::value_type>	lst;

	for (int i = 0; i < size; ++i)
		ms_lst_push(lst, i);

	Cont	c;

	c.insert(lst.begin(), lst.begin());
	printSize(c);

	c.insert(lst.begin(), ++lst.begin());
	printSize(c);

	c.insert(lst.begin(), lst.end());
	printSize(c);
}

template <class Cont>
static void	hint_insert(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "hint_insert:" << std::endl;
#endif
	Cont	c;

	ms_insert(c, c.begin(), 0);
	printSize(c);

	for (int i = 0; i < size; ++i)
		ms_insert(c, ++c.begin(), i);
	printSize(c);

	ms_insert(c, --c.end(), 5);
	printSize(c);
}

template <class Cont>
static void	value_insert(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "value_insert:" << std::endl;
#endif
	Cont	c;

	ms_insert(c, 0);
	printSize(c);

	for (int i = 0; i < size; i += 2)
		ms_insert(c, i);
	printSize(c);

	for (int i = 1; i < size; i += 2)
		ms_insert(c, i);
	printSize(c);
}

template <class Cont>
int	insert(int size)
{
	if (size < 0)
		size = 12;
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "erase: (size = " << size << ")" << std::endl;
#endif
	it_insert<Cont>(size);
	hint_insert<Cont>(size);
	value_insert<Cont>(size);
	return 1;
}

}
 #endif