# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaumon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 23:44:34 by tbeaumon          #+#    #+#              #
#    Updated: 2019/02/18 16:21:44 by bod              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@gcc -Wall -Werror -Wextra -o main  init_and_print_tab.c main.c check.c play.c
clean:
	@rm -f main
fclean: clean
	
re: fclean all
