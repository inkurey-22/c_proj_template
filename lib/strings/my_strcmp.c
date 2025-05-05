/*
** EPITECH PROJECT, 2024
** B-CPE-100-LIL-1-1-cpoolday06-theophile.riffe
** File description:
** my_strcmp
*/

#include <stddef.h>
#include "my_strings.h"

static int my_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int my_strcmp(char const *s1, char const *s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return - s2[0];
    if (s2 == NULL)
        return s1[0];
    for (int i = 0;; i++){
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0')
            return 0;
    }
    return 0;
}

int my_strcasecmp(char const *s1, char const *s2)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return - s2[0];
    if (s2 == NULL)
        return s1[0];
    for (int i = 0;; i++){
        if (my_tolower(s1[i]) != my_tolower(s2[i]))
            return my_tolower(s1[i]) - my_tolower(s2[i]);
        if (s1[i] == '\0')
            return 0;
    }
    return 0;
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    if (s1 == NULL && s2 == NULL)
        return 0;
    if (s1 == NULL)
        return - s2[0];
    if (s2 == NULL)
        return s1[0];
    for (int i = 0; i < n; i++){
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0')
            return 0;
    }
    return 0;
}
