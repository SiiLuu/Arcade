##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC 			= 	AGame/AGame.cpp								\
					HandleMap.cpp								\
					entity/Entity.cpp							\
					entity/component/Hp/Hp.cpp					\
					entity/component/AComponent.cpp				\
					entity/component/Position/Position.cpp		\
					entity/component/Speed/Speed.cpp

SRC_NIBBLER		=	AGame/nibbler/nibbler.cpp

SRC_PACMAN		=	AGame/pacman/pacman.cpp

OBJ				=	$(SRC:.cpp=.o)
OBJ_NIBBLER		=	$(SRC_NIBBLER:.cpp=.o)
OBJ_PACMAN		=	$(SRC_PACMAN:.cpp=.o)

NIBBLER 		=	lib_arcade_nibbler.so
PACMAN 			=	lib_arcade_pacman.so

all: $(NIBBLER)

%.o : %.cpp
		g++ -fPIC -c $(SRC) $(SRC_NIBBLER) $(SRC_PACMAN)
		mv AGame.o AGame
		mv Entity.o	entity
		mv Hp.o entity/component/Hp
		mv AComponent.o	 entity/component
		mv Position.o entity/component/Position
		mv Speed.o entity/component/Speed
		mv nibbler.o AGame/nibbler
		mv pacman.o AGame/pacman

$(NIBBLER): $(OBJ_NIBBLER)
		ld -shared $(OBJ) $(OBJ_NIBBLER) -o $(NIBBLER)
		ld -shared $(OBJ) $(OBJ_PACMAN) -o $(PACMAN)

clean:
	rm -f *.o
	rm -f AGame/*.o
	rm -f AGame/nibbler/*.o
	rm -f AGame/pacman/*.o
	rm -f entity/*.o
	rm -f entity/component/*.o
	rm -f entity/component/Hp/*.o
	rm -f entity/component/Position/*.o
	rm -f entity/component/Speed/*.o

fclean:	clean
	rm -f $(NIBBLER)
	rm -f $(PACMAN)

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
