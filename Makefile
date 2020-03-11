##
## EPITECH PROJECT, 2020
## cpp_rush2_2019
## File description:
## Makefile
##

NAME			=		arcade
TEST_NAME		=		tests/unit_tests

NO_COLOR		=		\e[0;0m
GREEN_COLOR		=		\e[0;32m
RED_COLOR		=		\e[0;31m
GREEN_B_COLOR	=		\e[1;32m
RED_B_COLOR		=		\e[1;31m

CC				=		g++
RM				=		rm -rf

MAIN_SRC		=		main.cpp

PROJ_SRC		=		errorGestion/error.cpp 					\
						errorGestion/errorGestion.cpp			\


TEST_SRC		=

MAIN_OBJ		=		$(MAIN_SRC:.cpp=.o)

PROJ_OBJ		=		$(PROJ_SRC:.cpp=.o)

TEST_OBJ		=		$(TEST_SRC:.cpp=.o)

TEST_COV		=		$(PROJ_SRC:.cpp=.gcda)	\
						$(PROJ_SRC:.cpp=.gcno)	\
						$(TEST_SRC:.cpp=.gcda)	\
						$(TEST_SRC:.cpp=.gcno)	\

INCLUDE_DIR		=		"include"

CFLAGS			+=		-I $(INCLUDE_DIR)
CFLAGS			+=		-W -Wextra

MAKEFLAGS		+=		--silent

%.o:			%.cpp
				$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< \
				&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
				|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

all:			$(NAME)

all_clean:		clean tests_clean

all_fclean:		fclean tests_fclean

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean

debug:			CFLAGS += -g3
debug:			sweet

tests_run:		CFLAGS += -fprofile-arcs -ftest-coverage
tests_run:		LDLIBS += -lgcov -lcriterion
tests_run:		fclean $(PROJ_OBJ) $(TEST_OBJ)

				$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }
				$(TEST_NAME) \
				&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; }

tests_clean:	clean
				$(RM) $(TEST_OBJ)
				$(RM) $(TEST_COV)

tests_fclean:	tests_clean
				$(RM) $(TEST_NAME)

tests_re:		tests_fclean tests_run

tests_sweet:	tests_run tests_clean

tests_sh:		sweet
				sh tests/tests.sh $(NAME) \
				&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; }

.PHONY:			all all_clean all_fclean clean fclean re sweet debug tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh
