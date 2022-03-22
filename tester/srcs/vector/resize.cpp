/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 01:53:22 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/21 11:41:58 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_vec
{

int	resize(int size)
{
	if (size < 0)
		size = 9;
#ifndef NOPRINT
	std::cout << std::endl << std::setw(48) << "resize: (size = " << size << ")" << std::endl;
#endif
	NAMESPACE::vector<int>	v;	
	v.resize(size, 19);
	printSize(v);

	v.resize(size + 2);
	printSize(v);

	v.resize(0);
	printSize(v);

	v.resize(3);
	printSize(v);
	return 1;
}
}