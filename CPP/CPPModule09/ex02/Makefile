# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/20 14:24:45 by fzuccaro          #+#    #+#              #
#    Updated: 2025/11/19 14:57:08 by fzuccaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp PmergeMeDeque.cpp
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