/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

//INCLUDE

#include <stdbool.h>

//--------------------------------
//DEFINE

#define EXIT_SUC 0
#define EXIT_FAIL 84

#define IS_DIGIT(x) ('0' <= x && x <= '9')


//-------------------------------
//FUNCTIONS

//setup
bool get_args(char **av, unsigned short *port);


#endif /* !SERVER_H_ */
