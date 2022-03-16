/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijacquet <ijacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:04:19 by ijacquet          #+#    #+#             */
/*   Updated: 2021/11/12 15:04:19 by ijacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

/*
** Printers
*/
template <class T>
void	print_vector(ft::vector<T> &vct, std::string name="")
{
	typename ft::vector<T>::iterator it = vct.begin();
	size_t 					i = 0;

	std::cout << " ------- Vector container " << name << " -------" << std::endl;
	while (it != vct.end())
	{
		std::cout << "Element " << i << ": |" << *it << "|" << std::endl;
		++it;
		++i;
	}
	P("");
}

template <class T>
void	basic_val(ft::vector<T> &l1, std::vector<T> &l2)
{
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
	l1.push_back(6);
	l1.push_back(7);

	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(5);
	l2.push_back(6);
	l2.push_back(7);
}


static bool	check_it(ft::vector<int>::iterator myIt, ft::vector<int>::iterator myEnd, std::vector<int>::iterator realIt)
{
	while (myIt != myEnd)
	{
		if (*myIt != *realIt)
			return (false);
		++myIt;
		++realIt;
	}
	return (true);
}

static bool	check_it_rev(ft::vector<int>::reverse_iterator myIt, ft::vector<int>::reverse_iterator myEnd, std::vector<int>::reverse_iterator realIt)
{
	while (myIt != myEnd)
	{
		if (*myIt != *realIt)
			return (false);
		++myIt;
		++realIt;
	}
	return (true);
}

void	test_vct_construct()
{
	print_title("Constructor");
	ft::vector<int> my1;
	std::vector<int> real1;
	check("Constructor empty", (my1 == real1));

	ft::vector<int> my2((size_t)3, 19);
	std::vector<int> real2((size_t)3, 19);
	check("Constructor fill", (my2 == real2));

	basic_val(my2, real2);
	ft::vector<int> my3(my2.begin(), my2.end());
	std::vector<int> real3(real2.begin(), real2.end());
	check("Constructor range", (my3 == real3));	

	ft::vector<int> my4(my3);
	std::vector<int> real4(real3);
	check("Constructor copy", (my4 == real4));	

	ft::vector<int> my5 = my4;
	std::vector<int> real5 = real4;
	check("Constructor =", (my5 == real5));	

	my5 = my3;
	real5 = real3;
	check("Assignation =", (my5 == real5));
}

/*
** Iterators
*/
void	test_vct_iterators()
{
	print_title("Iterators");
	ft::vector<int> my1;
	std::vector<int> real1;

	ft::vector<int>::iterator myIt = my1.begin();
	std::vector<int>::iterator realIt = real1.begin();
	
	if ((my1 == real1))
		check("Iterator empty", check_it(myIt, my1.end(), realIt));
	else
		check("Container empty", false); //Print error

	basic_val(my1, real1);
	myIt = my1.begin();
	realIt = real1.begin();
	if ((my1 == real1))
		check("Iterator basic", check_it(myIt, my1.end(), realIt));
	else
		check("Container basic", false); //Print error

	myIt = my1.begin();
	realIt = real1.begin();
	check("Iterator +", *(myIt + 2), *(realIt + 2));
	check("Iterator -", *(my1.end() - 3), *(real1.end() - 3));	

	ft::vector<int> my2;
	std::vector<int> real2;
	ft::vector<int>::reverse_iterator myIt2 = my2.rbegin();
	std::vector<int>::reverse_iterator realIt2 = real2.rbegin();

	if ((my2 == real2))
		check("Iterator reverse empty", check_it_rev(myIt2, my2.rend(), realIt2));
	else
		check("Container empty", false); //Print error
	
	basic_val(my2, real2);
	myIt2 = my2.rbegin();
	realIt2 = real2.rbegin();
	if ((my2 == real2))
		check("Iterator reverse basic", check_it_rev(myIt2, my2.rend(), realIt2));
	else
		check("Container basic", false); //Print error

	myIt2 = my2.rbegin();
	realIt2 = real2.rbegin();
	check("reverse iterator +", *(myIt2 + 2), *(realIt2 + 2));
	check("reverse iterator -", *(my2.rend() - 3), *(real2.rend() - 3));


	ft::vector<int>::const_iterator mt = my2.begin();
	std::vector<int>::const_iterator rt = real2.begin();

	int ret = true;
	while (mt != my2.end())
	{
		if (*mt != *rt)
			ret = false;
		++mt;
		++rt;
	}
	check("Iterator const", ret);

	ft::vector<int>::const_reverse_iterator mi = my2.rbegin();
	ft::vector<int>::const_reverse_iterator mend = my2.rend();
	std::vector<int>::const_reverse_iterator ri = real2.rbegin();

	// *mi = 2;
	// *ri = 2;
	ret = true;
	while (mi != mend)
	{
		if (*mi != *ri)
			ret = false;
		++mi;
		++ri;
	}
	check("Iterator reverse const", ret);
	if (mt != myIt)
		check("Iterators compare", true);
}

