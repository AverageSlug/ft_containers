NAME		=	ft_containers

CXX			=	clang++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -pedantic

SRCS		=	$(wildcard *.cpp)

OBJS		=	$(SRCS:.cpp=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean	:
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean all