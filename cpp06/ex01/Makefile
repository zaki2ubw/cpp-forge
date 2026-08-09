# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:39:58 by sohyamaz          #+#    #+#              #
#    Updated: 2026/08/09 13:35:17 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Serialize

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp Serializer.cpp

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
