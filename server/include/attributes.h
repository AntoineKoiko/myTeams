/*
** EPITECH PROJECT, 2021
** attributes.h
** File description:
** Compiler attributes macros
*/
#ifndef SERVER_ATTRIBUTES_H
#define SERVER_ATTRIBUTES_H

#ifndef N_U
    #define N_U __attribute__((unused))
#endif

#ifndef NON_NULL
    /**
     * @brief Tell compiler that certain arguments should not be NULL, if
     * so, it generates a warning
     * @param ... The positions of the arguments that should not be null
     */
    #define NON_NULL(...) __attribute__((nonnull(__VA_ARGS__)))
#endif

#endif // SERVER_ATTRIBUTES_H