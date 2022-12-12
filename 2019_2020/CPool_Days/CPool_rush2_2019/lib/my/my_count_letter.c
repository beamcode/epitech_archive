/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

int my_count_letter(char const *str)
{
    int i = 0;
    int occ = 0;

    while (str[i] != '\0') {
        if ((str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z')) {
            occ++;
        }
        i++;
    }
    return (occ);
}
