/*
** EPITECH PROJECT, 2021
** B-NWP-400-REN-4-1-myteams-aurelien.joncour
** File description:
** packet
*/

#ifndef PACKET_H_
#define PACKET_H_

#define SUCCESS_CODE 2
#define ERROR_CODE 4

typedef enum succ_response_e {
    NONE_SUCC_RES,
    SINGLE_ELEM,
    LIST_ELEM,
    CREATED,
    EVENT,
    OTHER_EVENT
} succ_response_t;

typedef enum err_response_e {
    NONE_ERR_RES,
    UNKNOWN_ERR,
} err_response_t;

typedef enum packet_type_e {
    NONE_PACK_TYPE,
    USER,
    TEAM,
    CHANNEL,
    THREAD,
    REPLY,
    MSG,
} packet_type_t;


#endif /* !PACKET_H_ */
