# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 15:29:39 by vstockma          #+#    #+#              #
#    Updated: 2023/11/06 15:29:40 by vstockma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = conversion

SRC = main.cpp ScalarConverter.cpp

OBJ = $(SRC:.cpp=.o)

CXX = c++

RM = rm -f

CPPFLAGS = -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re