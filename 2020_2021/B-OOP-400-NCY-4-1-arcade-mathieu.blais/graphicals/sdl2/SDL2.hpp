/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** sdl2
*/

#ifndef SDL2_HPP_
#define SDL2_HPP_

#include "Square.hpp"
#include "../IDisplayModule.hpp"

class SDL2 : public IDisplayModule {
    public:
        SDL2();
        ~SDL2();

        int Events();
        void draw_sprite();
        void initMap(std::map<int, std::vector<int>> map);
        void refreshMap(std::map<int, std::vector<int>> map);
        std::string getKey();
    protected:
    private:
        SDL_Window *window;
        SDL_Event event;
        SDL_Renderer *renderer;
        TTF_Font *font;

        std::string window_title;
        std::string game_title;
        std::vector<std::vector<Square *>> squares;
        int size;
};

#endif /* !SDL2_HPP_ */
