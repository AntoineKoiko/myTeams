##
## EPITECH PROJECT, 2020
## my c project
## File description:
## Makefile of the project
##

#constante
ECHO		=	echo
DEFAULT		=	"\e[0m"
OK_C		=	"\e[32m"
ERROR_C		=	"\e[31m"
LIGHT_RED	=	"\e[91m"

#var

NAME		=	myteams_server
TEST_NAME	=	unit_tests

CC		=	gcc

DLIB		=	../libs/myteams
DSRC		=	./src
DINCLUDE	=	./include
DTESTS		=	./tests

LIB		=	myteams

TEST_SRC	=

DSETUP	=	$(DSRC)/setup
SETUP_SRC	=	$(DSETUP)/get_args.c	\

SRC		=	$(SETUP_SRC)

SRCS	=	$(SRC) $(DSRC)/main.c
OBJ		=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -pedantic -I $(DINCLUDE) -I $(DLIB) 
LDFLAGS	=	 -L $(DLIB) -lmyteams -Wl,-rpath=$(PWD)/$(DLIB) -lmyteams

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) && \
	$(ECHO) $(OK_C)"\n---> [$(NAME)] Compiled 👌\n"$(DEFAULT) || \
	$(ECHO) $(ERROR_C)"\n---> Compilation failed\n"$(DEFAULT)
	cp $(NAME) ../

clean:
	#@make clean -C $(DTESTS)
	@rm -rf $(OBJ) vgcor* *~
	@rm -rf *.gcno
	@rm -rf *.gcda
	@$(ECHO) $(LIGHT_RED)"\n---> tmp files deleted\n"$(DEFAULT)

fclean:	clean
	@rm -f $(NAME) $(TEST_NAME)
	@$(ECHO) $(LIGHT_RED)"\n---> bin & unit_tests deleted\n"$(DEFAULT)

re: fclean all

debug: CFLAGS += -g3 -ggdb
debug: re

# tests_run:
# 	$(CC) $(TEST_SRC) $(SRC) -o $(TEST_NAME) -lcriterion --coverage -I $(DINCLUDE) $(LDFLAGS)
# 	./$(TEST_NAME)

.PHONY:	all $(NAME) clean fclean re tests_run debug
