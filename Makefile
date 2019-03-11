all:
	@gcc -Wall -Werror -Wextra -o main  init_and_print_tab.c main.c check.c play.c 
clean:
	@rm -f main
fclean: clean
	
re: fclean all
