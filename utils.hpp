#ifndef UTILS_HPP
# define UTILS_HPP

# include <cstddef>

namespace ft
{
	/******************************************************/
	/* _____ _   _ _   _  ___ _____ _____  ___  _   _  _, */
	/* |     |   | |\  | |      |     |   |   | |\  | |   */
	/* |---  |   | | \ | |      |     |   |   | | \ | '-. */
	/* |     |___| |  \| |___   |   __|__ |___| |  \| ,_| */
	/******************************************************/


	/***************************/
	/* ENABLE IF & IS_INTEGRAL */
	/***************************/

	template<bool Cond, class T = void> struct	enable_if;
	template<class T> struct enable_if<true, T>
	{
		typedef T type;
	};

	template<class T, T v> struct				integral_constant
	{
		static const bool				value = v;
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		operator						T() const
		{
			return v;
		}
	};

	template<typename> struct					is_integral_type : public integral_constant<bool, false> {};
	template<> struct							is_integral_type<bool> : public integral_constant<bool, true> {};
	template<> struct							is_integral_type<char> : public integral_constant<char, true> {};
	template<> struct							is_integral_type<char16_t> : public integral_constant<char16_t, true> {};
	template<> struct							is_integral_type<char32_t> : public integral_constant<char32_t, true> {};
	template<> struct							is_integral_type<wchar_t> : public integral_constant<wchar_t, true> {};
	template<> struct							is_integral_type<signed char> : public integral_constant<signed char, true> {};
	template<> struct							is_integral_type<short int> : public integral_constant<short int, true> {};
	template<> struct							is_integral_type<int> : public integral_constant<int, true> {};
	template<> struct							is_integral_type<long int> : public integral_constant<long int, true> {};
	template<> struct							is_integral_type<unsigned char> : public integral_constant<unsigned char, true> {};
	template<> struct							is_integral_type<unsigned short int> : public integral_constant<unsigned short int, true> {};
	template<> struct							is_integral_type<unsigned int> : public integral_constant<unsigned int, true> {};
	template<> struct							is_integral_type<unsigned long int> : public integral_constant<unsigned long int, true> {};

	template<typename T> struct					is_integral : public is_integral_type<T> {};

	/***********************************/
	/* EQUAL & LEXICOGRAPHICAL_COMPARE */
	/***********************************/

	template<class InputIterator1, class InputIterator2> bool							equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template<class InputIterator1, class InputIterator2, class BinaryPredicate> bool	equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	template<class InputIterator1, class InputIterator2> bool							lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template<class InputIterator1, class InputIterator2, class Compare> bool			lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	/********************/
	/* PAIR & MAKE_PAIR */
	/********************/

	template<class T1, class T2> struct			pair
	{
		public:
			/*MEMBER TYPES*/
			typedef T1							first_type;
			typedef T2							second_type;

			/*MEMBER VARIABLES*/
			first_type							first;
			second_type							second;

			/*MEMBER FUNCTIONS*/
			pair()
			{
				first = first_type();
				second = second_type();
			}

			template<class U, class V>			pair(const pair<U,V>& pr)
			{
				first = first_type(pr.first);
				second = second_type(pr.second);
			}

			pair(const first_type& a, const second_type& b)
			{
				first = first_type(a);
				second = second_type(b);
			}

			pair&								operator=(const pair& pr)
			{
				first = pr.first;
				second = pr.second;
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class T1, class T2> bool			operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == lhs.second);
	}

