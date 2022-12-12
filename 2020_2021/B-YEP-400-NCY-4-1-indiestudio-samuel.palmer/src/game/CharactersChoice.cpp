/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** menu
*/

#include "CharactersChoice.hpp"

CharactersChoice::CharactersChoice(const std::string &name) : Scene(name)
{
    index1 = 0;
    index2 = 0;
    index3 = 0;
    index4 = 0;
    std::shared_ptr<_Sound> _sound(new _Sound("resources/audio/m3.ogg"));
    sound = _sound;
    sound->set_volume(0.2);
    addSkybox(1.0f, 1.0f, 1.0f, "resources/img/skybox.png");
    addMap();
    loadModelSkin();
    loadModel();
    loadButtonSprite();
    loadArtworkSprite();
    loadSound();
    generateDecor();
    addText("resources/fonts/font.ttf", "PLAYER 1", 50, 300, 40);
    addText("resources/fonts/font.ttf", "PLAYER 2", 460, 130, 40);
    addText("resources/fonts/font.ttf", "AI 1", 1230, 130, 40);
    addText("resources/fonts/font.ttf", "AI 2", 1700, 300, 40);
}

CharactersChoice::~CharactersChoice()
{
}

void CharactersChoice::loadModel()
{
    addModel("resources/models/steve/steve.iqm", skinList[0]);
    addModel("resources/models/steve/steve.iqm", skinList[0]);
    addModel("resources/models/steve/steve.iqm", skinList[0]);
    addModel("resources/models/steve/steve.iqm", skinList[0]);
    model[0]->set_pos(0.3, 12.8, 4);
    model[0]->set_angle(220);
    model[0]->set_axis(0.4, 2, 0);
    model[0]->blender_adjust();
    model[1]->set_pos(0.6, 12.8, 5.7);
    model[1]->set_angle(190);
    model[1]->set_axis(0.4, 2, 0);
    model[1]->blender_adjust();
    model[2]->set_pos(0.6, 12.8, 7.2);
    model[2]->set_angle(170);
    model[2]->set_axis(0.4, 2, 0);
    model[2]->blender_adjust();
    model[3]->set_pos(0.3, 12.8, 9.0);
    model[3]->set_angle(150);
    model[3]->set_axis(0.4, 2, 0);
    model[3]->blender_adjust();
}

void CharactersChoice::generateDecor()
{
    add_obj(floor_obj, floor_txt, Vector3{0.5, 0.5, 0.5}, Vector3{5, -1, 5}, 0);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, 16}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, 25}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{16, 0, 3}, 90);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, -3}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, -12}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{-3, 0, 5}, 90);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
}

void CharactersChoice::add_obj(std::string obj, std::string txt, Vector3 scale, Vector3 pos, int angle)
{
    addModel(obj, txt);
    model[model.size() - 1]->set_scale(scale);
    model[model.size() - 1]->set_pos(pos);
    model[model.size() - 1]->set_angle(angle);
}

void CharactersChoice::loadSound()
{
    soundList.push_back("resources/audio/m3.ogg");
    soundList.push_back("resources/audio/m2.ogg");
    soundList.push_back("resources/audio/m4.ogg");
    soundList.push_back("resources/audio/m5.ogg");
    soundList.push_back("resources/audio/m6.ogg");
    soundList.push_back("resources/audio/m7.ogg");
    soundList.push_back("resources/audio/m8.ogg");
    soundList.push_back("resources/audio/m9.ogg");
    soundList.push_back("resources/audio/m10.ogg");
    soundList.push_back("resources/audio/m1.ogg");
}

void CharactersChoice::loadModelSkin()
{
    skinList.push_back("resources/img/skin2.png");
    skinList.push_back("resources/img/skin.png");
    skinList.push_back("resources/img/skin3.png");
    skinList.push_back("resources/img/skin4.png");
    skinList.push_back("resources/img/skin5.png");
    skinList.push_back("resources/img/skin6.png");
    skinList.push_back("resources/img/skin7.png");
    skinList.push_back("resources/img/skin8.png");
    skinList.push_back("resources/img/skin9.png");
    skinList.push_back("resources/img/tupac.png");
}

