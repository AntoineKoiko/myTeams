##
## EPITECH PROJECT, 2020
## my c project
## File description:
## Makefile of the project
##

#constante
ECHO		=	echo -e
DEFAULT		=	"\e[0m"
OK_C		=	"\e[32m"
ERROR_C		=	"\e[31m"
LIGHT_RED	=	"\e[91m"

#var

NAME		=	myteams_cli
TEST_NAME	=	unit_tests

CC		=	gcc

DLIB		=	../libs/myteams
LIBSO		= 	../libs/myteams
DSRC		=	./src
DSETUP		=	$(DSRC)/setup
DINCLUDE	=	./include
DCOMMON		=	../common
DTESTS		=	./tests

var := $(shell realpath $(PWD)/$(LIBSO)/libmyteams.so)

ifeq ($(.SHELLSTATUS), 0)
LIBSO=../libs/myteams
else
LIBSO=./libs/myteams
endif

LIB		=

TEST_SRC	=

SRC		=	$(DSETUP)/check_args.c		\
			$(DSETUP)/signal_handler.c	\
			$(DSETUP)/manage_fd_sets.c	\
			$(DSRC)/usage.c				\
			$(DSRC)/constant.c			\
			$(DSRC)/create_client.c		\
			$(DSRC)/destroy_client.c	\
			$(DSRC)/get_or_set_client.c	\
			$(DSRC)/client_my_teams.c	\
			$(DSRC)/check_select_error.c\
			$(DSRC)/check_fds.c			\
			$(DSRC)/interprate_server_response.c	\
			$(DSRC)/interprate_user_input.c			\
			$(DSRC)/packet_is_empty.c				\
			$(DSRC)/get_args.c						\
			$(DSRC)/rm_escape_char.c				\
			$(DSRC)/read_from_stdin.c				\
			$(DSRC)/serialize_cmd.c					\
			$(DSRC)/command_help.c					\
			$(DSRC)/server_response/unserializer/primary_type_getter.c		\
			$(DSRC)/server_response/process_error.c	\
			$(DSRC)/server_response/process_success.c	\
			$(DSRC)/server_response/success/process_create_event.c	\
			$(DSRC)/server_response/success/process_elem.c	\
			$(DSRC)/server_response/success/process_list.c	\
			$(DSRC)/server_response/success/process_simple_event.c	\
			$(DSRC)/server_response/success/process_other_event.c	\

SRCS	=	$(SRC) $(DSRC)/main.c

OBJ		=	$(SRCS:.c=.o)

CFLAGS	=	-W -Wall -Wextra -Werror -pedantic -I $(DINCLUDE) -I $(DLIB) -I $(DCOMMON)/include
LDFLAGS	=	-luuid -L $(DLIB) -lmyteams -Wl,-rpath=$(PWD)/$(LIBSO)

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