/*
** Capacity
*/
void	test_vct_capacity()
{
	print_title("Capacity functions");
	ft::vector<int> my1;
	std::vector<int> real1;

	check("Empty", my1.empty(), real1.empty());
	check("Size", my1.size(), real1.size());

	basic_val(my1, real1);
	check("Empty", my1.empty(), real1.empty());
	check("Size", my1.size(), real1.size());

	my1.resize((size_t)2);
	real1.resize((size_t)2);
	check("Resize", (my1 == real1));
	check("Size", my1.size(), real1.size());
	my1.resize((size_t)9);
	real1.resize((size_t)9);
	check("Resize", (my1 == real1));
	check("Size", my1.size(), real1.size());

	my1.reserve((size_t)2);
	real1.reserve((size_t)2);
	check("Reserve", (my1 == real1));
	check("Size", my1.size(), real1.size());

	my1.reserve((size_t)20);
	real1.reserve((size_t)20);
	check("Reserve", (my1 == real1));
	check("Size", my1.size(), real1.size());
}

/*
** Element access
*/
void	test_vct_elem_access()
{
	print_title("Elements access");
	ft::vector<int> my1;
	std::vector<int> real1;
	basic_val(my1, real1);

	check("cont[0]", my1[0], real1[0]);
	check("cont[3]", my1[3], real1[3]);
	check("cont[4] = 19", (my1[4] = 19), (real1[4] = 19));
	try
	{
		check("at(1)", my1.at(1), real1.at(1));
		check("at(4)", my1.at(4), real1.at(4));
		check("at(5) = 19", (my1.at(5) = 19), (real1.at(5) = 19));
		check("at(10)", my1.at(10), real1.at(10));
		//std::cout << "at(10) : " << vct.at(10) << std::endl;
	}
	catch (std::exception &e)
	{
		check("at(10)", true);
	}
	check("front", my1.front(), real1.front());
	check("back", my1.back(), real1.back());
}

/*
** Modifiers
*/
void	test_vct_assign()
{
	print_title("Assign");
	ft::vector<int> my1;
	std::vector<int> real1;
	ft::vector<int> my2;
	std::vector<int> real2;

	my2.assign(my1.begin(), my1.end());
	real2.assign(real1.begin(), real1.end());
	check("Assign empty", (my2 == real2));

	my2.assign((size_t)0, 10);
	real2.assign((size_t)0, 10);
	check("Assign empty", (my2 == real2));

	basic_val(my1, real1);
	my2.assign(my1.begin(), my1.end());
	real2.assign(real1.begin(), real1.end());
	check("Assign first empty", (my2 == real2));

	my2.assign(my1.begin(), my1.end());
	real2.assign(real1.begin(), real1.end());
	check("Assign", (my2 == real2));

	my2.clear();
	real2.clear();
	my2.assign((size_t)3, 10);
	real2.assign((size_t)3, 10);
	check("Assign val", (my2 == real2));

	my2.assign((size_t)5, 19);
	real2.assign((size_t)5, 19);
	check("Assign val", (my2 == real2));
}

