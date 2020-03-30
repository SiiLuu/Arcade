##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC 			= 	AGame/AbstractGame.cpp						\

SRC_NIBBLER		=	nibbler/nibbler.cpp

SRC_PACMAN		=	pacman/pacman.cpp

OBJ				=	$(SRC:.cpp=.o)
OBJ_NIBBLER		=	$(SRC_NIBBLER:.cpp=.o)
OBJ_PACMAN		=	$(SRC_PACMAN:.cpp=.o)

NIBBLER 		=	lib_arcade_nibbler.so
PACMAN 			=	lib_arcade_pacman.so

all: $(NIBBLER)

%.o : %.cpp
		g++ -fPIC -c $(SRC) $(SRC_NIBBLER) $(SRC_PACMAN)
		mv AbstractGame.o AGame
		mv nibbler.o nibbler
		mv pacman.o pacman

$(NIBBLER): $(OBJ_NIBBLER)
		g++ -shared -rdynamic $(OBJ) $(OBJ_NIBBLER) -o $(NIBBLER)
		g++ -shared -rdynamic $(OBJ) $(OBJ_PACMAN) -o $(PACMAN)

clean:
	rm -f *.o
	rm -f AGame/*.o
	rm -f nibbler/*.o
	rm -f pacman/*.o

fclean:	clean
	rm -f $(NIBBLER)
	rm -f $(PACMAN)

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
