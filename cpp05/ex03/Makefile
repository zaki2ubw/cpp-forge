# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 13:39:58 by sohyamaz          #+#    #+#              #
#    Updated: 2026/07/11 21:03:44 by sohyamaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Intern

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp \
	   Intern.cpp

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
	@mkdir -p outfile
	@rm -rf outfile/*
	./$(NAME)
	@ls -l outfile

rerun: re
	@mkdir -p outfile
	@rm -rf outfile/*
	./$(NAME)
	@ls -l outfile

valrun: $(NAME)
	@mkdir -p outfile
	@rm -rf outfile/*
	@valgrind --leak-check=full ./$(NAME)
	@ls -l outfile

revalrun: re
	@mkdir -p outfile
	@rm -rf outfile/*
	@valgrind --leak-check=full ./$(NAME)
	@ls -l outfile

.PHONY: all clean fclean re run rerun valrun revalrun
