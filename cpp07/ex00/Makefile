# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:39:58 by sohyamaz          #+#    #+#              #
#    Updated: 2026/08/15 12:11:51 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = whatever

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp

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
	./$(NAME)

rerun: re
	./$(NAME)

valrun: $(NAME)
	@valgrind --leak-check=full ./$(NAME)

revalrun: re
	@valgrind --leak-check=full ./$(NAME)

.PHONY: all clean fclean re run rerun valrun revalrun
