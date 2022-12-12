/*
**EPITECH PROJECT,2019
**test
**File description:
**test
*/

char *my_strcpy(char *dest, const char *src)
{
    int a = 0;

    while (src[a] != '\0') {
        dest[a] = src[a];
        a++;
    }
    dest[a] = '\0';
    return (dest);
}