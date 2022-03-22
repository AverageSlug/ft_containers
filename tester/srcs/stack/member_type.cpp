/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_type.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:55:00 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/19 21:43:29 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_stack
{
int	member_type(void)
{
	NAMESPACE::stack<int>::container_type	a;
	NAMESPACE::stack<int>::value_type		b;
	NAMESPACE::stack<int>::size_type		c;

	return 1;
	(void)a;(void)b;(void)c;
}
}