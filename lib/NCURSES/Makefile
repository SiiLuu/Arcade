##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC_NCURSES	=	nCurses.cpp

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

NCURSES =	lib_arcade_ncurses.so

CFLAGS +=	-fPIC -g -W -Wall -Wextra -Werror -Wpedantic
LDFLAGS		=	-shared -lncurses

all: $(NCURSES)

%.o : %.cpp
		@echo "Compiling $@..."
		g++ -fPIC -c $(SRC_NCURSES) $<

$(NCURSES): $(OBJ_NCURSES)
		@echo "Compiling..."
		ld -shared $(OBJ_NCURSES) -o ../$(NCURSES)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NCURSES)

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
