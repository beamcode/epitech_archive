/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Crate
*/

#ifndef CRATE_HPP_
#define CRATE_HPP_

#include <raylib.h>
#include <string>
#include "Model.hpp"

class Crate : public _Model {
    public:
        Crate(const std::string &obj, const std::string &texture);
        virtual ~Crate();

    private:
};

#endif /* !CRATE_HPP_ */
