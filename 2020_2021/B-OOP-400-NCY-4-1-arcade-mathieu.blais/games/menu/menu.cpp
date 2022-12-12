/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "menu.hpp"

extern "C"
{
    IGameModule *entryPoint();
}

IGameModule *entryPoint()
{
    return (new Menu());
}

IGameModule::~IGameModule()
{

}

Menu::Menu()
{
    index1 = -1;
    index2 = -1;
    event = 1;
    last_time = get_time();
    ticks_ps = 3;
    gameList.push_back("nibbler");
    gameList.push_back("solarfox");
    graphList.push_back("sfml");
    graphList.push_back("sdl2");
    graphList.push_back("ncurses");
    letter = 25;
    name = "null";
    std::ifstream in("scoreboard.txt");
    std::string str;
    size_t pos;
    while (std::getline(in, str)) {
        pos = str.find(" ");
        str.erase(0, pos+1);
        score = str;
    }
    in.close();
}

Menu::~Menu()
{
    std::fstream myfile;
    myfile.open ("scoreboard.txt", std::fstream::app);
    if (this->name != "null")
        myfile << this->name;
    myfile.close();
}

void Menu::printLastScore()
{
    int y = 25;

    for (size_t i = 0; i < score.size(); i++, y++)
        map.at(1).at(y) = score.at(i);
  }

void Menu::printSolarFoxScoreboard(std::map<int, std::string> mapSolarfox)
{
    int y = 5;
    size_t n = 0;
    size_t line = 7;

    for (auto it = mapSolarfox.begin(); it != mapSolarfox.end(); ++it, n++) {
        if (n >= mapSolarfox.size() - 3) {
            for (size_t i = 0; i < it->second.size() - 8; i++, y++) {
                std::string n = it->second.substr(0, 4);
                this->map.at(line).at(y) = n.at(i);
            }
            y++;
            std::string sc = std::to_string(it->first);
            for (size_t i = 0; i < sc.size(); i++, y++) {
                this->map.at(line).at(y) = sc.at(i);
            }
            line -= 2;
            y = 5;
        }
    }
}

void Menu::printNibblerScoreboard(std::map<int, std::string> mapNibbler)
{
    int y = 37;
    size_t n = 0;
    size_t line = 7;

    for (auto it = mapNibbler.begin(); it != mapNibbler.end(); ++it, n++) {
        if (n >= mapNibbler.size() - 3) {
            for (size_t i = 0; i < it->second.size() - 7; i++, y++) {
                std::string n = it->second.substr(0, 4);
                this->map.at(line).at(y) = n.at(i);
            }
            y++;
            std::string sc = std::to_string(it->first);
            for (size_t i = 0; i < sc.size(); i++, y++) {
                this->map.at(line).at(y) = sc.at(i);
            }
            line -= 2;
            y = 37;
        }
    }
}

void Menu::getScoreBoard()
{
    std::string str;
    std::string name;
    std::string score;
    std::map<int, std::string> mapNibbler;
    std::map<int, std::string> mapSolarfox;
    size_t pos = 0;

    std::ifstream in("scoreboard.txt");
    if(!in)
        return;
    while (std::getline(in, str)) {
        pos = str.find(" ");
        name = str.substr(0, str.find(" "));
        str.erase(0, pos+1);
        score = str;
        if (name.find("nibbler") != std::string::npos)
            mapNibbler.insert(std::pair(stoi(score), name));
        if (name.find("solarfox") != std::string::npos)
            mapSolarfox.insert(std::pair(stoi(score), name));
    }
    in.close();
    printLastScore();
    printNibblerScoreboard(mapNibbler);
    printSolarFoxScoreboard(mapSolarfox);
}

double Menu::get_time() const
{
    return (std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count());
}

int Menu::endGame()
{
    return (0);
}

void Menu::getEntityEvent()
{
    double tmp_time = get_time();

    if ((tmp_time - last_time) >= (1.0 / ticks_ps))
        last_time = tmp_time;
    else return;
    if (event == 1) {
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->first == 18) {
                for (size_t i = 0; i <= it->second.size() - 1; i++)
                    it->second[i] = 0;
            }
            for (int i = 1; i < 15; i++) {
                this->map.at(i).at(14) = 1;
                this->map.at(i).at(32) = 1;
            }
        }
        event = 0;
    }
    else {
        for (auto it = map.begin(); it != map.end(); ++it) {
            if (it->first == 18)
                it->second = mapSave;
            for (int i = 1; i < 15; i++) {
                this->map.at(i).at(14) = 0;
                this->map.at(i).at(32) = 0;
            }
        }
        event = 1;
    }
}

