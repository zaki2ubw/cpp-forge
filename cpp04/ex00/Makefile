# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:39:58 by sohyamaz          #+#    #+#              #
#    Updated: 2026/05/09 19:16:01 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zoo

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp Logger.cpp Animal.cpp Dog.cpp Cat.cpp

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

WRONGNAME = WrongZoo

WRONGSRCS = WrongMain.cpp Logger.cpp WrongAnimal.cpp Animal.cpp Dog.cpp WrongCat.cpp

WRONGOBJS = $(WRONGSRCS:.cpp=.o)

wrong: $(WRONGNAME)

$(WRONGNAME): $(WRONGOBJS)
	$(CXX) $(CXXFLAGS) $(WRONGOBJS) -o $(WRONGNAME)

reWrong: fclean wrong

.PHONY: all clean fclean re wrong
