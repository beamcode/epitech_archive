/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** model
*/


#include "Player.hpp"

Player::Player(const std::string &obj, const std::string &_texture) : _Model(obj, _texture)
{
    time = 0;
    lastRun = systemClock.now();
    move = 0.05f;
    dead = false;
    score = 0;
    timeBomb = 3;
    timeBombSave = 3;
    timeBombCheck = 0;
    std::shared_ptr<_Sound> _sound(new _Sound("resources/audio/death.ogg"));
    sound = _sound;
    sound->set_volume(0.8);
    p_size = {0.45f, 0.45f, 0.45f};
    scale = {0.25f, 0.25f, 0.25f};

    model.transform = MatrixRotateX( (PI * 2) / 4 );
    anims_count = 0;
    animFrameCounter = 0;
    anims.push_back(LoadModelAnimations("resources/models/steve/steve_idle.iqm", &anims_count));
    anims.push_back(LoadModelAnimations("resources/models/steve/steve_run.iqm", &anims_count));
}

Player::~Player()
{
}

void Player::setGrid(std::vector<std::vector<int>> _grid)
{
    grid = _grid;
}

bool Player::check_collision(float pos_x, float pos_z)
{
    float scale_x = (p_size.x / 2);
    float scale_z = (p_size.z / 2);
    std::pair<int, int> up_left = {static_cast<int>(pos_z + scale_z), static_cast<int>(pos_x - scale_x)};
    std::pair<int, int> up_right = {static_cast<int>(pos_z + scale_z), static_cast<int>(pos_x + scale_x)};
    std::pair<int, int> down_left = {static_cast<int>(pos_z - scale_z), static_cast<int>(pos_x - scale_x)};
    std::pair<int, int> down_right = {static_cast<int>(pos_z - scale_z), static_cast<int>(pos_x + scale_x)};

    if (grid.at(up_right.first).at(up_right.second) == 1 ||
        grid.at((up_right.first)).at((up_right.second)) == 4 ||
        grid.at((down_right.first)).at((down_right.second)) == 1 ||
        grid.at((down_right.first)).at((down_right.second)) == 4)
        return (false);
    else if (grid.at((up_left.first)).at((up_left.second)) == 1 ||
        grid.at((up_left.first)).at((up_left.second)) == 4 ||
        grid.at((down_left.first)).at((down_left.second)) == 1 ||
        grid.at((down_left.first)).at((down_left.second)) == 4)
        return (false);
    else if (grid.at((up_left.first)).at((up_left.second)) == 1 ||
        grid.at((up_left.first)).at((up_left.second)) == 4 ||
        grid.at((up_right.first)).at((up_right.second)) == 1 ||
        grid.at((up_right.first)).at((up_right.second)) == 4)
        return (false);
    else if (grid.at((down_left.first)).at((down_left.second)) == 1 ||
        grid.at((down_left.first)).at((down_left.second)) == 4 ||
        grid.at((down_right.first)).at((down_right.second)) == 1 ||
        grid.at((down_right.first)).at((down_right.second)) == 4)
        return (false);
    return (true);
}

void Player::movePlayerOne()
{
    float angle = -1.0f;
    if (IsKeyDown(KEY_RIGHT)) {
        angle = 270.0f;
        if (check_collision(position.x, position.z + move))
            position.z += move;
    }
    if (IsKeyDown(KEY_DOWN)) {
        angle = 180.0f;
        if (check_collision(position.x - move, position.z))
            position.x -= move;
    }
    if (IsKeyDown(KEY_LEFT)) {
        angle = 90.0f;
        if (check_collision(position.x, position.z - move))
            position.z -= move;
    }
    if (IsKeyDown(KEY_UP)) {
        angle = 0.0f;
        if (check_collision(position.x + move, position.z))
            position.x += move;
    }
    if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_UP)) angle = 40.0f;
    if (IsKeyDown(KEY_LEFT) && IsKeyDown(KEY_DOWN)) angle = 130.0f;
    if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_DOWN)) angle = 220.0f;
    if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_UP)) angle = 310.0f;
    if (angle > -1.0f)
        set_angle(angle);
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_UP))
        play_animation(1);
    else
        play_animation(0);
}

