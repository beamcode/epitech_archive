/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "Core.hpp"

int main()
{
    std::shared_ptr<Core> core(new Core());
    core->loop();
    return (0);
}
