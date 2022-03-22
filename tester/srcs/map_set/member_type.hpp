/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   member_type.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:55:00 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:15:16 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMBER_TYPE_HPP
# define MEMBER_TYPE_HPP
#include "../test_shared.hpp"

namespace	n_map_set
{

template <class Cont>
int	member_type(void)
{
	NAMESPACE::map<int, int>::key_type					a;
	//NAMESPACE::map<int, int>::mapped_type				x;
	NAMESPACE::map<int, int>::value_type				b;
	NAMESPACE::map<int, int>::size_type					c;
	NAMESPACE::map<int, int>::difference_type			d;
	NAMESPACE::map<int, int>::key_compare				e;
	//NAMESPACE::map<int, int>::value_compare			x;
	NAMESPACE::map<int, int>::allocator_type			f;
	//NAMESPACE::map<int, int>::reference				x;
	//NAMESPACE::map<int, int>::const_reference			x;
	NAMESPACE::map<int, int>::pointer					g;
	NAMESPACE::map<int, int>::const_pointer				h;
	NAMESPACE::map<int, int>::iterator					i;
	NAMESPACE::map<int, int>::const_iterator			j;
	NAMESPACE::map<int, int>::reverse_iterator			k;
	NAMESPACE::map<int, int>::const_reverse_iterator	l;

	return 1;
	(void)a;(void)b;(void)c;(void)d;(void)e;(void)f;(void)g;(void)h;(void)i;(void)j;(void)k;(void)l;
}

}
#endif