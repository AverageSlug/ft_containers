/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:44:22 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:10:21 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAR_HPP
# define CLEAR_HPP
# include "ms_test.hpp"
# define SIZE 8

namespace	n_map_set
{

template <class Cont>
int	test_clear(void)
{
	std::cout << std::endl << std::setw(48) << "clear:" << std::endl;
	clear<Cont>(ms_insert, ms_erase);
	return 1;
}

}

#endif