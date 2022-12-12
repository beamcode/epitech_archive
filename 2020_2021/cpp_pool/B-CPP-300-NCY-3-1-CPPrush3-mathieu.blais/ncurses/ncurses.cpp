/*
** EPITECH PROJECT, 2021
** ncurses.cpp
** File description:
** main
*/

#include "ncurses.hpp"

int max_x;
int max_y;

char *get_time()
{
    std::time_t ct = std::time(0);
    char *cc = ctime(&ct);
    return (cc);
}

void set_colors()
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_WHITE, COLOR_BLACK);
}

void set_params(WINDOW *win)
{
    noecho();
    set_colors();
    nodelay(win, TRUE);
    curs_set(FALSE);
    box(win, 0, 0);
    use_default_colors();
}

void print_network_info(int x, int y)
{
    attron(COLOR_PAIR(2));
    mvprintw(x, y, "   NETWORK MONITOR   ");
    attroff(COLOR_PAIR(4));
    mvprintw(x+2, y, "[ RX ]          %s", "NULL");
    mvprintw(x+3, y, "[ TX ]          %s", "NULL");
}

void print_hardware_info(int x, int y, hardware &val)
{
    val.getNames();
    attron(COLOR_PAIR(2));
    mvprintw(x, y, "   HARDWARE INFO   ");
    attroff(COLOR_PAIR(4));

    mvprintw(x+2, y, "Vendor ID:      %s", val.getVendor().c_str());
    mvprintw(x+3, y, "Model Name:     %s", val.getModel().c_str());
    mvprintw(x+4, y, "Cpu Cores:      %s", val.getCores().c_str());
    mvprintw(x+5, y, "Frequency:      %s", val.getFreq().c_str());
    mvprintw(x+6, y, "Cache Size:     %s", val.getCache().c_str());
}

void print_memory_info(int x, int y, ram &val)
{
    attron(COLOR_PAIR(2));
    mvprintw(x, y, "   MEMORY   ");
    attroff(COLOR_PAIR(4));

    mvprintw(x+2, y, "Total RAM       %.3d MB", val.get_total_ram());
    mvprintw(x+3, y, "Free RAM        %.3d MB", val.get_free_ram());
    mvprintw(x+4, y, "Shared          %.3d MB", val.get_shared_ram());
}

void print_cpu_info(int x, int y)
{
    attron(COLOR_PAIR(2));
    mvprintw(x, y, "   CPU   ");
    attroff(COLOR_PAIR(4));

    //Ugly code needed to fix a bad bug
    cpu a;
    a.refresh();
    std::vector<std::string> vec = a.getcpu(); 

    mvprintw(x+2, y, "[ TOTAL ]        %s", a.getTotal().c_str());
    for (unsigned int i = 0; i < vec.size(); i++)
        mvprintw((x+4) + i, y, "[ CPU %d ]        %s", i, vec[i].c_str());
}

void print_sys_info(int x, int y, info &val)
{
    attron(COLOR_PAIR(1));
    mvprintw(1, (max_x - (strlen(get_time()))) / 2, "%s", get_time());
    attroff(COLOR_PAIR(4));
    attron(COLOR_PAIR(2));
    mvprintw(x, 5, "   SYSTEM INFO   ");
    attroff(COLOR_PAIR(4));
    mvprintw(x+2, y, "Time:           %s", get_time());
    //mvprintw(x+3, y, "Uptime:         %.2d:%.2d:%.2d", (info.uptime/3600), (info.uptime % 3600) / 60, info.uptime % 60);
    mvprintw(x+4, y, "User:           %s", getlogin());
    mvprintw(x+5, y, "Host Name:      %s", val.get_user().c_str());
    mvprintw(x+6, y, "System Name:    %s", val.get_sys().c_str());
    mvprintw(x+7, y, "Machine:        %s", val.get_machine().c_str());
    mvprintw(x+8, y, "Version:        %s", val.get_version().c_str());
    //mvprintw(x+9, y, "Kernal:         %s", _sysinfo.release);    
}

int display_window()
{
    WINDOW *win = initscr();
    if (win == NULL)
        return (84);
    hardware h;
    ram r;
    info i;

    int ch = 0;
    set_params(win);

    while (1) {
        getmaxyx(win,max_y,max_x);
        if ((ch = getch()) != ERR) {
            clear();
            box(win, 0, 0);
        }
        print_sys_info(3, 5, i);
        print_hardware_info(14, 5, h);
        print_network_info(22, 5);
        print_memory_info(27, 5, r);
        print_cpu_info(33, 5);
        wrefresh(win);
        usleep(500);
    }
}

int start_ncurses() 
{
    return (display_window());
}