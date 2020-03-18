##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC_SDL	=	Sdl.cpp

OBJ_SDL	=	$(SRC_SDL:.cpp=.o)

SDL =	lib_arcade_sdl.so

CFLAGS +=	-fPIC -g -W -Wall -Wextra -Werror -Wpedantic
LDFLAGS		=	-shared -lsdl

all: $(SDL)

%.o : %.cpp
		@echo "Compiling $@..."
		g++ -fPIC -c $(SRC_SDL) $<

$(SDL): $(OBJ_SDL)
		@echo "Compiling..."
		ld -shared $(OBJ_SDL) -o ../$(SDL)

clean:
	rm -f *.o

fclean:	clean
	rm -f ../$(SDL)
	rm -f *.o

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
