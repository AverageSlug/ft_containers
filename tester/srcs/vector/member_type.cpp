/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_type.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:55:00 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:41:38 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_vec
{

int	member_type(void)
{
	NAMESPACE::vector<int>::value_type				a;
	NAMESPACE::vector<int>::allocator_type			b;
	NAMESPACE::vector<int>::size_type				c;
	NAMESPACE::vector<int>::difference_type			d;
	//NAMESPACE::vector<int>::reference				x;
	//NAMESPACE::vector<int>::const_reference		y;
	NAMESPACE::vector<int>::pointer					e;
	NAMESPACE::vector<int>::const_pointer			f;
	NAMESPACE::vector<int>::iterator				g;
	NAMESPACE::vector<int>::const_iterator			h;
	NAMESPACE::vector<int>::reverse_iterator		i;
	NAMESPACE::vector<int>::const_reverse_iterator	j;

	return 1;
	(void)a;(void)b;(void)c;(void)d;(void)e;(void)f;(void)g;(void)h;(void)i;(void)j;
}
}