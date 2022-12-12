/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include <memory>
#include <vector>
#include <string>
#include "Player.hpp"

class Game;

class Save {
  public:
    Save(std::shared_ptr<Game>);
    ~Save();

    void loadSave();
    void fillSave();

  private:
    std::shared_ptr<Game> game;
};

#endif /* !SAVE_HPP_ */
#include "Game.hpp"
