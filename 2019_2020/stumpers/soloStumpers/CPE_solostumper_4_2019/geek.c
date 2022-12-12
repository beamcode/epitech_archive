/*
** EPITECH PROJECT, 2019
** geek.c
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int my_strlen(char const *str) 
{
    int a = 0;

    for ( ; str[a] != '\0'; a++);
    return a;
}

static int my_putstr(char const *str) 
{
    return (write(1, str, my_strlen(str)));
}

static char* reverse_string_maj(char* name)
{
    int a = 0;
    int b = 0;

    while (name[b] != '\0') {
      printf("passed\n");
        if (a == 0) { 
	    if (name[b] >= 97 && name[b] <= 122) {
	        name[b] = name[b] - 32;
		a++;
		b++;
		continue;
	    }
        }
	else 
            name[b] = name[b];
        if (a == 1)
	    a = 0;
	b++;
    }
    return (name);
}

static char* reverse_string_min(char* name)
{
    int a = 0;
    int b = 1;

    while (name[b] != '\0') {
        if (a == 0) { 
            if (name[b] >= 65 && name[b] <= 90) {
	        name[b] = name[b] + 32;
	        a++;
	        b += 2;
	        continue;
            }
        }
        else name[b] = name[b];
        if (a == 1)
            a = 0;
        b += 2;
    }
    return (name);
}

int main(int ac, char** av)
{
    char* name = av[1];

    name = reverse_string_maj(name);
    name = reverse_string_min(name);
    printf("%s\n", name);
    //my_putstr(name);

    while (1) {


    //my_putstr("\n");
    return (0);
}

