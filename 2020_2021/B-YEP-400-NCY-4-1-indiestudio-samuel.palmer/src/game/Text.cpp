/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** text
*/

#include "Text.hpp"

Text::Text(const std::string &fontPath, const std::string &txt, float x, float y, int fontSize)
{
    const char *file = strToChar(fontPath);
    Font font = LoadFont(file);
    _font = font;
    tmp = txt;
    pos.x = x;
    pos.y = y;
    size = fontSize;
}

Text::~Text()
{
    //UnloadFont(_font);
}

void Text::drawText() const
{
    DrawTextEx(_font, tmp.c_str(), pos, size, 5, WHITE);
}

void Text::updateText(const std::string &txt)
{
    tmp = txt;
}
