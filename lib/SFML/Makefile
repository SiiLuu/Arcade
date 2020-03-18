##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

SRC_SFML	=	Sfml.cpp

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

SFML =	lib_arcade_sfml.so

CFLAGS +=	-fPIC -g -W -Wall -Wextra -Werror -Wpedantic
LDFLAGS		=	-shared -lsfml

all: $(SFML)

%.o : %.cpp
		@echo "Compiling $@..."
		g++ -fPIC -c $(SRC_SFML) $<

$(SFML): $(OBJ_SFML)
		@echo "Compiling..."
		ld -shared $(OBJ_SFML) -o ../$(SFML)

clean:
	rm -f *.o

fclean:	clean
	rm -f ../$(SFML)
	rm -f *.o

re: fclean all

debug:	CFLAGS += -g
debug:	fclean all
