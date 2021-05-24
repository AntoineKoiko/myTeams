##
## EPITECH PROJECT, 2020
## my c project
## File description:
## Makefile of the project
##

# constantes
ECHO		=	echo -e
DEFAULT		=	"\e[0m"
OK_C		=	"\e[32m"
ERROR_C		=	"\e[31m"
LIGHT_RED	=	"\e[91m"

# var

NAME		=	myteams_server
TEST_NAME	=	unit_tests

CC		=	gcc

DLIB			=	../libs/myteams
LIBSO			=	../libs/myteams
DSRC			=	./src
DINCLUDE		=	./include
DCOMMON			=	../common
DTESTS			=	./tests
TOOLS			=	$(DSRC)/tools
DSETUP			=	$(DSRC)/setup
DDATABASE		=	$(DSRC)/database
DDB_TEAMS		=	$(DDATABASE)/teams
DDB_CHANNELS	=	$(DDATABASE)/channels
DDB_THREADS		=	$(DDATABASE)/threads
DDB_REPLIES		=	$(DDATABASE)/replies
DDB_USERS		=	$(DDATABASE)/users
DDB_MESSAGES	=	$(DDATABASE)/msgs

var := $(shell realpath $(PWD)/$(LIBSO)/libmyteams.so)

ifeq ($(.SHELLSTATUS), 0)
LIBSO=../libs/myteams
else
LIBSO=./libs/myteams
endif

LIB		=	myteams

TEST_SRC	=

