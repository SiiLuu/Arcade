##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC 			= 	AGraph/AbstractGraph.cpp
SRC_NCURSES		=	NCURSES/nCurses.cpp
SRC_SDL			=	SDL/Sdl.cpp
SRC_SFML		=	SFML/Sfml.cpp

OBJ				=	$(SRC:.cpp=.o)
OBJ_NCURSES		=	$(SRC_NCURSES:.cpp=.o)
OBJ_SDL			=	$(SRC_SDL:.cpp=.o)
OBJ_SFML		=	$(SRC_SFML:.cpp=.o)

NCURSES 		=	lib_arcade_ncurses.so
SDL 			=	lib_arcade_sdl.so
SFML	 		=	lib_arcade_sfml.so

all: $(NCURSES)

%.o : %.cpp
		g++ -fPIC -llibstdc++ -c $(SRC) $(SRC_NCURSES) $(SRC_SDL) $(SRC_SFML)
		mv AbstractGraph.o AGraph/
		mv nCurses.o NCURSES/
		mv Sdl.o SDL/
		mv Sfml.o SFML/

$(NCURSES): $(OBJ_NCURSES)
		g++ -shared $(OBJ) $(OBJ_NCURSES) -o $(NCURSES)
		g++ -shared $(OBJ) $(OBJ_SDL) -o $(SDL)
		g++ -shared $(OBJ) $(OBJ_SFML) -o $(SFML)

clean:
	rm -f AGraph/*.o
	rm -f SFML/*.o
	rm -f SDL/*.o
	rm -f NCURSES/*.o

fclean:	clean
	rm -f $(NCURSES)
	rm -f $(SDL)
	rm -f $(SFML)

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
