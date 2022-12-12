/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Bomb
*/

#ifndef FIRE_HPP_
#define FIRE_HPP_

#include <raylib.h>
#include <string>
#include <memory>
#include "Model.hpp"

class Fire : public _Model {
    public:
        Fire(const std::string &obj, const std::string &texture);
        virtual ~Fire();
        bool timeToStop();

    private:
      float time;
};

#endif /* !FIRE_HPP_ */
