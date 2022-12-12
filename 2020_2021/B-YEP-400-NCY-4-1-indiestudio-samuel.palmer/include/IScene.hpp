/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Iscene
*/

#ifndef IScene_HPP_
#define IScene_HPP_

#include "rlgl.h"
#include "raylib.h"

#include <string>
#include <vector>
#include <memory>
#include <ostream>
#include <iostream>
#include <fstream>
#include <utility>

#include "GameVariable.hpp"
#include "Scoreboard.hpp"
#include "Window.hpp"
#include "Camera.hpp"
#include "Skybox.hpp"
#include "Player.hpp"
#include "Sprite.hpp"
#include "Event.hpp"
#include "Music.hpp"
#include "Model.hpp"
#include "Sound.hpp"
#include "Text.hpp"
#include "Map.hpp"
#include "IA.hpp"
#include "Fire.hpp"
#include "Bonus.hpp"
#include "Bomb.hpp"
#include "Crate.hpp"

/** @brief Interface class all scene

    @date June 2021
    */
class IScene {
    public:
        virtual ~IScene() = default;
         /**Draw the 3D scene
        */
        virtual void drawScene3d() const = 0;
        /**Draw the 2D scene
        */
        virtual void drawScene2d() const = 0;
        /**Update the actual scene
        */
        virtual void updateScene() = 0;
        /**Add a new music to the scene
         @param the path of the ressource file
        */
        virtual void addMusic(const std::string &path) = 0;
         /**Add a skybox to the scene
        @param path - the path of the ressource file
        @param width - width of the skybox  
        @param height - height of the skybox
        @param lenght - lenght of the skybox
        */
        virtual void addSkybox(float width, float height, float lenght, const std::string &path) = 0;
        /**Add a Map to the scene
        */
        virtual void addMap() = 0;
        /**Add a Model to the scene
         @param a - is the obj
         @param b - is the texture
        */
        virtual void addModel(const std::string &a, const std::string &b) = 0;
        /** add sprite to the scene
        @param path - the path of the ressource file
        @param x - x coordinate of the point
        @param y - y coordinate of the point 
        @param color - color color of the sprite 
        @param index - index of the sprite
        */
        virtual void addSprite(const std::string &path, int x, int y, Color color, int index) = 0;
        /**Name getter
        @return name of the actual scene
        */
        virtual std::string getName() const = 0;
        /**Change scene
        @return the scene dto be display
        */
        virtual std::string changeScene() const = 0;
        /**check if the scene is closed
        @return true if the game should be close closed
        */
        virtual bool isClosed() const = 0;
        /**Refresh the scene
        */
        virtual void refresh() = 0;
};

#endif /* !IScene_HPP_ */
