/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

#define TO_LOWER(val) ((val) >= 'A' && (val) <= 'Z' ? (val) + 32 : (val))

int my_count_letter(char const *str);
int my_put_float(float nb_float, int precision);
int my_put_nbr(int nb);
void my_putchar(char c);
void my_putchar_error(char c);
void my_putstr(char const *str);
void my_putstr_error(char const *str);
int my_pow(int a, int b);
int my_strlen(char const *str);
int rush2(int ac, char **av);