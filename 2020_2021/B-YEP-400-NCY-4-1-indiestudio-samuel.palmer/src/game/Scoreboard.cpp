/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Scoreboard
*/

#include "Scoreboard.hpp"

Scoreboard::Scoreboard()
{

}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::playerOne()
{
    std::shared_ptr<Text> text(new Text("resources/fonts/font.ttf", "0", 480, 680, 20));
    timeList.push_back(text);
    std::shared_ptr<Text> text3(new Text("resources/fonts/font.ttf", "Player 1", 450, 600, 30));
    std::shared_ptr<Text> text5(new Text("resources/fonts/font.ttf", "0000", 480, 740, 20));
    textList.push_back(text);
    textList.push_back(text3);
    textList.push_back(text5);
    scoreList.push_back(text5);
    std::shared_ptr<Sprite> sprite(new Sprite("resources/img/a00.png", 250, 620, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite5(new Sprite("resources/img/mbomb.png", 400, 660, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite6(new Sprite("resources/img/star.png", 420, 720, RAYWHITE, 9));
    spriteList.push_back(sprite);
    spriteList.push_back(sprite5);
    spriteList.push_back(sprite6);
}

void Scoreboard::playerTwo()
{
    std::shared_ptr<Text> text2(new Text("resources/fonts/font.ttf", "0", 1240, 160, 20));
    timeList.push_back(text2);
    std::shared_ptr<Text> text4(new Text("resources/fonts/font.ttf", "Player 2", 1240, 80, 30));
    std::shared_ptr<Text> text5(new Text("resources/fonts/font.ttf", "0000", 1300, 220, 20));
    scoreList.push_back(text5);
    textList.push_back(text2);
    textList.push_back(text4);
    textList.push_back(text5);
    std::shared_ptr<Sprite> sprite3(new Sprite("resources/img/mbomb.png", 1330, 140, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite2(new Sprite("resources/img/a00.png", 1420, 90, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite6(new Sprite("resources/img/star.png", 1350, 200, RAYWHITE, 9));
    spriteList.push_back(sprite2);
    spriteList.push_back(sprite3);
    spriteList.push_back(sprite6);
}

void Scoreboard::playerThree()
{
    std::shared_ptr<Text> text2(new Text("resources/fonts/font.ttf", "0", 1340, 680, 20));
    timeList.push_back(text2);
    std::shared_ptr<Text> text5(new Text("resources/fonts/font.ttf", "IA 1", 1350, 600, 30));
    std::shared_ptr<Text> text6(new Text("resources/fonts/font.ttf", "0000", 1400, 740, 20));
    scoreList.push_back(text6);
    textList.push_back(text2);
    textList.push_back(text5);
    textList.push_back(text6);
    std::shared_ptr<Sprite> sprite4(new Sprite("resources/img/a00.png", 1520, 620, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite3(new Sprite("resources/img/mbomb.png", 1430, 660, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite6(new Sprite("resources/img/star.png", 1450, 720, RAYWHITE, 9));
    spriteList.push_back(sprite4);
    spriteList.push_back(sprite3);
    spriteList.push_back(sprite6);
}

void Scoreboard::playerFour()
{
    std::shared_ptr<Text> text2(new Text("resources/fonts/font.ttf", "0", 580, 160, 20));
    timeList.push_back(text2);
    std::shared_ptr<Text> text5(new Text("resources/fonts/font.ttf", "IA 2", 550, 80, 30));
    std::shared_ptr<Text> text6(new Text("resources/fonts/font.ttf", "0000", 580, 220, 20));
    scoreList.push_back(text6);
    textList.push_back(text2);
    textList.push_back(text5);
    textList.push_back(text6);
    std::shared_ptr<Sprite> sprite3(new Sprite("resources/img/mbomb.png", 500, 140, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite4(new Sprite("resources/img/a00.png", 350, 90, RAYWHITE, 9));
    std::shared_ptr<Sprite> sprite6(new Sprite("resources/img/star.png", 520, 200, RAYWHITE, 9));
    spriteList.push_back(sprite4);
    spriteList.push_back(sprite3);
    spriteList.push_back(sprite6);
}

void Scoreboard::changeArtwork(const std::string &artwork)
{
    spriteList[0]->changePath(artwork);
}

void Scoreboard::draw() const
{
    for (size_t i = 0; i < textList.size(); ++i)
        textList[i]->drawText();
    for (size_t i = 0; i < spriteList.size(); ++i)
        spriteList[i]->draw();
}

void Scoreboard::update(float time, int _score)
{
    std::string str = std::to_string(time);
    std::string score = std::to_string(_score);
    timeList[0]->updateText(str);
    scoreList[0]->updateText(score);
}
