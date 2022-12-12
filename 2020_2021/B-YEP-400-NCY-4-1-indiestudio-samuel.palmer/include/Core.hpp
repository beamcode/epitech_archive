/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <raylib.h>
#include <rlgl.h>

#include "CharactersChoice.hpp"
#include "Window.hpp"
#include "Camera.hpp"
#include "Music.hpp"
#include "Skybox.hpp"
#include "Model.hpp"
#include "Map.hpp"
#include "Scene.hpp"
#include "Menu.hpp"
#include "Game.hpp"
#include "Options.hpp"
#include "End.hpp"


/** @brief class of the program core

    @date June 2021
    */
class Core {
    public:
        /** My core constructor
        */
        Core();
        ~Core();
        /**Draw the current scene
        */
        void draw() const;
        /**Update the current scene
        */
        void update();
        /**Main loop
        @return int that indicate if game is on
        */
        int loop();
    protected:
    private:
        std::shared_ptr<Save> save;/**<Ptr to save */
        _Window window;/**<Window obj*/
        _Camera camera;/**<Camera obj*/
        std::vector<std::shared_ptr<IScene>> sceneList;/**<?????????*/
        int index;/**<Class index value*/
};

#endif /* !Core_HPP_ */
