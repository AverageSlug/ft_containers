/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 00:05:37 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 08:34:37 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

namespace	n_stack
{
int	empty(void)
{
	#ifndef NOPRINT
		std::cout << std::endl << std::setw(48) << "empty:" << std::endl;
	#endif
	NAMESPACE::stack<int>	s;

	std::cout << s.empty() << std::endl;	
	s.push(101);
	std::cout << s.empty() << std::endl;	
	s.pop();
	std::cout << s.empty() << std::endl;	
	return 1;
}
}