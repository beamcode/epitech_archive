/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Options
*/

#ifndef Options_HPP_
#define Options_HPP_

#include "Scene.hpp"

class Options : public Scene {
    public:
        Options(const std::string &);
        virtual ~Options();

        void updateScene();
        void updateButton();
        void refresh();
        void writeInFile();

    private:
        int volume;
        int time1;
        int time2;
        std::shared_ptr<_Sound> sound;
};

#endif /* !Options_HPP_ */