void	test_vct_ppback()
{
	print_title("Push_back / Pop_back");
	ft::vector<int> my1;
	std::vector<int> real1;

	my1.push_back(12);
	real1.push_back(12);
	check("push_back", (my1 == real1));
	my1.push_back(26);
	my1.push_back(63);
	my1.push_back(125);
	real1.push_back(26);
	real1.push_back(63);
	real1.push_back(125);
	check("push_back", (my1 == real1));

	my1.pop_back();
	real1.pop_back();
	check("pop_back", (my1 == real1));
	my1.pop_back();
	my1.pop_back();
	my1.pop_back();
	real1.pop_back();
	real1.pop_back();
	real1.pop_back();
	check("pop_back", (my1 == real1));
}

void	test_vct_insert()
{
	print_title("Insert");
	ft::vector<int> my1;
	std::vector<int> real1;

	my1.insert(my1.begin(), 19);
	real1.insert(real1.begin(), 19);
	check("Insert", (my1 == real1));	
	my1.insert(my1.end(), 42);
	real1.insert(real1.end(), 42);
	check("Insert", (my1 == real1));
	my1.insert(my1.end(), 3);
	real1.insert(real1.end(), 3);
	my1.insert(--(my1.end()), 4);
	real1.insert(--(real1.end()), 4);
	check("Insert", (my1 == real1));

	ft::vector<int> my2;
	std::vector<int> real2;

	my2.insert(my2.begin(), (size_t)3, 19);
	real2.insert(real2.begin(), (size_t)3, 19);
	check("Insert fill", (my2 == real2));	
	my2.insert(my2.end(), (size_t)3, 42);
	real2.insert(real2.end(), (size_t)3, 42);
	check("Insert fill", (my2 == real2));
	my2.insert(my2.end(), (size_t)3, 3);
	real2.insert(real2.end(), (size_t)3, 3);
	my2.insert(--(my2.end()), (size_t)3, 4);
	real2.insert(--(real2.end()), (size_t)3, 4);
	check("Insert fill", (my2 == real2));

	ft::vector<int> my3;
	std::vector<int> real3;

	my3.insert(my3.begin(), my1.begin(), my1.end());
	real3.insert(real3.begin(), real1.begin(), real1.end());
	check("Insert range", (my3 == real3));	

	my3.insert(my3.end(), my1.begin(), my1.end());
	real3.insert(real3.end(), real1.begin(), real1.end());
	check("Insert range", (my3 == real3));

	my3.insert(my3.end(), my1.begin(), my1.end());
	real3.insert(real3.end(), real1.begin(), real1.end());
	my3.insert(--(my3.end()), my1.begin(), my1.end());
	real3.insert(--(real3.end()), real1.begin(), real1.end());
	check("Insert range", (my3 == real3));
}

void	test_vct_erase()
{
	print_title("Erase");
	ft::vector<int> my1;
	std::vector<int> real1;

	my1.erase(my1.begin(), my1.end());
	real1.erase(real1.begin(), real1.end());
	check("erase range empty", (my1 == real1));

	basic_val(my1, real1);
	my1.erase(++(my1.begin()));
	real1.erase(++(real1.begin()));
	check("erase", (my1 == real1));

	basic_val(my1, real1);
	my1.erase(my1.begin(), my1.end());
	real1.erase(real1.begin(), real1.end());
	check("erase range", (my1 == real1));
}

void	test_vct_clear()
{
	print_title("Clear");
	ft::vector<int> my1;
	std::vector<int> real1;

	my1.clear();
	real1.clear();
	check("Clear empty", (my1 == real1));

	basic_val(my1, real1);
	my1.clear();
	real1.clear();
	check("Clear", (my1 == real1));

	my1.clear();
	real1.clear();
	check("Clear", (my1 == real1));
}

