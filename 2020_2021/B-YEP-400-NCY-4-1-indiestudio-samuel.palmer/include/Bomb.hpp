/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <raylib.h>
#include <string>
#include <memory>
#include "Model.hpp"

/** @brief Class to deal with bomb obj
    @date June 2021
    */
class Bomb : public _Model {
    public:
        /** My constructor. Initializes bomb.
        @param obj - the path to the model
        @param texture - the path to the texture
        @param index - the index of obj
        */
        Bomb(const std::string &obj, const std::string &texture, int index);
        virtual ~Bomb();

        /**
        @return If the bomb is to be destroyed
        */

        bool timeToDestroy();

        /**
        @return If the bomb is destroyed
        */

        bool destroy();

        /** Event that plays the bomb destroyed sound
        */
        void playSound();


        /**
        @return The class Index
        */
        int getIndex() const;

    private:
        std::shared_ptr<_Sound> sound;/**<Ptr to sound of bomb */
        float time;/**<Time use for bomb placement */
};

#endif /* !BOMB_HPP_ */
