#include "SolarFox.hpp"

extern "C"
{
    IGameModule *entryPoint();
}

IGameModule *entryPoint()
{
    return (new SolarFox());
}

IGameModule::~IGameModule()
{
}

SolarFox::SolarFox()
{
    lives = 1;
    win = false;
    score = 0;
    end = false;
    guns_dir = 1;
    write = false;
    player_dir = 1;
    gameover_time = 4;
    prev_player_dir = 0;

    //speeds
    proj_speed = 30;
    guns_speed = 10;
    player_speed = 7;
    missiles_speed = 10;
    proj_spawn_speed = 5;
    missiles_spawn_speed = 7;
    
    //clocks
    tmp_time = get_time();

    last_time_proj = tmp_time;
    last_time_guns = tmp_time;
    last_time_player = tmp_time;
    last_time_missiles = tmp_time;
    last_time_gameover = tmp_time;
    last_time_spawn_proj = tmp_time;
    last_time_spawn_missiles = tmp_time;
    
}

SolarFox::~SolarFox()
{
    for (size_t i = 0; i < missiles.size(); i++) {
        delete missiles[i];
        missiles.erase(missiles.begin() + i);
    }
}

int SolarFox::get_score() const
{
    return (score);
}

double SolarFox::get_time() const
{
    return (std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count());
}

int SolarFox::endGame()
{
    return ((int)end);
}

void SolarFox::getEntityEvent()
{
    tmp_time = get_time();

    if (lives < 1) {
        print_end();
        write_leaderboard();
        return;
    }
    if ((tmp_time - last_time_player) >= (1.0 / player_speed)) {
        last_time_player = tmp_time;
        move_player();
    }
    if ((tmp_time - last_time_guns) >= (1.0 / guns_speed)) {
        last_time_guns = tmp_time;
        move_guns();
    }
    manage_missiles();
    check_events();
    manage_proj();
    print_score();
}

void SolarFox::write_leaderboard()
{
    if (write)
        return;

    std::string line = "solarfox " + std::to_string(score) +  "\n";
    std::fstream myfile;
    myfile.open ("scoreboard.txt", std::fstream::app);
    myfile << line;
    myfile.close();
    write = true;
}

void SolarFox::print_score()
{
    std::string s = std::to_string(score);

    for (size_t i = 0, y = 39; i < s.size(); i++, y++)
        map.at(5).at(y) = s.at(i);
}

void SolarFox::print_end()
{
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < (map[i].size() - 10); j++) {
            if (map.at(i).at(j) == 2 || map.at(i).at(j) == 4)
                map.at(i).at(j) = 0;
            if (map.at(i).at(j) == 3)
                map.at(i).at(j) = 1;
        }
    }
    for (size_t i = 0; i < proj_map.size(); i++)
        for (size_t j = 0; j < proj_map[i].size(); j++)
            proj_map.at(i).at(j) = 0;
    
    if (win) {
        proj_map.at(11).at(13 + 1) = 89;
        proj_map.at(11).at(13 + 2) = 79;
        proj_map.at(11).at(13 + 3) = 85;
        proj_map.at(11).at(13 + 5) = 87;
        proj_map.at(11).at(13 + 6) = 73;
        proj_map.at(11).at(13 + 7) = 78;
    }
    else {
        proj_map.at(11).at(12 + 1) = 71;
        proj_map.at(11).at(12 + 2) = 65;
        proj_map.at(11).at(12 + 3) = 77;
        proj_map.at(11).at(12 + 4) = 69;
        proj_map.at(11).at(12 + 6) = 79;
        proj_map.at(11).at(12 + 7) = 86;
        proj_map.at(11).at(12 + 8) = 69;
        proj_map.at(11).at(12 + 9) = 82;
    }
}

void SolarFox::move_player()
{
    std::pair<int, std::pair<int, int>> tmp = player;
    bool modify = true;

    if (player_dir == 1 && prev_player_dir != 3)
        tmp.second.first--;
    else if (player_dir == 2 && prev_player_dir != 4)
        tmp.second.second++;
    else if (player_dir == 3 && prev_player_dir != 1)
        tmp.second.first++;
    else if (player_dir == 4 && prev_player_dir != 2)
        tmp.second.second--;
    else {
        if (prev_player_dir == 1)
            tmp.second.first--;
        if (prev_player_dir == 2)
            tmp.second.second++;
        if (prev_player_dir == 3)
            tmp.second.first++;
        if (prev_player_dir == 4)
            tmp.second.second--;
        modify = false;
    }
    if (modify)
        prev_player_dir = player_dir;
    if (tmp.second.first == 3 || tmp.second.first == 19 ||
        tmp.second.second == 31 || tmp.second.second == 3)
        return;
    if (map.at(tmp.second.first).at(tmp.second.second) == 1)
        lives--;
    map.at(player.second.first).at(player.second.second) = 0;
    player = tmp;
    map.at(player.second.first).at(player.second.second) = player.first;
}

void SolarFox::move_guns()
{
    if (gun_1.second.second >= 33)
        guns_dir = 0;
    if (gun_1.second.second <= 1)
        guns_dir = 1;
    map.at(gun_1.second.first).at(gun_1.second.second) = 1;
    map.at(gun_2.second.first).at(gun_2.second.second) = 1;
    if (guns_dir == 1) {
        gun_1.second.second++;
        gun_2.second.second--;
    }
    if (guns_dir == 0) {
        gun_1.second.second--;
        gun_2.second.second++;
    }
    map.at(gun_1.second.first).at(gun_1.second.second) = 3;
    map.at(gun_2.second.first).at(gun_2.second.second) = 3;
}

