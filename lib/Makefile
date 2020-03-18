##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC_SFML	=	AbstractGraph.cpp	\
				SFML/Sfml.cpp

SRC_SDL		=	AbstractGraph.cpp	\
				SDL/Sdl.cpp

SRC_NCURSES	=	AbstractGraph.cpp	\

OBJ_SDL		=	$(SRC_SDL:.cpp=.o)
OBJ_SFML 	=	$(SRC_SFML:.cpp=.o)
OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

SDL 	=	lib_arcade_sdl.so
SFML 	=	lib_arcade_sfml.so
NCURSES =	lib_arcade_ncurses.so

CFLAGS +=	-W -Wall -Wextra -Werror -Wpedantic

all: $(NCURSES)

%.o : %.cpp
		g++ -fPIC -c -Wall $(SRC_NCURSES)

$(NCURSES):	$(OBJ_NCURSES)
		@echo "Compiling..."
		ld -shared $(OBJ_NCURSES) -o $(NCURSES)

clean:
	rm -f *.o
	rm -f NCURSES/*.o
	rm -f SDL/*.o
	rm -f SFML/*.o

fclean:	clean
	rm -f $(SDL)
	rm -f $(SFML)
	rm -f $(NCURSES)

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
