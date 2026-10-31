# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:39:58 by sohyamaz          #+#    #+#              #
#    Updated: 2026/10/31 18:02:56 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RPN

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

TEST_ARGS := "8 9 * 9 - 9 - 9 - 4 - 1 +"

SRCS = main.cpp RPN.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

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
