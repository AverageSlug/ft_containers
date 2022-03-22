/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:29:35 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 14:29:53 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/test.hpp"

int	vector(void)
{
	std::cout << std::setw(48) << std::string(PURPLE) + "vector" + EOC << std::endl;
	n_vec::member_type();
	n_vec::iterator();
	n_vec::r_iterator();
	n_vec::test_clear();
	n_vec::constructor();
	n_vec::capacity();
	n_vec::access();
	n_vec::all_operator();
	n_vec::erase(-1);
	n_vec::assign(-1);
	n_vec::insert(-1);
	n_vec::insert2(-1);
	n_vec::test_push_pop(-1);
	n_vec::resize(-1);
	return 0;
}
