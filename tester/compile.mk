# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlaurids <nlaurids@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 15:56:41 by vneirinc          #+#    #+#              #
#    Updated: 2022/03/18 17:06:19 by nlaurids         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAP_SET_SRC	=	../map.cpp \
				../set.cpp \
				map_iterator.cpp \
				set_iterator.cpp \
				ms_test.cpp

				
STCK_SRC	=	../stack.cpp \
				member_type.cpp \
				push_pop.cpp \
				empty.cpp \
				operator.cpp \
				constructor.cpp

VECT_SRC	=	../vector.cpp \
				member_type.cpp \
				constructor.cpp \
				assign.cpp \
				erase.cpp \
				insert.cpp \
				insert2.cpp \
				test_temp.cpp \
				access.cpp \
				capacity.cpp \
				resize.cpp \
				iterator.cpp \
				r_iterator.cpp \
				operator.cpp

VECT_P		=	$(addprefix vector/, $(VECT_SRC))
STCK_P		=	$(addprefix stack/, $(STCK_SRC))
MAP_SET_P	=	$(addprefix map_set/, $(MAP_SET_SRC))

S_SRCS		+=	$(addprefix srcs/, $(VECT_P) $(MAP_SET_P))
S_SRCS		+=	$(MAIN)

SRCS		+=	$(addprefix srcs/, $(VECT_P) $(STCK_P) $(MAP_SET_P))
SRCS		+=	$(MAIN)

CFLAG	=	-std=c++98 -Wall -Wextra -Werror -fsanitize=address
RM		=	rm -f
CC		=	clang++
OBJ		=	$(SRCS:.cpp=.o)
S_OBJ	=	$(S_SRCS:.cpp=.o)

%.o: %.cpp
		$(CC) $(CFLAG) $(MORE) -c $< -o $@

all:	$(OBJ)
		$(CC) $(CFLAG) $(MORE) -o $(NAME) $(OBJ)
		$(RM) $(OBJ)

speed:	$(S_OBJ)
		$(CC) $(CFLAG) $(MORE) -o $(NAME) $(S_OBJ)
		$(RM) $(S_OBJ)

clean:
		$(RM) $(OBJ)

.PHONY:	all clean speed