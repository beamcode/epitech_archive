/*
** EPITECH PROJECT, 2019
** myatoi
** File description:
** ok
*/

int my_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int val = 0;
    int nbr = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            sign = -sign;
            str++;
        }
        if (str[i] >= 'a' && str[i] <= 'z')
            return (0);
        if (str[i] >= 'a' && str[i] <= 'z')
            return (0);
    }
    i = 0;
    for (; str[i] >= '0' && str[i] <= '9' && str[i] != '\0'; i++) {
        nbr = str[i] - '0';
        val = (val * 10) + nbr;
    }
    return (val * sign);
}
