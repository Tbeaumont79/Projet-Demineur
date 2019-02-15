# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaumon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/23 23:44:34 by tbeaumon          #+#    #+#              #
#    Updated: 2019/02/15 18:46:10 by bod              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	@gcc -Wall -Werror -Wextra -o main  affichage.c main.c
clean:
	@rm -f main
fclean: clean
	
re: fclean all
