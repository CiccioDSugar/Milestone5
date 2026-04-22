# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/20 21:25:27 by fzuccaro          #+#    #+#              #
#    Updated: 2025/09/25 18:02:03 by fzuccaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = TypeIdentifier
SRC = main.cpp Base.cpp
CXX = c++
CXX_FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
				$(CXX) $(CXX_FLAGS) $(SRC) -o $(NAME)

clean:
		rm -f

fclean: clean
		rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re