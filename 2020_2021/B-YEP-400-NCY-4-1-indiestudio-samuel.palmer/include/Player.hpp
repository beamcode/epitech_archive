/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <raylib.h>
#include <raymath.h>
#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <chrono>

#include "Bonus.hpp"
#include "Bomb.hpp"
#include "Model.hpp"

class Player : public _Model {
    public:
        Player(const std::string &obj, const std::string &texture);
        virtual ~Player();
        void movePlayerOne();
        void movePlayerTwo();
        bool canPlaceBomb();
        void hasPlacedBomb(std::shared_ptr<Bomb> bomb);
        float timeToBomb();
        bool hasBomb(std::shared_ptr<Bomb> bomb);
        void setTimeBomb(float time);
        bool check_collision(float pos_x, float pos_z);
        bool hasKilledPlayer(Vector3 pos, int i);
        void setGrid(std::vector<std::vector<int>> _grid);
        void setScore(int _score);
        bool isDead() const;
        Vector3 get_size() const;
        int getScore() const;
        virtual void moveIA();
        void play_animation(int i);
        bool anim_clock();
        void applyBonus(std::shared_ptr<Bonus> bonus);
        void bonusHasEnd();

    protected:
        std::shared_ptr<_Sound> sound;
        std::vector<std::vector<int>> grid;
        std::vector<std::shared_ptr<Bomb>> bombList;
        Vector3 p_size;
        float time;
        float time2;
        float time3;
        float time4;
        float move;
        bool dead;
        int score;
        float timeBomb;
        float timeBombSave;
        int timeBombCheck;
        std::vector<ModelAnimation *> anims;
        int anims_count;
        int animFrameCounter;
        std::chrono::system_clock::time_point lastRun;
        std::chrono::system_clock systemClock;
    private:
};

#endif /* !PLAYER_HPP_ */
