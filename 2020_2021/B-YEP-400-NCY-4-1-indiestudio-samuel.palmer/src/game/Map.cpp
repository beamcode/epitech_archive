/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Map
*/
#include "Map.hpp"


_Map::_Map()
{
    srand(time(NULL));
    int t = rand() % 4;
    mapList.push_back("resources/img/map1.png");
    mapList.push_back("resources/img/map2.png");
    mapList.push_back("resources/img/map3.png");
    mapList.push_back("resources/img/map4.png");
    std::string map = mapList[t];
    name = map;
    image = LoadImage(map.c_str());
    cubicmap = LoadTextureFromImage(image);
    mesh = GenMeshCubicmap(image, Vector3{ 1.0f, 1.0f, 1.0f });
    model = LoadModelFromMesh(mesh);
    texture = LoadTexture("resources/img/cubicmap_atlas.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    position = { 0.5f, 0.0f, 0.5f };
    scale = { 1.0f, 1.0f, 1.0f };
    axis = { 0.0f, 1.0f, 0.0f };
    angle = 0.0f;
}

_Map::~_Map()
{
    //UnloadTexture(cubicmap);
    //UnloadImage(image);
    //UnloadMesh(mesh);
}

void _Map::changeMap(const std::string &_name)
{
    name = _name;
    Image image = LoadImage(name.c_str());
    cubicmap = LoadTextureFromImage(image);
    mesh = GenMeshCubicmap(image, Vector3{ 1.0f, 1.0f, 1.0f });
    UnloadImage(image);
    model = LoadModelFromMesh(mesh);
    texture = LoadTexture("resources/img/cubicmap_atlas.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
}

void _Map::draw() const
{
    DrawModelEx(model, position, axis, angle, scale, WHITE);
}

void _Map::set_pos(float x, float y, float z)
{
    position = {x, y, z};
}

void _Map::set_scale(Vector3 _scale)
{
    scale = _scale;
}

Model _Map::get_model() const
{
    return (model);
}

Vector3 _Map::get_pos() const
{
    return (position);
}

std::string _Map::getName() const
{
    return (name);
}