void Player::movePlayerTwo()
{
    float angle = -1.0f;
    if (IsKeyDown(KEY_D)) {
        angle = 270.0f;
        if (check_collision(position.x, position.z + move))
            position.z += move;
    }
    if (IsKeyDown(KEY_S)) {
        angle = 180.0f;
        if (check_collision(position.x - move, position.z))
            position.x -= move;
    }
    if (IsKeyDown(KEY_A)) {
        angle = 90.0f;
        if (check_collision(position.x, position.z - move))
            position.z -= move;
    }
    if (IsKeyDown(KEY_W)) {
        angle = 0.0f;
        if (check_collision(position.x + move, position.z))
            position.x += move;
    }
    if (IsKeyDown(KEY_D) && IsKeyDown(KEY_W)) angle = 310.0f;
    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W)) angle = 40.0f;
    if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S)) angle = 130.0f;
    if (IsKeyDown(KEY_D) && IsKeyDown(KEY_S)) angle = 220.0f;
    if (angle > -1.0f)
        set_angle(angle);
    if (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_S) || IsKeyDown(KEY_D))
        play_animation(1);
    else
        play_animation(0);
}

bool Player::hasKilledPlayer(Vector3 pos, int i)
{
    if (dead == true)
        return (false);
    if (static_cast<int>(pos.z) == static_cast<int>(position.z) && static_cast<int>(pos.x) == static_cast<int>(position.x)) {
        dead = true;
        sound->play_sound();
        return (true);
    }
    if ((pos.z + i) < 13) {
        if (static_cast<int>(pos.z + i) == static_cast<int>(position.z) && static_cast<int>(pos.x) == static_cast<int>(position.x)) {
            dead = true;
            sound->play_sound();
            return (true);
        }
    }
    if ((pos.z - i) > 0) {
        if (static_cast<int>(pos.z - i) == static_cast<int>(position.z) && static_cast<int>(pos.x) == static_cast<int>(position.x)) {
            dead = true;
            sound->play_sound();
            return (true);
        }
    }
    if ((pos.x + i) < 13) {
        if (static_cast<int>(pos.x + i) == static_cast<int>(position.x) && static_cast<int>(pos.z) == static_cast<int>(position.z)) {
            dead = true;
            sound->play_sound();
            return (true);
        }
    }
    if ((pos.x - i) > 0) {
        if (static_cast<int>(pos.x - i) == static_cast<int>(position.x) && static_cast<int>(pos.z) == static_cast<int>(position.z)) {
            dead = true;
            sound->play_sound();
            return (true);
        }
    }
    return (false);
}

void Player::bonusHasEnd()
{
    if (time3 + 7 < GetTime())
        move = 0.05f;
    if (time4 + 7 < GetTime()) {
        timeBomb = timeBombSave;
        timeBombCheck = 0;
    }
}

void Player::applyBonus(std::shared_ptr<Bonus> bonus)
{
    if (bonus->getIndex() == 1) {
        time3 = GetTime();
        move = 0.08f;
        score += 100;
    }
    if (bonus->getIndex() == 2 && timeBombCheck == 0) {
        time4 = GetTime();
        timeBombSave = timeBomb;
        timeBombCheck = 1;
        if (timeBomb > 0.5)
            timeBomb -= 0.5;
        score += 100;
    }
}

void Player::setScore(int _score)
{
    score += _score;
}

void Player::setTimeBomb(float time)
{
    timeBomb = time;
    timeBombSave = timeBomb;
}

void Player::hasPlacedBomb(std::shared_ptr<Bomb> bomb)
{
    time = GetTime();
    bombList.push_back(bomb);
}

bool Player::canPlaceBomb()
{
    if (time + timeBomb < GetTime() || time == 0)
        return (true);
    return (false);
}

float Player::timeToBomb()
{
    if (canPlaceBomb() == true)
        return (0);
    else
        return (time + timeBomb - GetTime());
}

bool Player::hasBomb(std::shared_ptr<Bomb> bomb)
{
    for (size_t i = 0; i < bombList.size(); i++) {
        if (bomb->getIndex() == bombList[i]->getIndex())
            return (true);
    }
    return (false);
}

Vector3 Player::get_size() const
{
    return (p_size);
}

int Player::getScore() const
{
    return (score);
}

bool Player::isDead() const
{
    return (dead);
}

void Player::play_animation(int i)
{
    if (systemClock.now() - lastRun >= std::chrono::milliseconds(50)) {
        lastRun += std::chrono::milliseconds(50);
        animFrameCounter++;
        UpdateModelAnimation(model, anims.at(i)[0], animFrameCounter);
        if (animFrameCounter >= anims.at(i)[0].frameCount) animFrameCounter = 0;
    }
}

void Player::moveIA() {}
