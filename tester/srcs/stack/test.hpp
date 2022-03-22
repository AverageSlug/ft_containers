/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaurids <nlaurids@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:32:46 by vneirinc          #+#    #+#             */
/*   Updated: 2022/03/18 17:06:55 by nlaurids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

# define GREEN "\e[92m"
# define YELLOW "\e[93m"
# define PURPLE "\e[95m"
# define EOC "\e[0m"

# include "../../../stack.hpp"
# include "../test_shared.hpp"
# include "../common_shared.hpp"
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <iterator>
# include <stack>

# define TYPE int

namespace	n_stack
{
int	test_push_pop(void);
int	constructor(void);
int	empty(void);
int	all_operator(void);
int	member_type(void);
}
#endif