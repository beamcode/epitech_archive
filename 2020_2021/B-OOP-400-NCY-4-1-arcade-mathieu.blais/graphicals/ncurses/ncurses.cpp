/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "ncurses.hpp"

extern "C"
{
    IDisplayModule *entryPoint();
}

IDisplayModule *entryPoint()
{
	return (new Ncurses());
}

IDisplayModule::~IDisplayModule()
{
}

Ncurses::Ncurses()
{
    this->window = initscr();
	keypad(this->window, true);
	noecho();
	start_color();
	curs_set(FALSE);
    box(this->window, 0, 0);
}

Ncurses::~Ncurses()
{
    endwin();
}

void Ncurses::initMap([[maybe_unused]]std::map<int, std::vector<int>> map)
{
    wrefresh(this->window);
    draw_sprite();
}

std::string Ncurses::getKey()
{
	nodelay(this->window, TRUE);
    int command = getch();

    switch (command) {
        case 259 : return ("up");
        case 261 : return ("right");
        case 260 : return ("left");
        case 258 : return ("down");
        case 10 : return ("enter");
        case 27 : return ("null");
        case 32 : return ("space");
        
        case 97 : return ("a");
        case 122 : return ("z");
        case 113 : return ("q");
        case 115 : return ("s");
        case 109 : return ("m");
        case 114 : return ("r");
    }
    wrefresh(this->window);
    return ("other");
}

void Ncurses::refreshMap(std::map<int, std::vector<int>> _map)
{
    this->map = _map;
    this->initMap(this->map);
}

void Ncurses::print_real(std::string map)
{
    init_pair(1, COLOR_BLACK, COLOR_MAGENTA);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(4, COLOR_BLACK, COLOR_WHITE);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    init_pair(6, COLOR_BLACK, COLOR_BLUE);
    init_pair(7, COLOR_BLACK, COLOR_CYAN);

    for (int i = 0; map[i] != '\0'; i++){
        if (map[i] == '&') {
	        attron(COLOR_PAIR(6));
            printw("%c", ' ');
            continue;
        }
        if (map[i] == '!') {
	        attron(COLOR_PAIR(3));
            printw("%c", ' ');
            continue;
        }
        if (map[i] == '@') {
	        attron(COLOR_PAIR(7));
            printw("%c", ' ');
            continue;
        }
        if (map[i] == '#') {
	        attron(COLOR_PAIR(1));
            printw("%c", ' ');
            continue;
        }
        if (map[i] == '$') {
	        attron(COLOR_PAIR(2));
            printw("%c", ' ');
            continue;
        }
    printw("%c", map[i]);
    attroff(COLOR_PAIR(1));
    }
    wrefresh(this->window);
}

void Ncurses::print_map()
{
    erase();
    int x = 0, y = 0;
    std::string map = "\n\n\n\n\n\n";

    for (auto it = this->map.begin(); it != this->map.end(); ++it) {
        map = map + "\t\t\t\t\t\t\t";
        for (size_t i = 0; i < it->second.size(); i++) {
            char a = it->second[i];
            switch (it->second[i]) {
                case 0 : map.push_back(' ');
                break;
                case 1 : map.push_back('#');
                break;
                case 2 : map.push_back('&');
                break;
                case 3 : map.push_back('!');
                break;
                case 4 : map.push_back('@');
                break;
                case 5 : map.push_back('$');
                break;
                default : map.push_back(a);
            }
            map.push_back(' ');
            x++;
        }
        map.push_back('\n');
        y++;
    }
    print_real(map);
}

void Ncurses::draw_sprite()
{
    if (LINES < 50 || COLS < 150) {
        erase();
        mvprintw((LINES / 2), (COLS / 2) - (21 / 2), "Window size too small\n");
        mvprintw((LINES / 2 + 1), (COLS / 2) - (38 / 2), "Enlarge your window or press CTRL + C to Quit\n");
        return;
    }
    print_map();
}