void CharactersChoice::loadButtonSprite()
{
    addSprite("resources/img/left.png", 350, 500, RAYWHITE, 1);
    addSprite("resources/img/right.png", 400, 500, RAYWHITE, 2);
    addSprite("resources/img/left.png", 690, 400, RAYWHITE, 3);
    addSprite("resources/img/right.png", 740, 400, RAYWHITE, 4);
    addSprite("resources/img/left.png", 1010, 400, RAYWHITE, 5);
    addSprite("resources/img/right.png", 1060, 400, RAYWHITE, 6);
    addSprite("resources/img/left.png", 1370, 500, RAYWHITE, 7);
    addSprite("resources/img/right.png", 1420, 500, RAYWHITE, 8);
    addSprite("resources/img/back.png", 15, 40, RAYWHITE, 13);
    addSprite("resources/img/play.png", 885, 470, RAYWHITE, 14);
}

void CharactersChoice::loadArtworkSprite()
{
    addSprite("resources/img/a2.png", 260, 600, RAYWHITE, 9);
    addSprite("resources/img/a2.png", 600, 600, RAYWHITE, 10);
    addSprite("resources/img/a2.png", 980, 600, RAYWHITE, 11);
    addSprite("resources/img/a2.png", 1320, 600, RAYWHITE, 12);
    artworkList.push_back("resources/img/a2.png");
    artworkList.push_back("resources/img/a0.png");
    artworkList.push_back("resources/img/a3.png");
    artworkList.push_back("resources/img/a4.png");
    artworkList.push_back("resources/img/a6.png");
    artworkList.push_back("resources/img/a5.png");
    artworkList.push_back("resources/img/a7.png");
    artworkList.push_back("resources/img/a8.png");
    artworkList.push_back("resources/img/a10.png");
    artworkList.push_back("resources/img/a9.png");
}

void CharactersChoice::saveCharacter()
{
    sound->stop_sound();
    std::ofstream myfile;
    std::ofstream art;
    myfile.open ("saves/char.txt");
    art.open("saves/artwork.txt");
    myfile << model[0]->getTexture() << "\n";
    myfile << model[1]->getTexture() << "\n";
    myfile << model[2]->getTexture() << "\n";
    myfile << model[3]->getTexture() << "\n";
    myfile.close();
    for (size_t i = 0; i < sprite.size(); ++i) {
        if (sprite[i]->getIndex() == 9)
            art << sprite[i]->getScoreboardPath() << std::endl;
        if (sprite[i]->getIndex() == 10)
            art << sprite[i]->getScoreboardPath() << std::endl;
        if (sprite[i]->getIndex() == 11)
            art << sprite[i]->getScoreboardPath() << std::endl;
        if (sprite[i]->getIndex() == 12)
            art << sprite[i]->getScoreboardPath() << std::endl;
    }
    art.close();
    newscene = "game";
}

void CharactersChoice::animateButtons()
{
    for (size_t i = 0; i < sprite.size(); ++i) {
        if (sprite[i]->getIndex() == 5 || sprite[i]->getIndex() == 1 || sprite[i]->getIndex() == 3 || sprite[i]->getIndex() == 7) {
            if (event->hasMouseOnSprite(sprite[i], -10, 60, 0, 60) == true && sprite[i]->getPath() != "resources/img/left2.png")
                sprite[i]->changePath("resources/img/left2.png");
            else {
                if (event->hasMouseOnSprite(sprite[i], -10, 60, 0, 60) == false && sprite[i]->getPath() == "resources/img/left2.png")
                    sprite[i]->changePath("resources/img/left.png");
            }
        }
        if (sprite[i]->getIndex() == 2 || sprite[i]->getIndex() == 4 || sprite[i]->getIndex() == 6 || sprite[i]->getIndex() == 8) {
            if (event->hasMouseOnSprite(sprite[i], -60, 120, 50, 50) == true && sprite[i]->getPath() != "resources/img/right2.png")
                sprite[i]->changePath("resources/img/right2.png");
            else {
                if (event->hasMouseOnSprite(sprite[i], -60, 120, 50, 50) == false && sprite[i]->getPath() == "resources/img/right2.png")
                    sprite[i]->changePath("resources/img/right.png");
            }
        }
        if (sprite[i]->getIndex() == 14 && event->hasMouseOnSprite(sprite[i], -10, 100, 0, 80) == true && sprite[i]->getPath() != "resources/img/play2.png")
            sprite[i]->changePath("resources/img/play2.png");
        else {
            if (sprite[i]->getIndex() == 14 && event->hasMouseOnSprite(sprite[i], -10, 100, 0, 80) == false && sprite[i]->getPath() == "resources/img/play2.png")
                sprite[i]->changePath("resources/img/play.png");
        }
        if (sprite[i]->getIndex() == 13 && event->hasMouseOnSprite(sprite[i], -10, 100, 0, 80) == true && sprite[i]->getPath() != "resources/img/back2.png")
            sprite[i]->changePath("resources/img/back2.png");
        else {
            if (sprite[i]->getIndex() == 13 && event->hasMouseOnSprite(sprite[i], -10, 100, 0, 80) == false && sprite[i]->getPath() == "resources/img/back2.png")
                sprite[i]->changePath("resources/img/back.png");
        }
    }
}

