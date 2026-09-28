# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:39:58 by sohyamaz          #+#    #+#              #
#    Updated: 2026/09/29 02:18:00 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

TEST_ARGS = 42 7 19 88 3 61 25 14 73 5 90 31 11 67 2 54 38 21 80 9 46

SRCS = main.cpp PmergeMe.cpp debug_util.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(WRONGOBJS)

fclean: clean
	$(RM) $(NAME) $(WRONGNAME)

re: fclean all

run: $(NAME)
	./$(NAME) $(TEST_ARGS)

rerun: re
	./$(NAME) $(TEST_ARGS)

valrun: $(NAME)
	@valgrind --leak-check=full ./$(NAME) $(TEST_ARGS)

revalrun: re
	@valgrind --leak-check=full ./$(NAME) $(TEST_ARGS)

.PHONY: all clean fclean re run rerun valrun revalrun
