/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Model
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <raylib.h>
#include <string>


/** @brief Class to deal with a specific sprite

    @date June 2021
    */
class Sprite {
    public:
        /** My constructor. Initializes sprite.
        @param path - the path of the ressource file
        @param _x - _x coordinate of the point
        @param _y - _y coordinate of the point 
        @param _color - _color color of the sprite 
        @param index - index of the sprite
        */
        Sprite(const std::string path, int _x, int _y, Color _color, int index);
        ~Sprite();

        template<typename T>
        /**Convert string to char *
          * @param const string to convert
          * @return the converted char *
        */
        const char *strToChar(const T &str) {
            return (str.c_str());
        }
         /**Draw the current sprite obj
        */
        void draw()const;
         /**@return the easting of the current sprite
        */
        float getXPosition() const;
        /**@return the northing of the current sprite
        */
        float getYPosition() const;
        /**@return the index of the current sprite
        */
        int getIndex() const;
        /**Change path of the sprite ressource
        */
        void changePath(const std::string &path);
         /**Get path of the sprite ressource
          * @param path of the ressources
        */
        std::string getPath() const;
        std::string getScoreboardPath();

    protected:
    private:
        Image image; /**<Image of sprite */
        Texture2D texture;/**<texture of sprite */
        int x;/**<???? */
        int y;/**<???? */
        Color color;/**<Color of sprite */
        int index;/**<Class index value*/
        std::string path;/**<Path to sprite texture*/
};

#endif /* !MODEL_HPP_ */
