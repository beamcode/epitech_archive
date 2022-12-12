/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** core
*/

#include "core.hpp"

Core::Core()
{
    this->gameList.push_back(std::pair("nibbler", "lib/arcade_nibbler.so"));
    this->gameList.push_back(std::pair("solarfox", "lib/arcade_solarfox.so"));
    this->gameList.push_back(std::pair("menu", "lib/arcade_menu.so"));
    this->graphList.push_back(std::pair("SFML", "lib/arcade_sfml.so"));
    this->graphList.push_back(std::pair("SDL2", "lib/arcade_sdl2.so"));
    this->graphList.push_back(std::pair("NCURSES", "lib/arcade_ncurses.so"));
}

Core::~Core()
{
    delete this->graphLib;
    delete this->game;
    my_dlib::my_dlclose(this->graphHandler);
    my_dlib::my_dlclose(this->gameHandler);
}

void Core::loadGraphicalLibrairies(const std::string &arg)
{
    this->graphHandler = my_dlib::my_dlopen(arg.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!this->graphHandler)
        throw LoadException(my_dlib::my_dlerror());
    typedef IDisplayModule *(*func)();
    func load = (func)my_dlib::my_dlsym(this->graphHandler, "entryPoint");
    if (!load)
        throw IncompleteException(my_dlib::my_dlerror());
    graphLib = load();
}

void Core::loadGame(const std::string &arg)
{
    this->gameHandler = my_dlib::my_dlopen(arg.c_str(), RTLD_LAZY | RTLD_GLOBAL);
    if (!this->gameHandler)
        throw LoadException(my_dlib::my_dlerror());
    typedef IGameModule *(*func)();
    func load = (func)my_dlib::my_dlsym(this->gameHandler, "entryPoint");
    if (!load)
        throw IncompleteException(my_dlib::my_dlerror());
    this->game = load();
}

void Core::getBaseLib(const std::string &arg)
{
    for (auto it = this->graphList.begin(); it != this->graphList.end(); it++) {
        if (it->second == arg)
            this->actualLib = arg;
    }
    this->actualGame = "lib/arcade_nibbler.so";
}

void Core::changeGraphicLib(const std::string &key)
{
    for (auto it = this->graphList.begin(); it != this->graphList.end(); it++) {
        if (key == "z" && it->second == this->actualLib && it->second != "lib/arcade_ncurses.so") {
            it++;
            delete this->graphLib;
            this->actualLib = it->second;
            const char *lib = this->actualLib.c_str();
            my_dlib::my_dlclose(this->graphHandler);
            this->loadGraphicalLibrairies(lib);
            graphLib->initMap(game->getMap());
            return;
        }
        if (key == "a" && it->second == this->actualLib && it->second != "lib/arcade_sfml.so") {
            it--;
            delete this->graphLib;
            this->actualLib = it->second;
            const char *lib = this->actualLib.c_str();
            my_dlib::my_dlclose(this->graphHandler);
            this->loadGraphicalLibrairies(lib);
            graphLib->initMap(game->getMap());
            return;
        }
    }
}

double Core::get_time() const
{
    return (std::chrono::duration<double>(std::chrono::steady_clock::now().time_since_epoch()).count());
}

void Core::backToMenu()
{
    this->actualGame = "lib/arcade_menu.so";
    delete this->game;
    const char *game = this->actualGame.c_str();
    my_dlib::my_dlclose(this->gameHandler);
    this->loadGame(game);
    this->game->initMap();
    refreshGame();
    this->actualGame = "lib/arcade_nibbler.so";
}

void Core::changeGame(const std::string &key)
{
    for (auto it = this->gameList.begin(); it != this->gameList.end(); it++) {
        if (key == "q" && it->second == this->actualGame && it->second != "lib/arcade_nibbler.so") {
            it--;
            this->actualGame = it->second;
        }
        if (key == "s" && it->second == this->actualGame && it->second != "lib/arcade_solarfox.so") {
            it++;
            this->actualGame = it->second;
        }
        if (key == "enter" && it->second == this->actualGame) {
            delete this->game;
            const char *game = this->actualGame.c_str();
            my_dlib::my_dlclose(this->gameHandler);
            this->loadGame(game);
            this->game->initMap();
            refreshGame();
        }
    }
    if (key == "m")
        backToMenu();
    if (key == "r") {
        delete this->game;
        const char *game = this->actualGame.c_str();
        my_dlib::my_dlclose(this->gameHandler);
        this->loadGame(game);
        this->game->initMap();
        refreshGame();
    }
}

void Core::displayGame()
{
    const double fps = 60;
    double last_time = get_time();
    std::string key;

    refreshGame();
    while (1) {
        double tmp_time = get_time();
        key = graphLib->getKey();
        if (game->endGame())
            backToMenu();
        if (key == "null")
            break;
        changeGraphicLib(key);
        changeGame(key);
        if (key != "other")
            game->manageEvents(key);
        game->getEntityEvent();
        if ((tmp_time - last_time) >= (1.0 / fps)) {
            last_time = tmp_time;
            refreshGame();
        }
        usleep(8330);
    }
}

void Core::refreshGame()
{
    graphLib->refreshMap(game->getMap());
    graphLib->draw_sprite();
}

void Core::SetupGame() const
{
    game->initMap();
    graphLib->initMap(game->getMap());
}

int main(int argc, const char **argv)
{
    Core *core = new Core;
    if (argc != 2) {
        std::cout << "USAGE : ./arcade <libraryName.so>" << std::endl;
        return (84);
    }
    try {
        core->getBaseLib(argv[1]);
        core->loadGraphicalLibrairies(argv[1]);
        core->loadGame((const char*)"lib/arcade_menu.so");
    }
    catch (std::runtime_error &exception)
    {
        std::cerr << exception.what() << std::endl;
        return (84);
    }
    core->SetupGame();
    core->displayGame();
    delete core;
    return (0);
}
