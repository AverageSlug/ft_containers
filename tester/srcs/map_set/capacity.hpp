/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:44:22 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 16:06:28 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAPACITY_HPP
# define CAPACITY_HPP
# define SIZE 8
# include "ms_test.hpp"

namespace	n_map_set
{

template <class Cont>
void	capacity(void)
{
	std::cout << std::endl << std::setw(48) << "empty/size/max_size: " << std::endl;
	Cont	c;

	std::cout << c.size() << std::endl;
	std::cout << c.max_size() << std::endl;

	ms_insert(c, 19);

	std::cout << c.empty() << std::endl;
	std::cout << c.max_size() << std::endl;

	ms_erase(c);
	std::cout << c.size() << std::endl;

	for (int i = 0; i < SIZE; ++i)
		ms_insert(c, 1);

	std::cout << c.size() << std::endl;
	std::cout << c.empty() << std::endl;
}

}

#endif