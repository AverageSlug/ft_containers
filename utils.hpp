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
			pair() :
				first(),
				second()
			{}

			template<class U, class V>			pair(const pair<U,V>& pr) :
				first(pr.first),
				second(pr.second)
			{}

			pair(const first_type& a, const second_type& b) :
				first(a),
				second(b)
			{}

			pair&								operator=(const pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return (*this);
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class T1, class T2> bool			operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == lhs.second);
	}

	template<class T1, class T2> bool			operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T1, class T2> bool			operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template<class T1, class T2> bool			operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T1, class T2> bool			operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	}

	template<class T1, class T2> bool			operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T1, class T2> pair<T1, T2>	make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
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

	/**************************/
	/* RANDOM ACCESS ITERATOR */
	/**************************/

	template<typename T> class								vector_iterator : public std::iterator<std::random_access_iterator_tag, T>
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
				_it(NULL)
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
				operator--();
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

			operator vector_iterator<const T> () const
			{
				return (vector_iterator<const T>(_it));
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<typename T> typename ft::vector_iterator<T>::difference_type							operator==(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type							operator!=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type							operator<(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type							operator<=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type							operator>(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type							operator>=(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type							operator+(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() + rhs.base());
	}

	template<typename T> typename ft::vector_iterator<T>::difference_type							operator-(const ft::vector_iterator<T> lhs, const ft::vector_iterator<T> rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<typename T_lhs, typename T_rhs> typename ft::vector_iterator<T_lhs>::difference_type	operator==(const ft::vector_iterator<T_lhs> lhs, const ft::vector_iterator<T_rhs> rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<typename T_lhs, typename T_rhs> typename ft::vector_iterator<T_lhs>::difference_type	operator!=(const ft::vector_iterator<T_lhs> lhs, const ft::vector_iterator<T_rhs> rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<typename T_lhs, typename T_rhs> typename ft::vector_iterator<T_lhs>::difference_type	operator<(const ft::vector_iterator<T_lhs> lhs, const ft::vector_iterator<T_rhs> rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<typename T_lhs, typename T_rhs> typename ft::vector_iterator<T_lhs>::difference_type	operator<=(const ft::vector_iterator<T_lhs> lhs, const ft::vector_iterator<T_rhs> rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<typename T_lhs, typename T_rhs> typename ft::vector_iterator<T_lhs>::difference_type	operator>(const ft::vector_iterator<T_lhs> lhs, const ft::vector_iterator<T_rhs> rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<typename T_lhs, typename T_rhs> typename ft::vector_iterator<T_lhs>::difference_type	operator>=(const ft::vector_iterator<T_lhs> lhs, const ft::vector_iterator<T_rhs> rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<typename T_lhs, typename T_rhs> typename ft::vector_iterator<T_lhs>::difference_type	operator-(const ft::vector_iterator<T_lhs> lhs, const ft::vector_iterator<T_rhs> rhs)
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

		private:
			/*variables*/
			iterator_type	_it;

		public:
			/*MEMBER FUNCTIONS*/
			reverse_iterator() :
				_it()
			{}

			explicit												reverse_iterator(iterator_type it) :
				_it(it)
			{}

			template <class Iter>									reverse_iterator(const reverse_iterator<Iter>& rev_it) :
				_it(rev_it.base())
			{}

			iterator_type											base() const
			{
				return _it;
			}

			reference												operator*() const
			{
				return (*_it);
			}

			reverse_iterator										operator+(difference_type n) const
			{
				return (reverse_iterator(_it - n));
			}

			reverse_iterator&										operator++()
			{
				_it--;
				return (*this);
			}

			reverse_iterator										operator++(int)
			{
				reverse_iterator	t(*this);
				operator--();
				return (t);
			}
			reverse_iterator&										operator+=(difference_type n)
			{
				_it -= n;
				return (*this);
			}

			reverse_iterator										operator-(difference_type n) const
			{
				return (reverse_iterator(_it + n));
			}

			reverse_iterator&										operator--()
			{
				_it++;
				return (*this);
			}

			reverse_iterator 										operator--(int)
			{
				reverse_iterator	t(*this);
				operator++();
				return (t);
			}
			reverse_iterator&										operator-=(difference_type n)
			{
				_it += n;
				return (*this);
			}

			pointer													operator->() const
			{
				return (&(operator*()));
			}

			reference												operator[](difference_type n) const
			{
				return (*(operator+(n)));
			}
	};
	/*NON-MEMBER FUNCTION OVERLOADS*/
	template<class Iterator> bool													operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iterator> bool													operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<class Iterator> bool													operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iterator> bool													operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<class Iterator> bool													operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iterator> bool													operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<class Iterator> reverse_iterator<Iterator>								operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it.base() + n);
	}

	template<class Iterator> bool													operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<class Iterator_lhs, class Iterator_rhs> bool							operator==(const reverse_iterator<Iterator_lhs>& lhs, const reverse_iterator<Iterator_rhs>& rhs)
	{
		return (lhs.base() == rhs.base());
	}

	template<class Iterator_lhs, class Iterator_rhs> bool							operator!=(const reverse_iterator<Iterator_lhs>& lhs, const reverse_iterator<Iterator_rhs>& rhs)
	{
		return (lhs.base() != rhs.base());
	}

	template<class Iterator_lhs, class Iterator_rhs> bool							operator<(const reverse_iterator<Iterator_lhs>& lhs, const reverse_iterator<Iterator_rhs>& rhs)
	{
		return (lhs.base() < rhs.base());
	}

	template<class Iterator_lhs, class Iterator_rhs> bool							operator<=(const reverse_iterator<Iterator_lhs>& lhs, const reverse_iterator<Iterator_rhs>& rhs)
	{
		return (lhs.base() <= rhs.base());
	}

	template<class Iterator_lhs, class Iterator_rhs> bool							operator>(const reverse_iterator<Iterator_lhs>& lhs, const reverse_iterator<Iterator_rhs>& rhs)
	{
		return (lhs.base() > rhs.base());
	}

	template<class Iterator_lhs, class Iterator_rhs> bool							operator>=(const reverse_iterator<Iterator_lhs>& lhs, const reverse_iterator<Iterator_rhs>& rhs)
	{
		return (lhs.base() >= rhs.base());
	}

	template<class Iterator_lhs, class Iterator_rhs> bool							operator-(const reverse_iterator<Iterator_lhs>& lhs, const reverse_iterator<Iterator_rhs>& rhs)
	{
		return (lhs.base() - rhs.base());
	}

	/******************************************************/
	/*  _   _  ___  ___         _, _____ _   _ ____ ____  */
	/*  |\ /| |   | |  |       |     |   |   | |    |     */
	/*  | ' | |---| |--'       '-.   |   |   | |--  |--   */
	/*  |   | |   | |          ,_|   |   |___| |    |     */
	/******************************************************/

	/**************************/
	/* BIDIRECTIONAL ITERATOR */
	/**************************/

	template<typename T, typename BST> class			map_iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
		public:
			/*MEMBER TYPES*/
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename std::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef T*																				pointer;
			typedef T&																				reference;
			typedef BST*																			bst;

		private:
			/*variables*/
			bst	_bst;

		public:
			/*MEMBER FUNCTIONS*/
			map_iterator() :
				_bst(NULL)
			{}

			map_iterator(bst b)
			{
				_bst = b;
			}

			map_iterator(const map_iterator& map_it)
			{
				*this = map_it;
			}

			map_iterator&					operator=(const map_iterator& map_it)
			{
				_bst = map_it._bst;
				return (*this);
			}

			virtual ~map_iterator() {}

			pointer							base() const
			{
				return (_bst);
			}

			reference						operator*() const
			{
				return (_bst->val);
			}

			pointer							operator->()
			{
				return &(operator*());
			}

			map_iterator&					operator++()
			{
				if (!_bst)
					return (*this);
				if (_bst->right)
					_bst = smallest_leaf(_bst->right);
				else
				{
					bst	t = _bst->parent;
					while (t && _bst == t->right)
					{
						_bst = t;
						t = t->parent;
					}
					_bst = t;
				}
				return (*this);
			}

			map_iterator					operator++(int)
			{
				map_iterator	t(*this);
				operator++();
				return (t);
			}

			map_iterator&					operator--()
			{
				if (!_bst)
					return (*this);
				if (_bst->left)
					_bst = largest_leaf(_bst->left);
				else
				{
					bst	t = _bst->parent;
					while (t && _bst == t->left)
					{
						_bst = t;
						t = t->parent;
					}
					_bst = t;
				}
				return (*this);
			}

			map_iterator 					operator--(int)
			{
				map_iterator	t(*this);
				operator--();
				return (t);
			}

			operator map_iterator<const T, BST>() const
			{
				return map_iterator<const T, BST>(_bst);
			}

			template<typename X> bool						operator==(const ft::map_iterator<X, BST>& x)
			{
				return (_bst == x._bst);
			}

			template<typename X> bool						operator!=(const ft::map_iterator<X, BST>& x)
			{
				return (_bst != x._bst);
			}
	};

	/**********************/
	/* BINARY SEARCH TREE */
	/**********************/

	template<typename T> struct		bst
	{
		T			val;
		struct bst*	left;
		struct bst*	right;
		struct bst* parent;
		bst() :
			left(NULL),
			right(NULL),
			parent(NULL)
		{}

		bst(T v, struct bst* lft = NULL, struct bst* rit = NULL, struct bst* par = NULL) :
			val(v),
			left(lft),
			right(rit),
			parent(par)
		{}
	};

	template<typename T> bst<T>*	smallest_leaf(bst<T> *bst)
	{
		if (!bst || !bst->left)
			return bst;
		return smallest_leaf(bst->left);
	}

	template<typename T> bst<T>*	largest_leaf(bst<T> *bst)
	{
		if (!bst || !bst->right)
			return bst;
		return largest_leaf(bst->right);
	}
}

#endif
