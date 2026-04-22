# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/28 18:48:56 by fzuccaro          #+#    #+#              #
#    Updated: 2025/10/03 18:44:59 by fzuccaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Array
SRC = main.cpp
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