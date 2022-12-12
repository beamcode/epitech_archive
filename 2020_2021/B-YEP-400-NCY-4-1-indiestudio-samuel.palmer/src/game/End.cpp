/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** End
*/

#include "End.hpp"

End::End(const std::string &name) : Scene(name)
{
    addSkybox(1.0f, 1.0f, 1.0f, "resources/img/skybox.png");
    addMap();
    addModel("resources/models/steve/steve.obj", "resources/models/steve/skin.png");
    model[0]->set_pos(-1.8, 14, 7);
    model[0]->set_angle(180);
    model[0]->set_axis(0.7, 2, 0);
    generateDecor();
}

End::~End()
{
}

void End::generateDecor()
{
    addModel("resources/models/floor.obj", "resources/img/floor.png");
    model[model.size() - 1]->set_scale(0.5, 0.5, 0.5);
    model[model.size() - 1]->set_pos(5, -1, 5);
    addModel("resources/models/palm.obj", "resources/img/palm_trunk.png");
    model[model.size() - 1]->load_texture("resources/img/palm_leaves.png", 1);
    model[model.size() - 1]->set_scale(0.6, 0.6, 0.6);
    model[model.size() - 1]->set_pos(5, 0, 16);
    addModel("resources/models/palm.obj", "resources/img/palm_trunk.png");
    model[model.size() - 1]->load_texture("resources/img/palm_leaves.png", 1);
    model[model.size() - 1]->set_scale(0.6, 0.6, 0.6);
    model[model.size() - 1]->set_pos(5, 0, 25);
    addModel("resources/models/palm.obj", "resources/img/palm_trunk.png");
    model[model.size() - 1]->load_texture("resources/img/palm_leaves.png", 1);
    model[model.size() - 1]->set_scale(0.6, 0.6, 0.6);
    model[model.size() - 1]->set_pos(16, 0, 3);
    model[model.size() - 1]->set_angle(90);
    addModel("resources/models/palm.obj", "resources/img/palm_trunk.png");
    model[model.size() - 1]->load_texture("resources/img/palm_leaves.png", 1);
    model[model.size() - 1]->set_scale(0.6, 0.6, 0.6);
    model[model.size() - 1]->set_pos(5, 0, -3);
    addModel("resources/models/palm.obj", "resources/img/palm_trunk.png");
    model[model.size() - 1]->load_texture("resources/img/palm_leaves.png", 1);
    model[model.size() - 1]->set_scale(0.6, 0.6, 0.6);
    model[model.size() - 1]->set_pos(5, 0, -12);
    addModel("resources/models/palm.obj", "resources/img/palm_trunk.png");
    model[model.size() - 1]->load_texture("resources/img/palm_leaves.png", 1);
    model[model.size() - 1]->set_scale(0.6, 0.6, 0.6);
    model[model.size() - 1]->set_pos(-3, 0, 5);
    model[model.size() - 1]->set_angle(90);
}

void End::loadSound(std::vector<std::string> txt)
{
    std::string sound;
    if (txt[1] == "resources/img/a00.png") { txt[1] = "resources/img/a0.png"; sound = "resources/audio/m2.ogg"; }
    if (txt[1] == "resources/img/a222.png") { txt[1] = "resources/img/a2.png"; sound = "resources/audio/m3.ogg"; }
    if (txt[1] == "resources/img/a33.png") { txt[1] = "resources/img/a3.png"; sound = "resources/audio/m4.ogg"; }
    if (txt[1] == "resources/img/a44.png") { txt[1] = "resources/img/a4.png"; sound = "resources/audio/m5.ogg"; }
    if (txt[1] == "resources/img/a55.png") { txt[1] = "resources/img/a5.png"; sound = "resources/audio/m7.ogg"; }
    if (txt[1] == "resources/img/a66.png") { txt[1] = "resources/img/a6.png"; sound = "resources/audio/m6.ogg"; }
    if (txt[1] == "resources/img/a77.png") { txt[1] = "resources/img/a7.png"; sound = "resources/audio/m8.ogg"; }
    if (txt[1] == "resources/img/a88.png") { txt[1] = "resources/img/a8.png"; sound = "resources/audio/m9.ogg"; }
    if (txt[1] == "resources/img/a99.png") { txt[1] = "resources/img/a9.png"; sound = "resources/audio/m1.ogg"; }
    if (txt[1] == "resources/img/a100.png") { txt[1] = "resources/img/a10.png"; sound = "resources/audio/m10.ogg"; }
    addSprite(txt[1], 530, 350, RAYWHITE, 2);
    addSprite("resources/img/winner.png", 1100, 0, RAYWHITE, 2);
    addSprite("resources/img/winner.png", 200, 0, RAYWHITE, 2);
    addSprite("resources/img/score1.png", 750, 0, RAYWHITE, 2);
    addMusic(sound);
    music[0]->set_volume(0.4);
    music[0]->play_music();
}

void End::openFile()
{
    std::vector<std::string> txt;
    std::string line;
    std::ifstream myfile ("saves/winner.txt");
    if (myfile.is_open()) {
        while (getline(myfile,line))
            txt.push_back(line);
        myfile.close();
    }
    model[0]->load_texture(txt[0], 0);
    addText("resources/fonts/font.otf", txt[2], 920, 140, 40);
    if (txt[3] == "0")
        addText("resources/fonts/font.otf", "Player 1", 820, 60, 70);
    if (txt[3] == "1")
        addText("resources/fonts/font.otf", "Player 2", 820, 60, 70);
    if (txt[3] == "2")
        addText("resources/fonts/font.otf", "IA 1", 820, 60, 70);
    if (txt[3] == "3")
        addText("resources/fonts/font.otf", "IA 2", 820, 60, 70);
    loadSound(txt);
}

void End::updateScene()
{
    newscene = "none";
    for (size_t i = 0; i < music.size(); ++i)
        music[i]->update_music();
    if (time + 10 < GetTime() || time == 0)
        close = true;
}

void End::refresh()
{
    time = GetTime();
    openFile();
}
