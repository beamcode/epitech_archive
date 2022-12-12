/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** options
*/

#include "Options.hpp"

Options::Options(const std::string &name) : Scene(name)
{
    this->volume = 40;
    this->time1 = 30;
    this->time2 = 30;
    addSkybox(1.0f, 1.0f, 1.0f, "resources/img/skybox.png");
    std::shared_ptr<_Sound> _sound(new _Sound("resources/audio/clic.wav"));
    sound = _sound;
    sound->set_volume(0.2);
    addMap();
    addMusic("resources/music/menu.ogg");
    addSprite("resources/img/fondflou.png", 0, 0, RAYWHITE, 1);
    addSprite("resources/img/back.png", 15, 40, RAYWHITE, 2);
    addText("resources/fonts/font.ttf", "VOLUME", 1650, 120, 50);
    addText("resources/fonts/font.ttf", "50 sec", 490, 370, 20);
    addText("resources/fonts/font.ttf", "40 sec", 550, 440, 20);
    addText("resources/fonts/font.ttf", "30 sec", 600, 510, 20);
    addText("resources/fonts/font.ttf", "20 sec", 650, 580, 20);
    addText("resources/fonts/font.ttf", "10 sec", 700, 640, 20);
    addText("resources/fonts/font.ttf", "Initial time range increase", 1100, 510, 40);
    addText("resources/fonts/font.ttf", "Delay between each time", 50, 820, 40);
    addText("resources/fonts/font.ttf", "decrease for bomb placements", 50, 900, 40);
    addText("resources/fonts/font.ttf", "50 sec", 1540, 610, 20);
    addText("resources/fonts/font.ttf", "40 sec", 1600, 680, 20);
    addText("resources/fonts/font.ttf", "30 sec", 1650, 750, 20);
    addText("resources/fonts/font.ttf", "20 sec", 1700, 820, 20);
    addText("resources/fonts/font.ttf", "10 sec", 1750, 880, 20);
    addSprite("resources/img/Options/40.png", 1250, 10, RAYWHITE, 3);
    addSprite("resources/img/Options/60.png", 1250, 560, RAYWHITE, 4);
    addSprite("resources/img/Options/60.png", 200, 320, RAYWHITE, 5);
    addSprite("resources/img/Options/plus.png", 1100, 20, RAYWHITE, 6);
    addSprite("resources/img/Options/moins.png", 1100, 180, RAYWHITE, 7);
    addSprite("resources/img/Options/plus.png", 60, 330, RAYWHITE, 8);
    addSprite("resources/img/Options/moins.png", 60, 490, RAYWHITE, 9);
    addSprite("resources/img/Options/plus.png", 1100, 600, RAYWHITE, 10);
    addSprite("resources/img/Options/moins.png", 1100, 760, RAYWHITE, 11);
}

Options::~Options()
{

}

Vector2 get_pos()
{
    Vector2 p;
    p = GetMousePosition();
    return (p);
}

bool check_within(int xmin, int xmax, int ymin, int ymax)
{
    Vector2 pos = get_pos();

    if ((pos.x >= xmin && pos.x <=xmax) && (pos.y >= ymin && pos.y <= ymax))
        return (true);
    return (false);
}