SRC		=	$(DSETUP)/get_args.c					\
			$(DSETUP)/signal_handler.c				\
			$(DSETUP)/manage_fd_sets.c				\
			\
			$(DSRC)/constant.c						\
			$(DSRC)/usage.c							\
			$(DSRC)/create_server.c					\
			$(DSRC)/get_or_set_server.c 			\
			$(DSRC)/close_server.c					\
			$(DSRC)/destroy_server.c				\
			$(DSRC)/server_my_teams.c				\
			$(DSRC)/check_select_error.c			\
			$(DSRC)/packet_is_empty.c				\
			$(DSRC)/check_fds.c						\
			$(DSRC)/connect_client.c				\
			$(DSRC)/get_high_socket.c				\
			$(DSRC)/close_session.c					\
			$(DSRC)/interprate_clients_req.c		\
			$(DSRC)/free_str_array.c				\
			$(DSRC)/new/new_session.c				\
			$(DSRC)/clean_user.c					\
			\
			$(DSRC)/requests/prepare_buffer.c		\
			$(DSRC)/requests/prepare_buffer_uuid.c	\
			$(DSRC)/requests/prepare_buffer_msg.c	\
			$(DSRC)/requests/is_subscribed.c		\
			$(DSRC)/requests/reset_uuid_t.c			\
			$(DSRC)/requests/put_types.c			\
			$(DSRC)/requests/put_structs.c			\
			$(DSRC)/requests/put_protocol.c			\
			$(DSRC)/requests/login.c				\
			$(DSRC)/requests/logout.c				\
			$(DSRC)/requests/use.c					\
			$(DSRC)/requests/send.c					\
			$(DSRC)/requests/user.c					\
			$(DSRC)/requests/subscribed.c			\
			$(DSRC)/requests/subscribe.c			\
			$(DSRC)/requests/create_req.c			\
			$(DSRC)/requests/create_team.c			\
			$(DSRC)/requests/create_channel.c		\
			$(DSRC)/requests/create_thread.c		\
			$(DSRC)/requests/create_reply.c			\
			$(DSRC)/requests/list_req.c				\
			$(DSRC)/requests/list_team.c			\
			$(DSRC)/requests/list_channel.c			\
			$(DSRC)/requests/list_thread.c			\
			$(DSRC)/requests/list_reply.c			\
			$(DSRC)/requests/list_user.c			\
			$(DSRC)/requests/list_message.c			\
			$(DSRC)/requests/info_team.c			\
			$(DSRC)/requests/info_user.c			\
			$(DSRC)/requests/info_channel.c			\
			$(DSRC)/requests/info_thread.c			\
			$(DSRC)/requests/find_user_in_session.c	\
			$(DSRC)/requests/uuid_is_in_arr.c		\
			\
			$(TOOLS)/uuid.c		\
			$(TOOLS)/str_array.c\
			$(TOOLS)/read.c		\
			$(TOOLS)/write.c	\
			$(TOOLS)/free.c		\
			\
			$(DDATABASE)/database_constants.c	\
			\
			$(DDATABASE)/init_db.c				\
			\
			$(DDATABASE)/file_management/db_file.c	\
			$(DDATABASE)/file_management/db_dir.c	\
			$(DDATABASE)/file_management/header.c	\
			\
			$(DDATABASE)/load_db.c		\
			$(DDATABASE)/save_db.c		\
			$(DDATABASE)/delete_db.c	\
			$(DDATABASE)/dump_db.c		\
			\
			$(DDB_TEAMS)/count_teams.c		\
			$(DDB_TEAMS)/load_teams.c		\
			$(DDB_TEAMS)/save_teams.c		\
			$(DDB_TEAMS)/insert_teams.c		\
            $(DDB_TEAMS)/new_team.c 		\
            $(DDB_TEAMS)/find_team.c 		\
			$(DDB_TEAMS)/delete_teams.c		\
			$(DDB_TEAMS)/dump_teams.c		\
			\
			$(DDB_CHANNELS)/count_channels.c	\
			$(DDB_CHANNELS)/load_channels.c		\
			$(DDB_CHANNELS)/save_channels.c		\
			$(DDB_CHANNELS)/insert_channels.c	\
            $(DDB_CHANNELS)/new_channel.c 		\
            $(DDB_CHANNELS)/find_channel.c 		\
			$(DDB_CHANNELS)/delete_channels.c	\
			\
			$(DDB_THREADS)/count_threads.c		\
			$(DDB_THREADS)/load_threads.c		\
			$(DDB_THREADS)/save_threads.c		\
			$(DDB_THREADS)/insert_threads.c		\
            $(DDB_THREADS)/new_thread.c 		\
            $(DDB_THREADS)/find_thread.c 		\
            $(DDB_THREADS)/delete_threads.c		\
			\
			$(DDB_REPLIES)/count_replies.c		\
			$(DDB_REPLIES)/load_replies.c		\
			$(DDB_REPLIES)/save_replies.c		\
			$(DDB_REPLIES)/insert_replies.c		\
            $(DDB_REPLIES)/new_reply.c 			\
			$(DDB_REPLIES)/delete_replies.c		\
			\
			$(DDB_USERS)/count_users.c		\
			$(DDB_USERS)/load_users.c		\
			$(DDB_USERS)/save_users.c		\
			$(DDB_USERS)/insert_users.c		\
			$(DDB_USERS)/new_user.c 		\
			$(DDB_USERS)/find_user.c 		\
			$(DDB_USERS)/delete_users.c		\
			\
			$(DDB_MESSAGES)/count_msgs.c	\
			$(DDB_MESSAGES)/load_msgs.c		\
			$(DDB_MESSAGES)/save_msgs.c		\
			$(DDB_MESSAGES)/insert_msgs.c	\
            $(DDB_MESSAGES)/new_msg.c 		\
			$(DDB_MESSAGES)/delete_msgs.c	\

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

debug: CFLAGS += -g3 -ggdb -D DEBUG
debug: re

# tests_run:
#	$(CC) $(TEST_SRC) $(SRC) -o $(TEST_NAME) -lcriterion --coverage -I $(DINCLUDE) $(LDFLAGS)
#	./$(TEST_NAME)

.PHONY:	all $(NAME) clean fclean re tests_run debug