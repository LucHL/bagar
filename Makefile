##
## EPITECH PROJECT, 2024
## -field
## File description:
## Makefile
##

all:
	make -C client
	make -C server

clean:
	make clean -C client
	make clean -C server

fclean: clean
	make fclean -C client
	make fclean -C server
	rm -f vgcore.*

re: fclean all

.PHONY: all clean fclean re
