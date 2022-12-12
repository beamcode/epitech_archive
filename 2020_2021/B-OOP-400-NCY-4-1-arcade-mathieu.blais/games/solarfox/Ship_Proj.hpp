/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Ship_Proj
*/

#ifndef Ship_Proj_HPP_
#define Ship_Proj_HPP_

#include <iostream>

class Ship_Proj {
    public:
        Ship_Proj(int x, int y, int dir);
        ~Ship_Proj();
        
        int decay();
        const int color;
        int get_color();
        void move_proj();
        std::pair<int, int> get_pos() const;
    protected:
    private:
        int dir;
        int moved;
        std::pair<int, int> pos;
};

#endif /* !SHIP_PROJ_HPP_ */
