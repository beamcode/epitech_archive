/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** save
*/

#include "Save.hpp"

Save::Save(std::shared_ptr<Game> _game)
{
    game = _game;
}

Save::~Save()
{
}

void Save::loadSave()
{
    std::string line;
    std::ifstream myfile ("saves/last.txt");
    std::vector<std::string> txt;
    std::vector<std::vector<int>> grid;

    if (myfile.is_open()) {
        while (getline(myfile,line))
            txt.push_back(line);
        myfile.close();
    }
    game->setMap(txt[0]);
}

void Save::fillSave()
{
    std::ofstream myfile;
    myfile.open ("saves/last.txt");
    myfile << game->getMap() << std::endl;
}
