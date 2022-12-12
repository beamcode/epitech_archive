/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Bonus
*/

#ifndef BONUS_HPP_
#define BONUS_HPP_

#include <raylib.h>
#include <string>
#include <memory>
#include "Model.hpp"

/** @brief Class to deal with Bonus
    @date June 2021
    */

class Player;
class Bonus : public _Model {
    public:
        /** My first constructor
        @param obj - the path to the model
        @param texture - the path to the texture
        @param index - class index
        */
        Bonus(const std::string &obj, const std::string &texture, int index);
        virtual ~Bonus();
        /**Did player have a bonus
        @param player - ptr to actual player
        @return if the player have a bonus
        */
        bool hasPlayerOn(std::shared_ptr<Player> player);

    private:
      float time;/**<Time for bonus apparance*/
};

#include "Player.hpp"
#endif /* !BONUS_HPP_ */
