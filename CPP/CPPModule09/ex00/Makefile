# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/11 18:48:40 by fzuccaro          #+#    #+#              #
#    Updated: 2025/10/17 21:28:03 by fzuccaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc
SRC = main.cpp BitcoinExchange.cpp
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
