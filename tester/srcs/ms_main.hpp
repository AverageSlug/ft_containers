/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vneirinc <vneirinc@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 22:13:31 by vneirinc          #+#    #+#             */
/*   Updated: 2021/12/20 23:37:07 by vneirinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_MAIN_HPP
# define MS_MAIN_HPP
# include "map_set/map_set.hpp"

namespace n_set
{
int	iterator(void);
int	r_iterator(void);
}

template<class Cont>
int	map_set(void)
{
	n_map_set::member_type<Cont>();
	n_map_set::capacity<Cont>();
	n_map_set::all_operator<Cont>();
	n_map_set::test_clear<Cont>();
	n_map_set::insert<Cont>(-1);
	n_map_set::erase<Cont>(-1);
	n_map_set::find_count<Cont>(-1);
	n_map_set::range_bound<Cont>(-1);
	return 1;
}
#endif