void Options::updateButton()
{
    if (event->hasClicked(MOUSE_LEFT_BUTTON) == true) {
        for (size_t i = 0; i < sprite.size(); ++i) {
            if (sprite[i]->getIndex() == 2 && event->hasClickOnSprite(sprite[i], -10, 100, 0, 80) == true)
                newscene = "menu";
            if (sprite[i]->getIndex() == 6 && check_within(1100, 1220, 20, 140) == true) {
                if (this->volume == 0)
                    sprite[2]->changePath("resources/img/Options/20.png");
                if (this->volume == 20)
                    sprite[2]->changePath("resources/img/Options/40.png");
                if (this->volume == 40)
                    sprite[2]->changePath("resources/img/Options/60.png");
                if (this->volume == 60)
                    sprite[2]->changePath("resources/img/Options/80.png");
                if (this->volume == 80)
                    sprite[2]->changePath("resources/img/Options/100.png");
                if (this->volume <= 80) {
                    this->volume += 20;
                    writeInFile();
                }
            }
            if (sprite[i]->getIndex() == 7 && check_within(1100, 1220, 180, 300) == true) {
                if (this->volume == 100)
                    sprite[2]->changePath("resources/img/Options/80.png");
                if (this->volume == 80)
                    sprite[2]->changePath("resources/img/Options/60.png");
                if (this->volume == 60)
                    sprite[2]->changePath("resources/img/Options/40.png");
                if (this->volume == 40)
                    sprite[2]->changePath("resources/img/Options/20.png");
                if (this->volume == 20)
                    sprite[2]->changePath("resources/img/Options/0.png");
                if (this->volume >= 20) {
                    this->volume -= 20;
                    writeInFile();
                }
            }

            if (sprite[i]->getIndex() == 8 && check_within(60, 180, 330, 450) == true) {
                if (this->time1 == 0)
                    sprite[4]->changePath("resources/img/Options/20.png");
                if (this->time1 == 10)
                    sprite[4]->changePath("resources/img/Options/40.png");
                if (this->time1 == 20)
                    sprite[4]->changePath("resources/img/Options/60.png");
                if (this->time1 == 30)
                    sprite[4]->changePath("resources/img/Options/80.png");
                if (this->time1 == 40)
                    sprite[4]->changePath("resources/img/Options/100.png");
                if (this->time1 <= 40) {
                    this->time1 += 10;
                    writeInFile();
                }
            }
            if (sprite[i]->getIndex() == 9 && check_within(60, 180, 490, 610) == true) {
                if (this->time1 == 50)
                    sprite[4]->changePath("resources/img/Options/80.png");
                if (this->time1 == 40)
                    sprite[4]->changePath("resources/img/Options/60.png");
                if (this->time1 == 30)
                    sprite[4]->changePath("resources/img/Options/40.png");
                if (this->time1 == 20)
                    sprite[4]->changePath("resources/img/Options/20.png");
                if (this->time1 == 10)
                    sprite[4]->changePath("resources/img/Options/0.png");
                if (this->time1 >= 10) {
                    this->time1 -= 10;
                    writeInFile();
                }
            }

            if (sprite[i]->getIndex() == 10 && check_within(1100, 1220, 600, 720) == true) {
                if (this->time2 == 0)
                    sprite[3]->changePath("resources/img/Options/20.png");
                if (this->time2 == 10)
                    sprite[3]->changePath("resources/img/Options/40.png");
                if (this->time2 == 20)
                    sprite[3]->changePath("resources/img/Options/60.png");
                if (this->time2 == 30)
                    sprite[3]->changePath("resources/img/Options/80.png");
                if (this->time2 == 40)
                    sprite[3]->changePath("resources/img/Options/100.png");
                if (this->time2 <= 40)
                    this->time2 += 10;
            }
            if (sprite[i]->getIndex() == 11 && check_within(1100, 1220, 760, 880) == true) {
                if (this->time2 == 50)
                    sprite[3]->changePath("resources/img/Options/80.png");
                if (this->time2 == 40)
                    sprite[3]->changePath("resources/img/Options/60.png");
                if (this->time2 == 30)
                    sprite[3]->changePath("resources/img/Options/40.png");
                if (this->time2 == 20)
                    sprite[3]->changePath("resources/img/Options/20.png");
                if (this->time2 == 10)
                    sprite[3]->changePath("resources/img/Options/0.png");
                if (this->time2 >= 10) {
                    this->time2 -= 10;
                    writeInFile();
                }
            }
        }
        sound->play_sound();
    }

    for (size_t i = 0; i < sprite.size(); ++i) {          //parcours tout les sprite de la fenetre
        if (sprite[i]->getIndex() == 2 && event->hasMouseOnSprite(sprite[i], -10, 100, 0, 80) == true && sprite[i]->getPath() != "resources/img/back2.png") //si la souris passe par dessus le sprite
            sprite[i]->changePath("resources/img/back2.png");                             //change la texture du sprite si la souris passe par dessus
        else {
            if (sprite[i]->getIndex() == 2 && event->hasMouseOnSprite(sprite[i], -10, 100, 0, 80) == false && sprite[i]->getPath() == "resources/img/back2.png")  //si la souris est plus sur le sprite
                sprite[i]->changePath("resources/img/back.png");          //remet la texture de base du sprite
        }
        if (sprite[i]->getIndex() == 6 && check_within(1100, 1220, 20, 140) == true && sprite[i]->getPath() != "resources/img/Options/plus2.png")
            sprite[i]->changePath("resources/img/Options/plus2.png");
        else {
            if (sprite[i]->getIndex() == 6 && check_within(1100, 1220, 20, 140) == false && sprite[i]->getPath() == "resources/img/Options/plus2.png")
                sprite[i]->changePath("resources/img/Options/plus.png");
        }
        if (sprite[i]->getIndex() == 7 && check_within(1100, 1220, 180, 300) == true && sprite[i]->getPath() != "resources/img/Options/moins2.png")
            sprite[i]->changePath("resources/img/Options/moins2.png");
        else {
            if (sprite[i]->getIndex() == 7 && check_within(1100, 1220, 180, 300) == false && sprite[i]->getPath() == "resources/img/Options/moins2.png")
                sprite[i]->changePath("resources/img/Options/moins.png");
        }

        if (sprite[i]->getIndex() == 8 && check_within(60, 180, 330, 450) == true && sprite[i]->getPath() != "resources/img/Options/plus2.png")
            sprite[i]->changePath("resources/img/Options/plus2.png");
        else {
            if (sprite[i]->getIndex() == 8 && check_within(60, 180, 330, 450) == false && sprite[i]->getPath() == "resources/img/Options/plus2.png")
                sprite[i]->changePath("resources/img/Options/plus.png");
        }
        if (sprite[i]->getIndex() == 9 && check_within(60, 180, 490, 610) == true && sprite[i]->getPath() != "resources/img/Options/moins2.png")
            sprite[i]->changePath("resources/img/Options/moins2.png");
        else {
            if (sprite[i]->getIndex() == 9 && check_within(60, 180, 490, 610) == false && sprite[i]->getPath() == "resources/img/Options/moins2.png")
                sprite[i]->changePath("resources/img/Options/moins.png");
        }

        if (sprite[i]->getIndex() == 10 && check_within(1100, 1220, 600, 720) == true && sprite[i]->getPath() != "resources/img/Options/plus2.png")
            sprite[i]->changePath("resources/img/Options/plus2.png");
        else {
            if (sprite[i]->getIndex() == 10 && check_within(1100, 1220, 600, 720) == false && sprite[i]->getPath() == "resources/img/Options/plus2.png")
                sprite[i]->changePath("resources/img/Options/plus.png");
        }
        if (sprite[i]->getIndex() == 11 && check_within(1100, 1220, 760, 880) == true && sprite[i]->getPath() != "resources/img/Options/moins2.png")
            sprite[i]->changePath("resources/img/Options/moins2.png");
        else {
            if (sprite[i]->getIndex() == 11 && check_within(1100, 1220, 760, 880) == false && sprite[i]->getPath() == "resources/img/Options/moins2.png")
                sprite[i]->changePath("resources/img/Options/moins.png");
        }
    }
}

void Options::writeInFile()
{
    std::ofstream myfile;
    myfile.open ("saves/settings.txt");
    myfile << volume << std::endl;
    myfile << time1 << std::endl;
    myfile << time2 << std::endl;
    myfile.close();
    float vol = volume / 40 - 0.1;
    sound->set_volume(vol);
}

void Options::updateScene()
{
    newscene = "none";
    updateButton();
    for (size_t i = 0; i < music.size(); ++i)
        music[i]->update_music();
}

void Options::refresh() {}
