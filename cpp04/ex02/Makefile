# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:39:58 by sohyamaz          #+#    #+#              #
#    Updated: 2026/05/10 14:35:37 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Zoo

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp Logger.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp

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

WRONGSRCS = WrongMain.cpp Logger.cpp WrongAnimal.cpp AAnimal.cpp Dog.cpp WrongCat.cpp Brain.cpp

WRONGOBJS = $(WRONGSRCS:.cpp=.o)

wrong: $(WRONGNAME)

$(WRONGNAME): $(WRONGOBJS)
	$(CXX) $(CXXFLAGS) $(WRONGOBJS) -o $(WRONGNAME)

rewrong: fclean wrong

.PHONY: all clean fclean re wrong rewrong