void	test_vct_swap()
{
	print_title("Swap / Extern Swap");
	ft::vector<int> my1;
	ft::vector<int> my2;
	std::vector<int> real1;
	std::vector<int> real2;

	my1.swap(my2);
	real1.swap(real2);
	check("Swap empty", (my1 == real1));
	check("Swap empty", (my2 == real2));

	basic_val(my1, real1);
	my1.swap(my2);
	real1.swap(real2);
	check("Swap", (my1 == real1));
	check("Swap", (my2 == real2));
	my1.swap(my2);
	real1.swap(real2);
	check("Swap", (my1 == real1));
	check("Swap", (my2 == real2));

	my2.push_back(19);
	my2.push_back(101);
	my2.push_back(42);
	real2.push_back(19);
	real2.push_back(101);
	real2.push_back(42);

	ft::vector<int>::iterator myIt = my1.begin();
	std::vector<int>::iterator realIt = real1.begin();
	check("Iterators before", (*myIt == *realIt));

	my1.swap(my2);
	real1.swap(real2);

	check("Swap", (my1 == real1));
	check("Swap", (my2 == real2));

	check("Iterators after", (*myIt == *realIt));
	check("Iterators after ++", (*(myIt++) == *(realIt++)));

	my1.swap(my2);
	real1.swap(real2);
	check("Swap", (my1 == real1));
	check("Swap", (my2 == real2));

	ft::swap(my1, my2);
	std::swap(real1, real2);
	check("Swap extern", (my1 == real1));
	check("Swap extern", (my2 == real2));
	ft::swap(my1, my2);
	std::swap(real1, real2);
	check("Swap extern", (my1 == real1));
	check("Swap extern", (my2 == real2));

	my2.clear();
	real2.clear();
	ft::swap(my1, my2);
	std::swap(real1, real2);
	check("Swap extern", (my1 == real1));
	check("Swap extern", (my2 == real2));
	ft::swap(my1, my2);
	std::swap(real1, real2);
	check("Swap extern", (my1 == real1));
	check("Swap extern", (my2 == real2));
}

void	test_vct_op()
{
	print_title("Relational operators");
	ft::vector<int>		my1;
	std::vector<int>	real1;
	ft::vector<int>		my2;
	std::vector<int>	real2;

	check("Operator ==", (my1 == my2), (real1 == real2));
	check("Operator !=", (my1 != my2), (real1 != real2));
	check("Operator <=", (my1 <= my2), (real1 <= real2));
	check("Operator <", (my1 < my2), (real1 < real2));
	check("Operator >=", (my1 >= my2), (real1 >= real2));
	check("Operator >", (my1 > my2), (real1 > real2));

	basic_val(my1, real1);
	basic_val(my2, real2);
	check("Operator ==", (my1 == my2), (real1 == real2));
	check("Operator !=", (my1 != my2), (real1 != real2));
	check("Operator <=", (my1 <= my2), (real1 <= real2));
	check("Operator <", (my1 < my2), (real1 < real2));
	check("Operator >=", (my1 >= my2), (real1 >= real2));
	check("Operator >", (my1 > my2), (real1 > real2));

	my1.push_back(19);
	real1.push_back(19);
	check("Operator ==", (my1 == my2), (real1 == real2));
	check("Operator !=", (my1 != my2), (real1 != real2));
	check("Operator <=", (my1 <= my2), (real1 <= real2));
	check("Operator <", (my1 < my2), (real1 < real2));
	check("Operator >=", (my1 >= my2), (real1 >= real2));
	check("Operator >", (my1 > my2), (real1 > real2));
}

void	test_vector()
{
	print_header("VECTOR");
	test_vct_construct();
	P("");
	test_vct_iterators();
	P("");
	test_vct_capacity();
	P("");
	test_vct_elem_access();
	P("");
	test_vct_assign();
	P("");
	test_vct_ppback();
	P("");
	test_vct_insert();
	P("");
	test_vct_erase();
	P("");
	test_vct_clear();
	P("");
	test_vct_swap();
	P("");
	test_vct_op();
	P("");
}
