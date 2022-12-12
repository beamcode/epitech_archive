/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "nibbler.hpp"

extern "C"
{
    IGameModule *entryPoint();
}

IGameModule *entryPoint()
{
    return (new Nibbler());
}

IGameModule::~IGameModule()
{
}

Nibbler::Nibbler()
{
    dir = "left";
    prev_dir = dir;
    end = false;
    score = 0;
    last_time = get_time();
    lives = 1;
    write = false;
}

Nibbler::~Nibbler()
{
}

double Nibbler::get_time() const
{
    return (std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count());
}

void Nibbler::getEntityEvent()
{
    double tmp_time = get_time();

    if (lives < 1) {
        print_end();
        write_leaderboard();
        return;
    }
    if ((tmp_time - last_time) >= (1.0 / 9.0))
        last_time = tmp_time;
    else return;
    spawnFood();
    move_snake();
    print_score();
}

void Nibbler::write_leaderboard()
{
    if (write)
        return;
    
    std::string line = "nibbler " + std::to_string(score) +  "\n";
    std::fstream myfile;
    myfile.open ("scoreboard.txt", std::fstream::app);
    myfile << line;
    myfile.close();
    write = true;
}

int Nibbler::endGame()
{
    return (end);
}

int Nibbler::get_score() const
{
    return (score);
}

void Nibbler::spawnFood()
{
    int x = rand() % 33;
    int y = rand() % 20;
    int r = rand() % 20;
    int count = 0;

    if (y < 2 || x < 2)
        return;
    for (size_t i = 0, j = 0; i < map.size() && r == 3; i++) {
        if ((int)i == y) {
            for (; (int)j != x; j++);
            if (map[i].at(j) == 0)
                map[i].at(j) = 3;
        }
    }
    for (size_t i = 0; i < map.size(); i++) {
        for (int y = 0; y < 33; y++) {
            if (map[i].at(y) == 3)
                count++;
        }
    }
    if (count == 0) {
        for (size_t i = 0, j = 0; i < map.size(); i++) {
            if ((int)i == y) {
                for (; (int)j != x; j++);
                if (map[i].at(j) == 0)
                    map[i].at(j) = 3;
            }
        }
    }
}

void Nibbler::print_end()
{
    for (size_t i = 1; i < map.size() - 1; i++) {
        for (size_t j = 1; j < (map[i].size() - 11); j++) {
            if (map.at(i).at(j) == 2 || map.at(i).at(j) == 4 ||
                map.at(i).at(j) == 1 || map.at(i).at(j) == 3)
                map.at(i).at(j) = 0;
        }
    }
    map.at(11).at(12 + 1) = 71;
    map.at(11).at(12 + 2) = 65;
    map.at(11).at(12 + 3) = 77;
    map.at(11).at(12 + 4) = 69;
    map.at(11).at(12 + 6) = 79;
    map.at(11).at(12 + 7) = 86;
    map.at(11).at(12 + 8) = 69;
    map.at(11).at(12 + 9) = 82;
}

void Nibbler::print_score()
{
    std::string s = std::to_string(this->score);
    int y = 39;

    for (size_t i = 0; i < s.size(); i++, y++)
        map.at(5).at(y) = s.at(i);
}

void Nibbler::move_snake()
{
    std::pair<int, std::pair<int, int>> tmp = snake[0];
    bool modify = true;

    if (dir == "right" && prev_dir != "left")
        tmp.second.first++;
    else if (dir == "up" && prev_dir != "down")
        tmp.second.second--;
    else if (dir == "left" && prev_dir != "right")
        tmp.second.first--;
    else if (dir == "down" && prev_dir != "up")
        tmp.second.second++;
    else {
        if (prev_dir == "right")
            tmp.second.first++;
        if (prev_dir == "up")
            tmp.second.second--;
        if (prev_dir == "left")
            tmp.second.first--;
        if (prev_dir == "down")
            tmp.second.second++;
        modify = false;
    }
    if (modify)
        prev_dir = dir;
    if (map.at(tmp.second.second).at(tmp.second.first) != 0 &&
        map.at(tmp.second.second).at(tmp.second.first) != 3) {
        lives--;
        return;
    }
    snake.insert(snake.begin(), 1, tmp);
    snake[1].first = snake.back().first;
    if (map.at(tmp.second.second).at(tmp.second.first) == 3)
        score += 10;
    else {
        map.at(snake.back().second.second).at(snake.back().second.first) = 0;
        snake.pop_back();
    }
    for (size_t i = 0; i < snake.size(); i++)
        map.at(snake[i].second.second).at(snake[i].second.first) = snake[i].first;
}

void Nibbler::set_dir(const std::string &key)
{
    dir = key;
}

void Nibbler::manageEvents(const std::string &key)
{
    if (key == "right" || key == "left" || key == "up" || key == "down")
        set_dir(key);
}

std::map<int, std::vector<int>> Nibbler::getMap() const
{
    std::map<int, std::vector<int>> tmp;
    int pos = 1;

    for (size_t i = 0; i < map.size(); i++, pos++)
        tmp.insert(std::pair(pos, map[i]));
    return (tmp);
}

void Nibbler::initMap()
{
    std::string str = "games/nibbler/nibbler_map.txt";
    std::vector<int> vec;
    std::ifstream in(str);

    if(!in) {
        std::cerr << "Cannot open the File : "<< str <<std::endl;
        return;
    }
    str.clear();
    while (std::getline(in, str)) {
            std::stringstream iss(str);
            int number = 0;
            while (iss >> number)
            vec.push_back(number);
        map.push_back(vec);
        vec.clear();
    }
    in.close();
    snake = {
        {4, {16, 14}}, {2, {17, 14}}, {2, {18, 14}},
        {2, {19, 14}}, {2, {20, 14}}, {2, {21, 14}}
    };
}
