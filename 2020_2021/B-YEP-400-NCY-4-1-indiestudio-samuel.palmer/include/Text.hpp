/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <raylib.h>
#include <string>
#include <ostream>
#include <iostream>

class Text {
    public:
        Text(const std::string &fontPath, const std::string &txt, float x, float y, int fontSize);
        ~Text();
        template<typename T>
        const char *strToChar(const T &str) {
            return (str.c_str());
        }
        void drawText() const;
        void updateText(const std::string &txt);

    protected:
    private:
        Font _font;
        Vector2 pos;
        int size;
        std::string tmp;
};

#endif /* !CAMERA_HPP_ */
