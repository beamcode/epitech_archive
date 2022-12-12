/*
** EPITECH PROJECT,2019
** my_strcat
** File description:
** 
*/

char *my_strcat(char *dest, char const *src)
{
    int a = 0;

    while (dest[a] != '\0') {
        a++;
    }
    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = a;
    return (dest);
}