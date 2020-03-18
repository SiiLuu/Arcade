##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

all:
	make -C ./NCURSES

clean:
	rm -f *.o
	rm -f NCURSES/*.o
	rm -f SDL/*.o
	rm -f SFML/*.o

fclean:	clean
	make fclean -C ./NCURSES

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
