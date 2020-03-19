##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC 	=	main.cpp 								\
			ArcadeCore.cpp							\
			config/gameConfig.cpp					\
			errorGestion/error.cpp					\
			errorGestion/errorGestion.cpp			\
			scene/sceneMainMenu/sceneMainMenu.cpp	\
			scene/sceneMainGame/sceneMainGame.cpp	\
			scene/scenePauseMenu/scenePauseMenu.cpp	\
			libLoader/LibLoader.cpp

OBJ 	=	$(SRC:.cpp=.o)

NAME 	=	arcade

CFLAGS +=	-W -Wall -Wextra -Werror -Wpedantic

all:	games graphicals core

core:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

graphicals:
	make -C ./lib

games:
	make -C ./games

clean:
	rm -f *.o
	rm -f scene/*.o
	rm -f errorGestion/*.o
	rm -f config/*.o
	rm -f scene/scenePauseMenu/*.o
	rm -f scene/sceneMainGame/*.o
	rm -f scene/sceneMainMenu/*.o
	rm -f libLoader/*.o
	make -C ./games clean
	make -C ./lib clean

fclean:	clean
	rm -f $(NAME)
	make -C ./games fclean
	make -C ./lib fclean

re: fclean all
	make -C ./games re
	make -C ./lib re

.PHONY: core games graphicals
