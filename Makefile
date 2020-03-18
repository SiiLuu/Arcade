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
			lib/NCURSES/nCurses.cpp					\
			lib/SFML/Sfml.cpp						\
			lib/SDL/Sdl.cpp						\
			scene/sceneMainMenu/sceneMainMenu.cpp	\
			scene/sceneMainGame/sceneMainGame.cpp	\
			scene/scenePauseMenu/scenePauseMenu.cpp

OBJ 	=	$(SRC:.cpp=.o)

NAME 	=	arcade

CFLAGS +=	-W -Wall -Wextra -Werror -Wpedantic

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f *.o
	rm -f scene/*.o
	rm -f lib/*.o
	rm -f lib/NCURSES/*.o
	rm -f lib/SDL/*.o
	rm -f lib/SFML/*.o
	rm -f errorGestion/*.o
	rm -f config/*.o
	rm -f games/component/Hp/*.o
	rm -f games/component/Position/*.o
	rm -f games/component/Speed/*.o
	rm -f scene/scenePauseMenu/*.o
	rm -f scene/sceneMainGame/*.o
	rm -f scene/sceneMainMenu/*.o

fclean:	clean
	rm -f $(NAME)

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
