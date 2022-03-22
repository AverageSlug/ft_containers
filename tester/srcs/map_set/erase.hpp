/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 09:08:20 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 16:06:34 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERASE_HPP
# define ERASE_HPP
# include "ms_test.hpp"
# include <list>

namespace n_map_set
{

template <class Cont>
static void	it_erase(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "it_erase:" << std::endl;
#endif
	Cont	c;

	for (int i = 0; i < size; ++i)
		ms_insert(c, i);
	printSize(c);

	c.erase(c.begin(), ++(++c.begin()));
	printSize(c);

	c.erase(++c.begin(), ++c.begin());
	printSize(c);

	c.erase(--c.end(), c.end());
	printSize(c);

	c.erase(c.begin(), c.end());
	printSize(c);
}

template <class Cont>
static void	one_it_erase(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "one_it_erase:" << std::endl;
#endif
	Cont	c;

	for (int i = 0; i < size; ++i)
		ms_insert(c, i);
	printSize(c);

	c.erase(c.begin());
	printSize(c);

	c.erase(++c.begin());
	printSize(c);

	c.erase(--c.end());
	printSize(c);

	for (unsigned long i = 0; i < c.size(); ++i)
		c.erase(c.begin());
	printSize(c);
}

template <class Cont>
static void	value_erase(int size)
{
#ifndef NOPRINT
	std::cout << std::endl << std::setw(18) << "value_erase:" << std::endl;
#endif
	Cont	c;

	for (int i = 0; i < size; ++i)
		ms_insert(c, i);
	printSize(c);

	c.erase(size - 1);
	printSize(c);

	c.erase(size / 2);
	printSize(c);

	c.erase(1);
	printSize(c);

	for (unsigned long i = 0; i < c.size(); ++i)
		c.erase(i);
	printSize(c);
}

template <class Cont>
int	erase(int size)
{
	if (size < 0)
		size = 12;
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "erase: (size = " << size << ")" << std::endl;
#endif
	one_it_erase<Cont>(size);
	it_erase<Cont>(size);
	value_erase<Cont>(size);
	return 1;
}

}
#endif