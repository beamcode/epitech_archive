/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Menu
*/

#ifndef Menu_HPP_
#define Menu_HPP_

#include "Scene.hpp"

class Menu : public Scene {
    public:
        Menu(const std::string &);
        Menu(const std::string &, std::shared_ptr<Save>save);
        virtual ~Menu();

        void updateScene();
        void updateButton();
        void refresh();
        void animateButtons();

    private:
};
#endif /* !Menu_HPP_ */
