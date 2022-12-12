/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** camera
*/

#include "Camera.hpp"

_Camera::_Camera()
{
    camera = {0};
    camera.position = {-2.0f, 17.0f, 6.5f};
    camera.target = {5.5f, 0.0f, 6.5f};
    camera.up = {0.0f, 1.0f, 0.0f};
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    mode = false;
}

_Camera::~_Camera()
{
}

void _Camera::free_camera()
{
    if (mode) {
        SetCameraMode(camera, CAMERA_PERSPECTIVE);
        camera.position = {-2.0f, 4.0f, 6.5f};
        camera.target = {5.5f, 0.0f, 6.5f};
        camera.up = {0.0f, 1.0f, 0.0f};
        mode = false;
    }
    else {
        SetCameraMode(camera, CAMERA_FIRST_PERSON);
        mode = true;
    }
}

void _Camera::update_camera()
{
    UpdateCamera(&camera);
}

Camera _Camera::get_camera() const
{
    return (camera);
}

void _Camera::set_pos(float x, float y, float z)
{
    camera.position = {x, y, z};
}

void _Camera::set_target(float x, float y, float z)
{
    camera.target = {x, y, z};
}
