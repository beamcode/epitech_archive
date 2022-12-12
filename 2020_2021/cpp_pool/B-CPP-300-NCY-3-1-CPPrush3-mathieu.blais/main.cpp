#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "ncurses/ncurses.hpp"
#include "SFML/window.hpp"


void Usage(void)
{
    std::cout << "Usage:\n" << "        ./MyGKrellm <-n> or <-g>\n\n" << "       -n for NCurses display\n" << "       -g for Graphical display\n" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 1 || argc > 2)
        Usage();
    if (argc == 2) {
        if (strcmp(argv[1], "-n") == 0)
            start_ncurses();
        else if (strcmp(argv[1], "-g") == 0);
            //openGraphicDisplay();
        else
            Usage();
    }
}
