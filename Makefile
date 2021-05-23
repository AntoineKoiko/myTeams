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


SERVER_NAME = myteams_server
CLIENT_NAME = myteams_cli

SERVER_D = ./server
CLIENT_D = ./client

all: $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME):
	make -C $(SERVER_D)

$(CLIENT_NAME):
	make -C $(CLIENT_D)

clean:
	make clean -C $(SERVER_D)
	make clean -C $(CLIENT_D)

fclean:
	make fclean -C $(SERVER_D)
	make fclean -C $(CLIENT_D)
	rm -rf $(SERVER_NAME)
	rm -rf $(CLIENT_NAME)

re:
	rm -rf $(SERVER_NAME)
	rm -rf $(CLIENT_NAME)
	make re -C $(SERVER_D)
	make re -C $(CLIENT_D)

debug:
	make debug -C $(SERVER_D)
	make debug -C $(CLIENT_D)

clean_server:
	make clean -C $(SERVER_D)

clean_client:
	make clean -C $(CLIENT_D)

fclean_server:
	make fclean -C $(SERVER_D)
	rm -rf $(SERVER_NAME)

fclean_cliennt:
	make fclean -C $(CLIENT_D)
	rm -rf $(CLIENT_NAME)

re_server:
	rm -rf $(SERVER_NAME)
	make re -C $(SERVER_D)

re_client:
	rm -rf $(CLIENT_NAME)
	make re -C $(CLIENT_D)

.PHONY: all $(SERVER_NAME)  $(CLIENT_NAME) clean fclean re clean_server clean_client fclean_server fclean_cliennt re_server re_client