void SolarFox::manage_missiles()
{
    int x = rand() % 32;
    int y = rand() % 22;

    for (size_t i = 0; i < missiles.size(); i++) {
        if ((missiles[i]->get_pos().first <= 0 && missiles[i]->get_dir() == 1) ||
            (missiles[i]->get_pos().first >= 22 && missiles[i]->get_dir() == 3)) {
            proj_map.at(missiles[i]->get_pos().first).at(missiles[i]->get_pos().second) = 0;
            delete missiles[i];
            missiles.erase(missiles.begin() + i);
        }
    }
    if ((tmp_time - last_time_spawn_missiles) >= (1.0 / missiles_spawn_speed)) {
        last_time_spawn_missiles = tmp_time;
        if (x > 28)
            missiles.push_back(new Missile(5, 3, gun_1.second.first, gun_1.second.second));
        if (y > 15)
            missiles.push_back(new Missile(5, 1, gun_2.second.first, gun_2.second.second));
    }
    if ((tmp_time - last_time_missiles) >= (1.0 / missiles_speed)) {
        last_time_missiles = tmp_time;
        for (size_t i = 0; i < missiles.size(); i++) {
            proj_map.at(missiles[i]->get_pos().first).at(missiles[i]->get_pos().second) = 0;
            missiles[i]->move_proj();
            proj_map.at(missiles[i]->get_pos().first).at(missiles[i]->get_pos().second) = 5;
        }
    }
}

void SolarFox::manage_proj()
{
    for (size_t i = 0; i < ship_p.size(); i++) {
        if (ship_p[i]->decay() >= 3) {
            proj_map.at(ship_p[i]->get_pos().first).at(ship_p[i]->get_pos().second) = 0;
            delete ship_p[i];
            ship_p.erase(ship_p.begin() + i);
        }
    }
    if ((tmp_time - last_time_spawn_proj) >= (1.0 / proj_spawn_speed)) {
        last_time_spawn_proj = tmp_time;
        ship_p.push_back(new Ship_Proj(player.second.first, player.second.second, prev_player_dir));
    }
    if ((tmp_time - last_time_proj) >= (1.0 / proj_speed)) {
        last_time_proj = tmp_time;
        
        for (size_t i = 0; i < ship_p.size(); i++) {
            proj_map.at(ship_p[i]->get_pos().first).at(ship_p[i]->get_pos().second) = 0;
            ship_p[i]->move_proj();
            for (size_t j = 0; j < missiles.size(); j++) {
                if ((missiles[j]->get_pos().first == ship_p[i]->get_pos().first) &&
                    (missiles[j]->get_pos().second == ship_p[i]->get_pos().second)) {
                    delete missiles[j];
                    missiles.erase(missiles.begin() + j);
                }
            }
            proj_map.at(ship_p[i]->get_pos().first).at(ship_p[i]->get_pos().second) = ship_p[i]->color;
        }
    }
}

void SolarFox::check_events()
{
    int pows = 0;

    for (size_t i = 0; i < proj_map.size(); i++) {
        for (size_t j = 0; j < proj_map[i].size(); j++) {
            if (proj_map.at(player.second.first).at(player.second.second) == 5) {
                lives--;
                return;
            }
        }
    }
    for (size_t i = 0; i < ship_p.size(); i++) {
        if (map.at(ship_p.front()->get_pos().first).at(ship_p.front()->get_pos().second) == 2) {
            map.at(ship_p.front()->get_pos().first).at(ship_p.front()->get_pos().second) = 0;
            score += 10;
        }
    }
    for (size_t i = 0; i < map.size(); i++) {
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map.at(i).at(j) == 2)
                pows++;
        }
    }
    if (pows == 0) {
        win = true;
        lives--;
    }
}

void SolarFox::manageEvents(const std::string &key)
{
    if (key == "up")
        player_dir = 1;
    if (key == "right")
        player_dir = 2;
    if (key == "down")
        player_dir = 3;
    if (key == "left")
        player_dir = 4;
}

std::map<int, std::vector<int>> SolarFox::getMap() const
{
    std::vector<std::vector<int>> tmp_map = map;
    std::map<int, std::vector<int>> tmp;
    int pos = 1;

    for (size_t i = 0; i < proj_map.size(); i++) {
        for (size_t j = 0; j < proj_map[i].size(); j++) {
            if (proj_map[i].at(j) != 0)
                tmp_map.at(i).at(j) = proj_map[i].at(j);
        }
    }
    for (size_t i = 0; i < tmp_map.size(); i++, pos++)
        tmp.insert(std::pair(pos, tmp_map[i]));
    return (tmp);
}

void SolarFox::initMap()
{
    std::string str = "games/solarfox/solarfox_map.txt";
    std::vector<int> vec;
    std::ifstream in(str);

    if(!in) {
        std::cerr << "Cannot open the File: " << str <<std::endl;
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
    proj_map = map;
    for (size_t i = 0; i < proj_map.size(); i++)
        for (size_t j = 0; j < proj_map[i].size(); j++)
            proj_map[i].at(j) = 0;
    gun_1 = {3, {0, 1}};
    gun_2 = {3, {22, 33}};
    player = {4, {14, 16}};
}

