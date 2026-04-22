# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 21:25:27 by fzuccaro          #+#    #+#              #
#    Updated: 2025/09/23 11:51:59 by fzuccaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ConversionOfScalarType
SRC = main.cpp ScalarConverter.cpp
CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC)
				$(CXX) $(CXX_FLAGS) $(SRC) -o $(NAME)

clean:
		rm -f

fclean: clean
		rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re