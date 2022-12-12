/*
** EPITECH PROJECT , 2019
** MAIN TESTING
** File description :
** testing
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
        if (a == n) {
            dest[a] = '\0';
            return(dest);
        }
    }
    dest[a] = '\0';
    return (dest);
}