void Menu::changeLetterPosition(std::string key)
{
    if (key == "left") {
        if (this->letter > 25) {
            this->map.at(7).at(this->letter) = 0;
            this->letter--;
            this->map.at(7).at(this->letter) = 45;
        }
    }
    if (key == "right") {
        if (this->letter < 28) {
            this->map.at(7).at(this->letter) = 0;
            this->letter++;
            this->map.at(7).at(this->letter) = 45;
        }
    }
}

void Menu::changeLetter()
{
    if (this->map.at(6).at(this->letter) == 90)
        this->map.at(6).at(this->letter) = 64;
    this->map.at(6).at(this->letter)++;
    this->name.clear();
    this->name.push_back(this->map.at(6).at(25));
    this->name.push_back(this->map.at(6).at(26));
    this->name.push_back(this->map.at(6).at(27));
    this->name.push_back(this->map.at(6).at(28));
}

void Menu::manageEvents(const std::string &key)
{
    if (key == "z")
        setMenuGraphChoices(0);
    if (key == "a")
        setMenuGraphChoices(1);
    if (key == "s" || key == "b")
        setMenuGameChoices(0);
    if (key == "q")
        setMenuGameChoices(1);
    if (key == "left" || key == "right")
        changeLetterPosition(key);
    if (key == "space")
        changeLetter();
}

void Menu::setMenuGameChoices(const int &direction)
{
    size_t y = 0;
    int size = gameList.size();

    if (direction == 0) {
        if (index2 < size - 1) {
            for (auto it = map.begin(); it != map.end(); ++it) {
                if (it->first == 12) {
                    for (size_t i = 23; i <= it->second.size() - 1; i++, y++) {
                        if (y <= gameList[index2 + 1].size()) {
                            int c = (char) gameList[index2 + 1][y];
                            it->second[i] = c;
                        }
                        else {
                            it->second[i] = 0;
                            if (event == 0)
                                map.at(12).at(32) = 1;
                        }
                    }
                }
            }
            index2++;
        }
    }
    else {
        if (index2 > 0) {
            for (auto it = map.begin(); it != map.end(); ++it) {
                if (it->first == 12) {
                    for (size_t i = 23; i <= it->second.size() - 1; i++, y++) {
                        if (y <= gameList[index2 - 1].size()) {
                            int c = (char) gameList[index2 - 1][y];
                            it->second[i] = c;
                        }
                        else {
                            it->second[i] = 0;
                            if (event == 0)
                                map.at(12).at(32) = 1;
                        }
                    }
                }
            }
            index2--;
        }
    }
}

void Menu::setMenuGraphChoices(const int &direction)
{
    size_t y = 0;
    int size = graphList.size();

    if (direction == 0) {
        if (index1 < size - 1) {
            for (auto it = map.begin(); it != map.end(); ++it) {
                if (it->first == 9) {
                    for (size_t i = 25; i <= it->second.size() - 1; i++, y++) {
                        if (y <= graphList[index1 + 1].size()) {
                            int c = (char) graphList[index1 + 1][y];
                            it->second[i] = c;
                        }
                        else
                            it->second[i] = 0;
                    }
                }
            }
            index1++;
        }
    }
    else {
        if (index1 > 0) {
            for (auto it = map.begin(); it != map.end(); ++it) {
                if (it->first == 9) {
                    for (size_t i = 25; i <= it->second.size() - 1; i++, y++) {
                        if (y <= graphList[index1 - 1].size()) {
                            int c = (char) graphList[index1 - 1][y];
                            it->second[i] = c;
                        }
                        else
                            it->second[i] = 0;
                    }
                }
            }
            index1--;
        }
    }
}

std::map<int, std::vector<int>> Menu::getMap() const
{
    return (map);
}

void Menu::initMap()
{
    std::string str = "games/menu/menu_map.txt";
    std::vector<int> vec;
    int j = 1;

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
        map.insert(std::pair(j, vec));
        if (j == 18)
            mapSave = vec;
        vec.clear();
        j++;
    }
    in.close();
    setMenuGraphChoices(0);
    setMenuGameChoices(0);
    getScoreBoard();
}
