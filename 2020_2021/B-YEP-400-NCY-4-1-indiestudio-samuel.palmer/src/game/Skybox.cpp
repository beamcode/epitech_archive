/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Skybox
*/

#include "Skybox.hpp"

_Skybox::_Skybox(float width, float height, float lenght, const std::string &path_img)
{
    cube = GenMeshCube(width, height, lenght);
    skybox = LoadModelFromMesh(cube);
    position = {0.0f, 0.0f, 0.0f};
    size = 100.0f;
    int a = MATERIAL_MAP_CUBEMAP;
    int b = 0;
    skybox.materials[0].shader = LoadShader(TextFormat("resources/shaders/glsl330/skybox.vs"), TextFormat("resources/shaders/glsl330/skybox.fs"));
    SetShaderValue(skybox.materials[0].shader, GetShaderLocation(skybox.materials[0].shader, "environmentMap"), &a, SHADER_UNIFORM_INT);
    SetShaderValue(skybox.materials[0].shader, GetShaderLocation(skybox.materials[0].shader, "doGamma"), &b, SHADER_UNIFORM_INT);
    SetShaderValue(skybox.materials[0].shader, GetShaderLocation(skybox.materials[0].shader, "vflipped"), &b, SHADER_UNIFORM_INT);
    set_texture(path_img);
}

_Skybox::~_Skybox()
{
  //  UnloadImage(img);
  //  UnloadShader(skybox.materials[0].shader);
}

void _Skybox::set_texture(const std::string &path_img)
{
    img = LoadImage(path_img.c_str());
    skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = LoadTextureCubemap(img, CUBEMAP_LAYOUT_AUTO_DETECT);
}

void _Skybox::draw() const
{
    rlDisableBackfaceCulling();
    rlDisableDepthMask();
    DrawModel(skybox, position, size, color);
    rlEnableBackfaceCulling();
    rlEnableDepthMask();
}

void _Skybox::set_color(Color _color)
{
    color = _color;
}

void _Skybox::set_size(float _size)
{
    size = _size;
}

void _Skybox::set_pos(float x, float y, float z)
{
    position = {x, y, z};
}
