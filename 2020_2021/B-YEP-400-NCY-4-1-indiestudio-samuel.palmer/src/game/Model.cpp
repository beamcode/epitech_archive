/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** model
*/
#include "Model.hpp"

_Model::_Model(const std::string &obj, const std::string &_texture)
{
    model = LoadModel(strToChar(obj));

    textPath = _texture;
    load_texture(strToChar(_texture), 0);
    position = {0.0f, 0.0f, 0.0f};
    scale = {0.2f, 0.2f, 0.2f};
    axis = { 0.0f, 1.0f, 0.0f };
    angle = 0.0f;
    index = 0;
}

_Model::_Model(const std::string &obj, const std::string &_texture, int _index)
{
    index = _index;
    textPath = _texture;
    model = LoadModel(strToChar(obj));
    texture = LoadTexture(strToChar(_texture));
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    position = {0.0f, 0.0f, 0.0f};
    scale = {0.2f, 0.2f, 0.2f};
    axis = { 0.0f, 1.0f, 0.0f };
    angle = 0.0f;
}

_Model::~_Model()
{
    //UnloadModel(model);
    //UnloadTexture(texture);
    //UnloadTexture(tmp);*/
}

void _Model::draw() const
{
    DrawModelEx(model, position, axis, angle, scale, WHITE);
}

std::string _Model::getTexture() const
{
    return (textPath);
}

void _Model::load_texture(const std::string &path, int i)
{
    textPath = path;
    tmp = LoadTexture(strToChar(path));
    model.materials[i].maps[MATERIAL_MAP_DIFFUSE].texture = tmp;
}

void _Model::set_scale_of(float v, const std::string &val)
{
    if (val == "x")
        scale.x = v;
    else if (val == "y")
        scale.y = v;
    else if (val == "z")
        scale.z = v;
}

void _Model::set_pos_of(float v, const std::string &val)
{
    if (val == "x")
        position.x = v;
    else if (val == "y")
        position.y = v;
    else if (val == "z")
        position.z = v;
}

void _Model::set_axis_of(float v, const std::string &val)
{
    if (val == "z")
        axis.z = v;
    else if (val == "y")
        axis.y = v;
    else if (val == "x")
        axis.x = v;
}

void _Model::blender_adjust()
{
    model.transform = MatrixRotateX( (PI * 2) / 4 );
}
