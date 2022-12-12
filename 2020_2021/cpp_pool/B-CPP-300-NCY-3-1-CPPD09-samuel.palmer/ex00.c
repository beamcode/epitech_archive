/*
** EPITECH PROJECT, 2021
** ex00.c
** File description:
** ex00
*/

#include "ex00.h"

//Class and Inits
static void koala_initializer(koala_t *this, char *_name, char _is_A_Legend)
{
    this->m_parent.m_name = _name;
    this->m_is_a_legend = _is_A_Legend;
    if (_is_A_Legend == 1)
        printf("Building Legend\n");
    else if (_is_A_Legend == 0) {
        this->m_parent.m_power = 0;
        printf("Building NotLegend\n");
    }
}

void cthulhu_initializer(cthulhu_t *this)
{
    printf("----\nBuilding Cthulhu\n");
    this->m_name = "Cthulhu";
    this->m_power = 42;
}

cthulhu_t *new_cthulhu()
{
    cthulhu_t *new = malloc(sizeof(cthulhu_t));
    if (new == NULL)
        return (NULL);
    cthulhu_initializer(new);
    return (new);
}

koala_t *new_koala(char *name, char is_a_legend)
{
    koala_t *new = malloc(sizeof(koala_t));
    if (new == NULL)
        return (NULL);
    new->m_parent = *new_cthulhu();
    koala_initializer(new, name, is_a_legend);
    return (new);
}

//Other functions
void eat(koala_t *this)
{
    printf("%s eats\n", this->m_parent.m_name);
    this->m_parent.m_power += 42;
}

void sleeping(cthulhu_t *this)
{
    printf("%s sleeps\n", this->m_name);
    this->m_power += 42000;
}

void attack(cthulhu_t *this)
{
    if (this->m_power >= 42) {
        printf("%s attacks and destroys the city\n", this->m_name);
        this->m_power -= 42;
    }
    else
        printf("%s can't attack, he doesn't have enough power\n", this->m_name);
}

void print_power(cthulhu_t *this)
{
    printf("Power => %d\n", this->m_power);
}