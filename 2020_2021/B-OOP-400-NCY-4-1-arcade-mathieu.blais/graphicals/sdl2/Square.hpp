/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** square
*/

#ifndef SQUARE_HPP_
#define SQUARE_HPP_

#include <iostream>
#include <map>
#include <vector>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_shape.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>

class Square {
    public:
        Square(int x, int y, int size, SDL_Renderer *renderer, TTF_Font *_font);
        ~Square();

        void draw_square(SDL_Renderer *renderer);
        void update_text(std::string _letter, SDL_Renderer *renderer);
        void display_text(bool);
        void set_rgb(int color);
        SDL_Rect *get_rect(void);
    protected:
    private:
        SDL_Rect square;
        SDL_Color sq_color;

        bool text_disp;
        std::string letter;
        SDL_Rect text_rect;
        SDL_Color text_color;
        TTF_Font *text_font;
        SDL_Surface *text_surface;
        SDL_Texture *text_texture;
};

#endif /* !SQUARE_HPP_ */
