/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** model
*/

#include "Sprite.hpp"

Sprite::Sprite(const std::string path, int _x, int _y, Color _color, int _index)
{
    this->path = path;
    const char *file = strToChar(path);
    image = LoadImage(file);
    texture = LoadTextureFromImage(image);
    x = _x;
    y = _y;
    color = _color;
    index = _index;
}

Sprite::~Sprite()
{
    //UnloadImage(image);
    //UnloadTexture(texture);
}

void Sprite::draw() const
{
    DrawTexture(texture, x, y, color);
}

float Sprite::getXPosition() const
{
    return (x);
}

float Sprite::getYPosition() const
{
    return (y);
}

int Sprite::getIndex() const
{
    return (index);
}

std::string Sprite::getPath() const
{
    return (path);
}


void Sprite::changePath(const std::string &path)
{
    this->path = path;
    const char *file = strToChar(path);
    image = LoadImage(file);
    texture = LoadTextureFromImage(image);
}

std::string Sprite::getScoreboardPath()
{
    if (path == "resources/img/a0.png") return ("resources/img/a00.png");
    if (path == "resources/img/a2.png") return ("resources/img/a222.png");
    if (path == "resources/img/a3.png") return ("resources/img/a33.png");
    if (path == "resources/img/a4.png") return ("resources/img/a44.png");
    if (path == "resources/img/a5.png") return ("resources/img/a55.png");
    if (path == "resources/img/a6.png") return ("resources/img/a66.png");
    if (path == "resources/img/a7.png") return ("resources/img/a77.png");
    if (path == "resources/img/a8.png") return ("resources/img/a88.png");
    if (path == "resources/img/a9.png") return ("resources/img/a99.png");
    if (path == "resources/img/a10.png") return ("resources/img/a100.png");
    return ("resources/img/a00.png");
}
