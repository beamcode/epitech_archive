/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** menu
*/


#include "Menu.hpp"

Menu::Menu(const std::string &name, std::shared_ptr<Save> save) : Scene(name, save)
{
    addMusic("resources/audio/menut.ogg");
    addSkybox(1.0f, 1.0f, 1.0f, "resources/img/skybox.png");
    addMap();
    addSprite("resources/img/fond2.png", 0, 0, RAYWHITE, 5);
    addSprite("resources/img/logo.png", 800, 50, RAYWHITE, 5);
    addSprite("resources/img/dababy.png", 370, 300, RAYWHITE, 5);
    addSprite("resources/img/b.png", 100, 100, RAYWHITE, 1);
    addSprite("resources/img/a.png", 100, 200, RAYWHITE, 2);
    addSprite("resources/img/c.png", 100, 300, RAYWHITE, 3);
    addSprite("resources/img/d.png", 100, 400, RAYWHITE, 4);
}

Menu::~Menu()
{
}

void Menu::animateButtons()
{
    for (size_t i = 0; i < sprite.size(); ++i) {
        if (sprite[i]->getIndex() == 1 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == true && sprite[i]->getPath() != "resources/img/b2.png")
            sprite[i]->changePath("resources/img/b2.png");
        else {
            if (sprite[i]->getIndex() == 1 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == false && sprite[i]->getPath() == "resources/img/b2.png")
                sprite[i]->changePath("resources/img/b.png");
        }
        if (sprite[i]->getIndex() == 2 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == true && sprite[i]->getPath() != "resources/img/a22.png")
            sprite[i]->changePath("resources/img/a22.png");
        else {
            if (sprite[i]->getIndex() == 2 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == false && sprite[i]->getPath() == "resources/img/a22.png")
                sprite[i]->changePath("resources/img/a.png");
        }
        if (sprite[i]->getIndex() == 3 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == true && sprite[i]->getPath() != "resources/img/c2.png")
            sprite[i]->changePath("resources/img/c2.png");
        else {
            if (sprite[i]->getIndex() == 3 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == false && sprite[i]->getPath() == "resources/img/c2.png")
                sprite[i]->changePath("resources/img/c.png");
        }
        if (sprite[i]->getIndex() == 4 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == true && sprite[i]->getPath() != "resources/img/d2.png")
            sprite[i]->changePath("resources/img/d2.png");
        else {
            if (sprite[i]->getIndex() == 4 && event->hasMouseOnSprite(sprite[i], -10, 280, 0, 80) == false && sprite[i]->getPath() == "resources/img/d2.png")
                sprite[i]->changePath("resources/img/d.png");
        }
    }
}

void Menu::updateButton()
{
    if (event->hasClicked(MOUSE_LEFT_BUTTON) == true) {
        for (size_t i = 0; i < sprite.size(); ++i) {
            if (sprite[i]->getIndex() == 4 && event->hasClickOnSprite(sprite[i], -10, 280, 0, 80) == true)
                close = true;
            if (sprite[i]->getIndex() == 2 && event->hasClickOnSprite(sprite[i], -10, 280, 0, 80) == true) {
                save->loadSave();
                newscene = "game";
            }
            if (sprite[i]->getIndex() == 1 && event->hasClickOnSprite(sprite[i], -10, 280, 0, 80) == true)
                newscene = "choice";
            if (sprite[i]->getIndex() == 3 && event->hasClickOnSprite(sprite[i], -10, 280, 0, 80) == true)
                newscene = "options";
        }
    }
    animateButtons();
}

void Menu::updateScene()
{
    newscene = "none";
    updateButton();
    for (size_t i = 0; i < music.size(); ++i)
        music[i]->update_music();
}

void Menu::refresh()
{
    std::ifstream set ("saves/settings.txt");
    std::string line;
    std::vector<std::string> v;
    if (set.is_open()) {
        while (getline(set,line))
            v.push_back(line);
        set.close();
    }
    float vol = stoi(v[0]) / 40 - 0.1;
    music[0]->set_volume(vol);
}
