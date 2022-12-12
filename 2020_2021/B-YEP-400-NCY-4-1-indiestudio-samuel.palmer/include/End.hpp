/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** End
*/

#ifndef END_HPP_
#define END_HPP_

#include "Scene.hpp"

class End : public Scene {
    public:
        End(const std::string &);
        virtual ~End();

        void updateScene();
        void updateButton();
        void refresh();
        void generateDecor();
        void openFile();
        void loadSound(std::vector<std::string> txt);
    private:
      float time;

};

#endif /* !End_HPP_ */
