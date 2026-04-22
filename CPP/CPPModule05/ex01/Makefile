# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fzuccaro <fzuccaro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/10 14:11:26 by fzuccaro          #+#    #+#              #
#    Updated: 2025/09/16 12:29:16 by fzuccaro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Form
SRC = main.cpp Bureaucrat.cpp Form.cpp
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