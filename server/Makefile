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

NAME		=	myteams_server
TEST_NAME	=	unit_tests

CC		=	gcc

DLIB		=	../libs/myteams
LIBSO		= 	../libs/myteams
DSRC		=	./src
DINCLUDE	=	./include
DCOMMON		= 	../common
DTESTS		=	./tests
DSETUP		=	$(DSRC)/setup
DDATABASE	=	$(DSRC)/database

var := $(shell realpath $(PWD)/$(LIBSO)/libmyteams.so)

ifeq ($(.SHELLSTATUS), 0)
LIBSO=../libs/myteams
else
LIBSO=./libs/myteams
endif

LIB		=	myteams

TEST_SRC	=

SRC		=	$(DSETUP)/get_args.c	\
			$(DSETUP)/signal_handler.c	\
			$(DSETUP)/manage_fd_sets.c	\
			$(DSRC)/constant.c		\
			$(DSRC)/usage.c			\
			$(DSRC)/create_server.c	\
			$(DSRC)/get_or_set_server.c \
			$(DSRC)/close_server.c		\
			$(DSRC)/destroy_server.c	\
			$(DSRC)/server_my_teams.c	\
			$(DSRC)/check_select_error.c	\
			$(DSRC)/packet_is_empty.c		\
			$(DSRC)/check_fds.c				\
			$(DSRC)/connect_client.c		\
			$(DSRC)/get_high_socket.c		\
			$(DSRC)/close_session.c			\
			$(DSRC)/interprate_clients_req.c\
			$(DSRC)/free_str_array.c		\
			$(DSRC)/new/new_session.c	\
			$(DSRC)/new/new_user.c 		\
			$(DSRC)/new/new_team.c 		\
			$(DSRC)/new/new_channel.c 	\
			$(DSRC)/new/new_thread.c 	\
			$(DSRC)/new/new_reply.c 	\
			$(DSRC)/new/new_msg.c 		\
			$(DSRC)/clean_user.c		\
			$(DSRC)/requests/prepare_buffer.c	\
			$(DSRC)/requests/prepare_buffer_uuid.c	\
			$(DSRC)/requests/is_subscribed.c		\
			$(DSRC)/requests/reset_uuid_t.c			\
			$(DSRC)/requests/put_types.c	\
			$(DSRC)/requests/put_structs.c	\
			$(DSRC)/requests/login.c	\
			$(DSRC)/requests/logout.c	\
			$(DSRC)/requests/use.c	\
			$(DSRC)/requests/create_req.c		\
			$(DSRC)/requests/create_team.c		\
			$(DSRC)/requests/create_channel.c	\
			$(DSRC)/requests/create_thread.c	\
			$(DSRC)/requests/create_reply.c		\
			$(DSRC)/requests/list_req.c			\
			$(DSRC)/requests/list_team.c		\
			$(DSRC)/requests/list_channel.c		\
			$(DSRC)/requests/list_thread.c		\
			$(DSRC)/requests/list_reply.c		\
			$(DSRC)/requests/info_team.c		\
			$(DSRC)/requests/info_user.c		\
			$(DSRC)/requests/info_channel.c		\
			$(DSRC)/requests/info_thread.c		\
			$(DSRC)/requests/db/find_team.c		\
			$(DSRC)/requests/db/find_channel.c	\
			$(DSRC)/requests/db/find_thread.c	\
			$(DSRC)/requests/db/find_user.c		\
			$(DSRC)/requests/uuid_is_in_arr.c	\
			\
			$(DDATABASE)/database_constants.c	\
			\
			$(DDATABASE)/init/init_db.c				\
			\
			$(DDATABASE)/file_management/header.c	\
			\
			$(DDATABASE)/load/load_db.c				\
			\
			$(DDATABASE)/save/save_db.c				\
			$(DDATABASE)/save/save_teams.c			\
			$(DDATABASE)/save/save_users.c			\
			$(DDATABASE)/save/save_channels.c		\
			$(DDATABASE)/save/save_threads.c			\
			$(DDATABASE)/save/save_replies.c			\
			$(DDATABASE)/save/save_messages.c		\

SRCS	=	$(SRC) $(DSRC)/main.c

OBJ		=	$(SRCS:.c=.o)

INCLUDE	=	-I $(DINCLUDE) -I $(DLIB) -I $(DCOMMON)/include

CFLAGS	=	-W -Wall -Wextra -Werror -pedantic $(INCLUDE)

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