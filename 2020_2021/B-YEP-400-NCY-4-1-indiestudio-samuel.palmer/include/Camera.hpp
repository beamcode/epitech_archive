/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <raylib.h>

/** @brief Class to play with camera
    @date June 2021
    */

class _Camera {
    public:
        /** Default constructor
        */
        _Camera();
        ~_Camera();


        /**@return camera obj
        */
        Camera get_camera() const;
        /** free camera obj
        */
        void free_camera();
        /** update camera obj
        */
        void update_camera();
        /** set camera position
        @param x - sets x position for the camera
        @param y - sets y position for the camera
        @param z - sets z position for the camera
        */
        void set_pos(float x, float y, float z);
        /** set camera inclination
        @param x - sets x inclination for the camera
        @param y - sets y inclination for the camera
        @param z - sets z inclination for the camera
        */
        void set_target(float x, float y, float z);

    protected:
    private:
        Camera camera;/**<initial Camera obj*/
        bool mode;/**<initial bool to switch camera view settings*/
};

#endif /* !CAMERA_HPP_ */
