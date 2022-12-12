/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Scoreboard
*/

#ifndef SCOREBOARD_HPP_
#define SCOREBOARD_HPP_

#include <raylib.h>
#include <raymath.h>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

#include "Sprite.hpp"
#include "Text.hpp"

class Scoreboard {
  public:
    Scoreboard();
    ~Scoreboard();
    void playerOne();
    void playerTwo();
    void playerThree();
    void playerFour();
    void changeArtwork(const std::string &artwork);
    void draw() const;
    void update(float time, int _score);

  private:
    std::vector<std::shared_ptr<Text>> textList;
    std::vector<std::shared_ptr<Text>> timeList;
    std::vector<std::shared_ptr<Text>> scoreList;
    std::vector<std::shared_ptr<Sprite>> spriteList;
};

#endif /* !SCOREBOARD_HPP_ */
