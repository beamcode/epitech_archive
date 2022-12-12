/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Missile
*/

#ifndef Missile_HPP_
#define Missile_HPP_

#include <iostream>

class Missile {
    public:
        Missile(int val, int _dir, int x, int y);
        ~Missile();
        
        void move_proj();
        std::pair<int, int> get_pos() const;
        void set_dir(int _dir);
        int get_dir();
    private:
        std::pair<int, std::pair<int, int>> proj;
        unsigned int dir;
};

#endif /* !MISSILE_HPP_ */
