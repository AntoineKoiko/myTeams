/*
** EPITECH PROJECT, 2021
** file_management.h
** File description:
** Manage files that contains data
*/
#ifndef SERVER_FILE_MANAGEMENT_H
#define SERVER_FILE_MANAGEMENT_H

typedef struct file_header_s
{
    int magic_number;
    int file_type;
    int elements_nb;
} file_header_t;

#endif // SERVER_FILE_MANAGEMENT_H