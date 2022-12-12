/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** square
*/

#include "Square.hpp"

Square::Square(int x, int y, int size, SDL_Renderer *renderer, TTF_Font *font)
{
    sq_color = {0, 0, 0, 255};
    square = {x, y, size, size};
    
    text_disp = false;
    text_color = {255, 255, 255, 255};
    text_font = font;
    text_rect = {x + (size/4), y + (size/4), size - (size/4), size};
    text_surface = TTF_RenderText_Solid(text_font, "T", text_color);
    text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
}

Square::~Square()
{
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
}

void Square::draw_square(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, sq_color.r, sq_color.g, sq_color.b, sq_color.a);
    SDL_RenderFillRect(renderer, &square);
    SDL_RenderDrawRect(renderer, &square);
    if (text_disp)
        SDL_RenderCopy(renderer, text_texture, NULL, &text_rect);
}

SDL_Rect *Square::get_rect(void)
{
    return (&square);
}

void Square::display_text(bool disp)
{
    text_disp = disp;
}

void Square::set_rgb(int color)
{
    if (color == 0)
        sq_color = {0, 0, 0, 255};
    if (color == 1)
        sq_color = {180, 0, 180, 255};
    if (color == 2)
        sq_color = {0, 0, 180, 255};
    if (color == 3)
        sq_color = {0, 170, 0, 255};
    if (color == 4)
        sq_color = {0, 170, 180, 255};
    if (color == 5)
        sq_color = {255, 0, 0, 255};
}

void Square::update_text(std::string letter, SDL_Renderer *renderer)
{
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
    text_surface = TTF_RenderText_Solid(text_font, letter.c_str(), text_color);
    text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
}