	template<class T1, class T2> bool			operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T1, class T2> bool			operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template<class T1, class T2> bool			operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T1, class T2> bool			operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T1, class T2> bool			operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T1, class T2> pair<T1,T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1,T2>(x, y));
	}

	/******************************************************/
	/* _____ _____ ____ ____   ___  _____  ___  ____   _, */
	/*   |     |   |    |   \ |   |   |   |   | |   \ |   */
	/*   |     |   |--  |---' |---|   |   |   | |---' '-. */
	/* __|__   |   |___ |   \ |   |   |   |___| |   \ ,_| */
	/******************************************************/


	/*******************/
	/* ITERATOR TRAITS */
	/*******************/

	template<class Iterator> struct							iterator_traits
	{
		public:
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template<class T> struct								iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t								difference_type;
			typedef T										value_type;
			typedef T*										pointer;
			typedef T&										reference;
			typedef std::random_access_iterator_tag			iterator_category;
	};

	template<class T> struct								iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t								difference_type;
			typedef T										value_type;
			typedef const T*								pointer;
			typedef const T&								reference;
			typedef std::random_access_iterator_tag			iterator_category;
	};

	/*******************/
	/* VECTOR ITERATOR */
	/*******************/

	template<typename T> class											vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
			/*MEMBER TYPES*/
			typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename std::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef T*																				pointer;
			typedef T&																				reference;

		private:
			/*variables*/
			pointer	_it;

		public:
			/*MEMBER FUNCTIONS*/
			vector_iterator() :
				_it(nullptr)
			{}

			vector_iterator(pointer it) :
				_it(it)
			{}

			vector_iterator(const vector_iterator& vec_it) :
				_it(vec_it._it)
			{}

			vector_iterator&			operator=(const vector_iterator& vec_it)
			{
				_it = vec_it._it;
				return (*this);
			}

			virtual ~vector_iterator() {}

			pointer						base() const
			{
				return (_it);
			}

			reference					operator*() const
			{
				return (*_it);
			}

			pointer						operator->()
			{
				return &(operator*());
			}

			vector_iterator				operator+(difference_type n) const
			{
				return (_it + n);
			}

			vector_iterator&			operator++()
			{
				_it++;
				return (*this);
			}

			vector_iterator				operator++(int)
			{
				vector_iterator	t(*this);
				operator++();
				return (t);
			}

			vector_iterator&			operator+=(difference_type n)
			{
				_it += n;
				return (*this);
			}

			vector_iterator				operator-(difference_type n) const
			{
				return (_it - n);
			}

			vector_iterator&			operator--()
			{
				_it--;
				return (*this);
			}

			vector_iterator 			operator--(int)
			{
				vector_iterator	t(*this);
				operator++();
				return (t);
			}

			vector_iterator&			operator-=(difference_type n)
			{
				_it - n;
				return (*this);
			}

			reference					operator[](difference_type n) const
			{
				return (*(operator+(n)));
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<typename T> typename ft::vector_iterator<T>::difference_type	operator==(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type	operator!=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type	operator<(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type	operator<=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type	operator>(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type	operator>=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type	operator+(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() + rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type	operator-(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}
	/********************/
	/* REVERSE ITERATOR */
	/********************/

	template<class Iterator> class 											reverse_iterator
	{
		public:
			/*MEMBER TYPES*/
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

			/*MEMBER FUNCTIONS*/
			reverse_iterator();
			explicit												reverse_iterator(iterator_type it);
			template <class Iter>									reverse_iterator(const reverse_iterator<Iter>& rev_it);
			iterator_type											base() const;
			reference												operator*() const;
			reverse_iterator										operator+(difference_type n) const;
			reverse_iterator&										operator++();
			reverse_iterator										operator++(int);
			reverse_iterator&										operator+=(difference_type n);
			reverse_iterator										operator-(difference_type n) const;
			reverse_iterator&										operator--();
			reverse_iterator 										operator--(int);
			reverse_iterator&										operator-=(difference_type n);
			pointer													operator->() const;
			reference												operator[](difference_type n) const;
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class Iterator> bool													operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template<class Iterator> bool													operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template<class Iterator> bool													operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template<class Iterator> bool													operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template<class Iterator> bool													operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template<class Iterator> bool													operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
	template<class Iterator> reverse_iterator<Iterator>								operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);
	template<class Iterator> typename reverse_iterator<Iterator>::difference_type	operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
}

#endif
