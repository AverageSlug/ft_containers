/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijacquet <ijacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:04:48 by ijacquet          #+#    #+#             */
/*   Updated: 2021/11/12 15:04:48 by ijacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTER_HPP_
# define __TESTER_HPP_

# include <deque>
# include <stack>
# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <stack>
# include <queue>
# include <map>
# include <utility>

# include "../vector.hpp"
# include "../map.hpp"
# include "../stack.hpp"
# include "../utils.hpp"

# define RESET "\e[0m"
# define RED "\e[91m"
# define GREEN "\e[92m"
# define BLUE "\e[94m"
# define BOLD "\e[1m"
# define GOOD "GOOD"
# define FAIL "FAIL"


# define P(x) std::cout << x << std::endl;
# define PP(x) std::cout << "|" << x << "|" << std::endl;
# define PL(name, x) std::cout << name << x << std::endl;

void	test_list();
void	test_stack();
void	test_vector();
void	test_queue();
void	test_map();

bool compare_supEq(int a, int b);
bool compare_infEq(int a, int b);
bool compare_Eq(int a, int b);
bool compare_inf(int a, int b);
bool compare_sup(int a, int b);
bool test_pair(int &val);
bool pred(int &val);

void 	print_header(std::string str);
void 	print_title(std::string str);

template <class T>
void	print_comp(std::string title, T a, T b)
{
	if (!title.empty())
		std::cout << title << std::endl;
	std::cout << "Miens : " << a << std::endl;
	std::cout << "Vraie : " << b << std::endl;
	std::cout << std::endl;
}

template <typename T>
inline void check(std::string name, T a, T b)
{
	std::string margin(24 - name.length(), ' ');
	if (a ==  b)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << BOLD << RED << FAIL << RESET << std::endl;
};

inline void check(std::string name, bool good)
{
	std::string margin(24 - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << BOLD << RED << FAIL << RESET << std::endl;
};

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return (false);
		}
	}
	return (true);
};

template <typename T>
bool operator==(ft::stack<T> &a, std::stack<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	if (!a.empty())
	{
		if (a.top() != b.top())
			return (false);
	}
	return (true);
};

template <typename T, typename S>
bool operator==(ft::map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

// template <class T, class S>
// bool operator==(ft::pair<T, S> &a, std::pair<T, S> &b)
// {
// 	if (a.first != b.first)
// 		return (false);
// 	if (a.second != b.second)
// 		return (false);
// 	return (true);
// };

#endif