/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sdl2
*/

#include "SDL2.hpp"

extern "C"
{
    IDisplayModule *entryPoint();
}

IDisplayModule *entryPoint()
{
    return (new SDL2());
}

IDisplayModule::~IDisplayModule()
{
}

SDL2::SDL2()
{
    size = 26;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cout << "SDL could not initilize! SDL Error: " << SDL_GetError() << std::endl;
    TTF_Init();
    Uint32 flags = SDL_WINDOW_SHOWN;
    window = SDL_CreateWindow(
        (char *)"SDL2 Game",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1200, 600,
        flags);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    //if (window == NULL)
    //    std::cout << "Window Error: " << SDL_GetError() << std::endl;
    font = TTF_OpenFont("graphicals/sdl2/font.ttf", size);
    SDL_RaiseWindow(window);
}

SDL2::~SDL2()
{
    for (size_t i = 0, j = 0; i < squares.size(); i++, j = 0) {
        for (; j < squares[i].size(); j++) {
            delete squares[i].at(j);
        }
    }
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDL2::draw_sprite()
{
    SDL_RenderClear(renderer);
    for(auto& row:squares) {
        for(auto& col:row) {
            col->draw_square(renderer);
        }
    }
    SDL_SetRenderDrawColor(renderer, 0,0, 0, 0);
    SDL_RenderPresent(renderer);
}

int SDL2::Events()
{
    if (SDL_PollEvent(&event)) {
        if (SDL_QUIT == event.type)
            return (1);
    }
    return (0);
}

std::string SDL2::getKey()
{
    while (SDL_PollEvent(&event)) {
        if (SDL_QUIT == event.type)
            return ("null");
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT: return ("right");
                case SDLK_DOWN: return ("down");
                case SDLK_LEFT: return ("left");
                case SDLK_UP: return ("up");
                case SDLK_RETURN: return ("enter");
                case SDLK_ESCAPE: return ("null");
                case SDLK_SPACE: return ("space");

                case SDLK_p: return ("p");
                case SDLK_a: return ("a");
                case SDLK_z: return ("z");
                case SDLK_q: return ("q");
                case SDLK_s: return ("s");
                case SDLK_m: return ("m");
                case SDLK_r: return ("r");
            }
        }
    }
    return ("other");
}

void SDL2::initMap(std::map<int, std::vector<int>> map)
{
    int size_y = map.size(),
        size_x = map.begin()->second.size(),
        pos_x = 0,
        pos_y = 0;
    std::vector<Square *> tmp;

    for (int i = 0, y = pos_y; i < size_y; i++, y+=size) {
        for (int j = 0, x = pos_x; j < size_x; j++, x+=size)
            tmp.push_back(new Square(x, y, size, renderer, font));
        squares.push_back(tmp);
        tmp.clear();
    }
}

void SDL2::refreshMap(std::map<int, std::vector<int>> map)
{
    for (std::map<int,std::vector<int>>::iterator it = map.begin(); it != map.end(); ++it) {
        for (size_t i = 0, k = it->first - 1; i < it->second.size(); i++) {
            std::string str(1, (char)it->second.at(i));
            squares.at(k).at(i)->display_text(false);
            switch(it->second.at(i)) {
                case 1: squares.at(k).at(i)->set_rgb(1); continue;
                case 2: squares.at(k).at(i)->set_rgb(2); continue;
                case 3: squares.at(k).at(i)->set_rgb(3); continue;
                case 4: squares.at(k).at(i)->set_rgb(4); continue;
                case 5: squares.at(k).at(i)->set_rgb(5); continue;
                default: squares.at(k).at(i)->set_rgb(0);
            }
            squares.at(k).at(i)->display_text(true);
            squares.at(k).at(i)->update_text(str, renderer);
        }
    }
}
