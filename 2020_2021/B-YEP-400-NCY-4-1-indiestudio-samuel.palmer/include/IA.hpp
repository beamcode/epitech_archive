/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IA
*/

#ifndef IA_HPP_
#define IA_HPP_

#include "Player.hpp"

class IA : public Player {
    public:
        IA(const std::string &obj, const std::string &texture);
        virtual ~IA();
        void moveIA();

    protected:
    private:
      int t;
      int tmp;
};

#endif /* !IA_HPP_ */
