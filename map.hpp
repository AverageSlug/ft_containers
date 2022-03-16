#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <iterator>
# include <stdexcept>
# include "utils.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > class map
	{
		public:
			/*MEMBER TYPES*/
			typedef Key														key_type;
			typedef T														mapped_type;
			typedef ft::pair<const key_type, mapped_type>					value_type;
			typedef Compare													key_compare;
			class	value_compare
			{
				friend class map<key_type, mapped_type, key_compare, Alloc>;
				protected:
					Compare			comp;
					value_compare	(Compare c) : comp(c) {}
				public:
					bool	operator()(const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
			};
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef ft::map_iterator<value_type>							iterator;
			typedef ft::map_iterator<const value_type>						const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef typename allocator_type::size_type						size_type;

			/*MEMBER FUNCTIONS*/
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			template<class InputIterator> map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map& x);
			~map();
			map&								operator=(const map& x);

			/*iterators*/
			iterator							begin();
			const_iterator						begin() const;
			iterator							end();
			const_iterator						end() const;
			reverse_iterator					rbegin();
			const_reverse_iterator				rbegin() const;
			reverse_iterator					rend();
			const_reverse_iterator				rend() const;

			/*capacity*/
			bool								empty() const;
			size_type							size() const;
			size_type							max_size() const;

			/*element access*/
			mapped_type&						operator[](const key_type& k);

			/*modifiers*/
			pair<iterator,bool>					insert(const value_type& val);
			iterator							insert(iterator position, const value_type& val);
			template<class InputIterator> void	insert(InputIterator first, InputIterator last);
			void								erase(iterator position);
			size_type							erase(const key_type& k);
			void								erase(iterator first, iterator last);
			void								swap(map& x);
			void								clear();

			/*observers*/
			key_compare							key_comp() const;
			value_compare						value_comp() const;

			/*operations*/
			iterator							find(const key_type& k);
			const_iterator						find(const key_type& k) const;
			size_type							count(const key_type& k) const;
			iterator							lower_bound(const key_type& k);
			const_iterator						lower_bound(const key_type& k) const;
			iterator							upper_bound(const key_type& k);
			const_iterator						upper_bound(const key_type& k) const;
			pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			pair<iterator,iterator>				equal_range(const key_type& k);

			/*allocator*/
			allocator_type						get_allocator() const;

	};
}

#endif