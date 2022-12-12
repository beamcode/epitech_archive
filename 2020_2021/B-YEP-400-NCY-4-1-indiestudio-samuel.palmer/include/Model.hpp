/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Model
*/

#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <raylib.h>
#include <raymath.h>
#include <string>
#include <iostream>
#include "Sound.hpp"

/** @brief Class for all Model
    @date June 2021
    */

class _Model {
    public:
       
        /** My first constructor
        @param obj - the path to the model
        @param texture - the path to the texture
        */
        _Model(const std::string &obj, const std::string &texture);
         /** My second constructor
        @param obj - the path to the model
        @param texture - the path to the texture
        @param index - the index of obj
        */
       
        _Model(const std::string &obj, const std::string &texture, int index);
        virtual ~_Model();

        template<typename T>
       
        /**Convert string to char *
          * @param const string to convert
          * @return the converted char *
        */

        const char *strToChar(const T &str) {
          return (str.c_str());
        }
       
        /**Draw the current obj
        */
       
        void draw() const;
       
        /**Change the texture path
        @param path to the texture
       
        */
        void change_texture(const std::string &path);
       
        /**Change the texture path
        @return the path of the texture
        */
       
        std::string getTexture() const;
       
        /**Apply texture
        @param path - the path of the texture
        @param i - apply texture to correspoding meche
        */
       
        void load_texture(const std::string &path, int i);
        
        /**Changes specific value in Vector3
        @param v - sets the given value to the associated Vector3 position in 2nd param
        @param val - character used to indicated which value must be changed in the Vector3 (x, y, z)
        */
       
        void set_pos_of(float v, const std::string &val);

        /**Changes specific value in Vector3
        @param v - sets the given value to the associated Vector3 position in 2nd param
        @param val - character used to indicated which value must be changed in the Vector3 (x, y, z)
        */    

        void set_axis_of(float v, const std::string &val);
        
        /**Changes specific value in Vector3
        @param v - sets the given value to the associated Vector3 position in 2nd param
        @param val - character used to indicated which value must be changed in the Vector3 (x, y, z)
        */

        void set_scale_of(float v, const std::string &val);

        /**Changes specific value in Vector3
        @param v - sets the given value to the associated Vector3 position in 2nd param
        @param val - character used to indicated which value must be changed in the Vector3 (x, y, z)
        */

        void set_angle(float _angle) { angle = _angle; };

        /**Sets model angle
        @param _angle - sets model angle value
        */
        
        void set_pos(float x, float y, float z) { position = {x, y, z}; };

        /**Sets model position
        @param x - sets x position for the model
        @param y - sets y position for the model
        @param z - sets z position for the model
        */

        void set_axis(float x, float y, float z) { axis = {x, y, z}; };

        /**Sets model axis
        @param x - sets x axis for the model
        @param y - sets y axis for the model
        @param z - sets z axis for the model
        */

        void set_scale(float x, float y, float z) { scale = {x, y, z}; };

        /**Sets model scale
        @param x - sets x scale for the model
        @param y - sets y scale for the model
        @param z - sets z scale for the model
        */
        
        void set_pos(Vector3 _position) { position = _position; };

        /**Sets model position
        @param _position - sets all 3 of the models positions with a Vector3 as paramater 
        */

        void set_scale(Vector3 _scale) { scale = _scale; };

        /**Sets model scale
        @param _scale - sets all 3 of the models scale values with a Vector3 as paramater 
        */

        void set_axis(Vector3 _axis) { axis = _axis; };

        /**Sets model axis
        @param _axis - sets all 3 of the models axis values with a Vector3 as paramater 
        */

        Vector3 get_axis() const { return (axis); };

        /**Gets axis values
        @return Vector3 of axis values
        */

        Vector3 get_scale() const { return (scale); };

        /**Gets scale values
        @return Vector3 of scale values
        */

        Vector3 get_pos() const { return (position); };

        /**Gets axis values
        @return Vector3 of position values
        */

        void loadAnimations(const std::string &path, int count);

        /**Loads a aditional animation for the model
        @param path - path to the animation file
        @param count - animation count value that must be parsed
        */

        void blender_adjust();

        /**Adjusts up axis from blender models to the up axis of the raylib (z --> y)
        */


        /**Get Index
        @return Index
        */
        int getIndex() const { return (index); };

    protected:
        Model model;/**<Model obj*/
        Texture2D texture;/**<Texture of the model*/

        Vector3 position;/**<Position of the model on x, y, z**/
        Vector3 scale;/**<Scale of the model on x, y, z*/
        Vector3 axis;/**<Axis of the model on x, y, z**/
        float angle;/**<Angle of the model 0 to 360*/

        std::string textPath;/**<Path of texture*/
        int index;/**<Class index value*/
        Texture2D tmp;/**<Texture for tmp model**/
    private:
};

#endif /* !MODEL_HPP_ */