void CharactersChoice::updateButton()
{
    if (event->hasClicked(MOUSE_LEFT_BUTTON) == true) {
        for (size_t i = 0; i < sprite.size(); ++i) {
            if (sprite[i]->getIndex() == 1 && event->hasClickOnSprite(sprite[i], -10, 60, 0, 60) == true && index1 > 0) {
                index1--;
                model[0]->load_texture(skinList[index1], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index1]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 2 && event->hasClickOnSprite(sprite[i], -60, 120, 50, 50) == true && index1 < 9) {
                index1++;
                model[0]->load_texture(skinList[index1], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index1]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 3 && event->hasClickOnSprite(sprite[i], -10, 60, 0, 60) == true && index2 > 0) {
                index2--;
                model[1]->load_texture(skinList[index2], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index2]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 4 && event->hasClickOnSprite(sprite[i], -60, 120, 50, 50) == true && index2 < 9) {
                index2++;
                model[1]->load_texture(skinList[index2], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index2]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 5 && event->hasClickOnSprite(sprite[i], -10, 60, 0, 60) == true && index3 > 0) {
                index3--;
                model[2]->load_texture(skinList[index3], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index3]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 6 && event->hasClickOnSprite(sprite[i], -60, 120, 50, 50) == true && index3 < 9) {
                index3++;
                model[2]->load_texture(skinList[index3], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index3]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 7 && event->hasClickOnSprite(sprite[i], -10, 60, 0, 60) == true && index4 > 0) {
                index4--;
                model[3]->load_texture(skinList[index4], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index4]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 8 && event->hasClickOnSprite(sprite[i], -60, 120, 50, 50) == true && index4 < 9) {
                index4++;
                model[3]->load_texture(skinList[index4], 0);
                sound->stop_sound();
                sound->changeSound(soundList[index4]);
                sound->play_sound();
            }
            if (sprite[i]->getIndex() == 9)
                sprite[i]->changePath(artworkList[index1]);
            if (sprite[i]->getIndex() == 10)
                sprite[i]->changePath(artworkList[index2]);
            if (sprite[i]->getIndex() == 11)
                sprite[i]->changePath(artworkList[index3]);
            if (sprite[i]->getIndex() == 12)
                sprite[i]->changePath(artworkList[index4]);
            if (sprite[i]->getIndex() == 14 && event->hasClickOnSprite(sprite[i], -10, 100, 0, 80) == true)
                saveCharacter();
            if (sprite[i]->getIndex() == 13 && event->hasClickOnSprite(sprite[i], -10, 100, 0, 80) == true) {
                newscene = "menu";
                sound->stop_sound();
            }
        }
    }
    animateButtons();
}

void CharactersChoice::updateScene()
{
    newscene = "none";
    updateButton();
    for (size_t i = 0; i < music.size(); ++i)
        music[i]->update_music();
}

void CharactersChoice::refresh()
{
    std::ifstream set ("saves/settings.txt");
    std::vector<std::string> v;
    std::string line;
    if (set.is_open()) {
        while (getline(set,line))
            v.push_back(line);
        set.close();
    }
    float vol = stoi(v[0]) / 40 - 0.1;
    sound->set_volume(vol);
}
