/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** music
*/

#include "Scene.hpp"

Scene::Scene(const std::string &_name)
{
    name = _name;
    std::shared_ptr<Event> _event(new Event());
    event = _event;
    close = false;
    newscene = "none";
}

Scene::Scene(const std::string &_name, std::shared_ptr<Save> _save)
{
    name = _name;
    std::shared_ptr<Event> _event(new Event());
    event = _event;
    close = false;
    newscene = "none";
    save = _save;
}

Scene::~Scene()
{
}

std::string Scene::getName() const
{
    return (name);
}

void Scene::addModel(const std::string &a, const std::string &b)
{
    std::shared_ptr<_Model> _model(new _Model(a, b));
    model.push_back(_model);
}

void Scene::addSkybox(float width, float height, float lenght, const std::string &path)
{
    std::shared_ptr<_Skybox> _skybox(new _Skybox(width, height, lenght, path));
    skybox.push_back(_skybox);
}

void Scene::addSprite(const std::string &path, int x, int y, Color color, int index)
{
    std::shared_ptr<Sprite> _sprite(new Sprite(path, x, y, color, index));
    sprite.push_back(_sprite);
}

void Scene::addMap()
{
    std::shared_ptr<_Map> _map(new _Map());
    this->map = _map;
}

void Scene::addMusic(const std::string &path)
{
    std::shared_ptr<_Music> _music(new _Music(path));
    _music->set_volume(0.5f);
    _music->play_music();
    music.push_back(_music);
}

void Scene::addText(const std::string &fontPath, const std::string &txt, float x, float y, int fontSize)
{
    std::shared_ptr<Text> _text(new Text(fontPath, txt, x, y, fontSize));
    text.push_back(_text);
}

void Scene::drawScene3d() const
{
    for (size_t i = 0; i < skybox.size(); ++i)
        skybox[i]->draw();
    map->draw();
    for (size_t i = 0; i < model.size(); ++i)
        model[i]->draw();
}

void Scene::drawScene2d() const
{
    for (size_t i = 0; i < sprite.size(); ++i)
        sprite[i]->draw();
    for (size_t i = 0; i < text.size(); ++i)
        text[i]->drawText();
    for (size_t i = 0; i < sc.size(); ++i)
        sc[i]->draw();
}

std::string Scene::changeScene() const
{
    return (newscene);
}

bool Scene::isClosed() const
{
    return (close);
}
