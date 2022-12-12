/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

int check_alphanum(char a)
{
    if ((a < '0' || a > '9') && (a < 'A' || a > 'Z') && (a < 'a' || a > 'z'))
        return (1);
    return (0);
}

char *my_strcapitalize_synthesis(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    for (int a = 1; str[a] != '\0'; a++) {
        if (check_alphanum(str[a - 1]) && (str[a] >= 'a' && str[a] <= 'z'))
            str[a] -= 32;
    }
    return (str);
}