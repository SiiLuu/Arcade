##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC 			= 	AGraph/AbstractGraph.cpp
SRC_CACA		=	LIBCACA/libCaca.cpp
SRC_SDL			=	SDL/Sdl.cpp
SRC_SFML		=	SFML/Sfml.cpp

OBJ				=	$(SRC:.cpp=.o)
OBJ_CACA		=	$(SRC_CACA:.cpp=.o)
OBJ_SDL			=	$(SRC_SDL:.cpp=.o)
OBJ_SFML		=	$(SRC_SFML:.cpp=.o)

CACA 			=	lib_arcade_libcaca.so
SDL 			=	lib_arcade_sdl.so
SFML	 		=	lib_arcade_sfml.so

all: $(CACA)

%.o : %.cpp
		g++ -fPIC -c $(SRC) $(SRC_CACA) $(SRC_SDL) $(SRC_SFML)
		mv AbstractGraph.o AGraph/
		mv libCaca.o LIBCACA/
		mv Sdl.o SDL/
		mv Sfml.o SFML/

$(CACA): $(OBJ_CACA)
		g++ -shared -rdynamic $(OBJ) $(OBJ_CACA) -o $(CACA)
		g++ -shared -rdynamic $(OBJ) $(OBJ_SDL) -o $(SDL)
		g++ -shared -rdynamic $(OBJ) $(OBJ_SFML) -o $(SFML)

clean:
	rm -f AGraph/*.o
	rm -f SFML/*.o
	rm -f SDL/*.o
	rm -f LIBCACA/*.o

fclean:	clean
	rm -f $(CACA)
	rm -f $(SDL)
	rm -f $(SFML)

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
