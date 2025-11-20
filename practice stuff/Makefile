# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pauladrettas <pauladrettas@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 19:34:05 by pdrettas          #+#    #+#              #
#    Updated: 2025/11/20 19:19:56 by pauladretta      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01

SRC			=	./main.cpp ./Fixed.cpp
				
OBJ			=	$(SRC:.cpp=.o)
			
CXX			=	c++

CXXFLAGS	=	-std=c++17

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:	
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:		fclean all

leaks: re
	valgrind --leak-check=full ./$(NAME)
	$(MAKE) fclean

.PHONY: all clean fclean re leaks