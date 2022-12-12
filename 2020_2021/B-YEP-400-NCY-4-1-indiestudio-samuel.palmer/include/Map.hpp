/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Map
*/

#ifndef Map_HPP_
#define Map_HPP_

#include <raylib.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class _Map {
    public:
        _Map();
        ~_Map();

        void set_pos(float x, float y, float z);
        Model get_model() const;
        Vector3 get_pos() const;
        void draw() const;
        void set_scale(Vector3 _scale);
        std::string getName() const;
        void changeMap(const std::string &_name);

    protected:
    private:
        float angle;
        Mesh mesh;
        Model model;
        Vector3 axis;
        Vector3 scale;
        Vector3 position;
        Texture2D texture;
        Texture2D cubicmap;
        std::vector<std::string> mapList;
        std::string name;
        Image image;
};

#endif /* !Map_HPP_ */
