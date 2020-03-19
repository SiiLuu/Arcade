##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

all:
	make -C ./lib
	#make -C ./game
	#make -C ./core

core:
	make -C ./core

graphicals:
	make -C ./lib

game:
	make -C ./game

clean:
	make -C ./lib clean
	make -C ./core clean
	make -C ./game clean

fclean:	clean
	rm -f $(NAME)
	make -C ./lib fclean

re: fclean all
	make -C ./lib re
