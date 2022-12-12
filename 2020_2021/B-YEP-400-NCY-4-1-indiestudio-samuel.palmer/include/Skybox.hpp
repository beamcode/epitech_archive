/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Skybox
*/

#ifndef Skybox_HPP_
#define Skybox_HPP_

#include <raylib.h>
#include <rlgl.h>
#include <string>

class _Skybox {
    public:
        _Skybox(float width, float height, float lenght, const std::string &path_img);
        ~_Skybox();

        void draw() const;
        void set_color(Color _color);
        void set_size(float size);
        void set_pos(float x, float y, float z);
        void set_texture(const std::string &path_img);

    protected:
    private:
        Mesh cube;
        Model skybox;
        Color color;
        Vector3 position;
        float size;
        Image img;
};

#endif /* !Skybox_HPP_ */
