/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Choice
*/

#ifndef Choice_HPP_
#define Choice_HPP_

#include "Scene.hpp"

class CharactersChoice : public Scene {
    public:
        CharactersChoice(const std::string &);
        virtual ~CharactersChoice();

        void updateScene();
        void updateButton();
        void loadModelSkin();
        void loadButtonSprite();
        void loadArtworkSprite();
        void loadSound();
        void loadModel();
        void saveCharacter();
        void refresh();
        void animateButtons();
        void generateDecor();
        void add_obj(std::string obj, std::string txt, Vector3 scale, Vector3 pos, int angle);

    private:
      std::vector<std::string> skinList;
      int index1;
      int index2;
      int index3;
      int index4;
      std::vector<std::string> artworkList;
      std::shared_ptr<_Sound> sound;
      std::vector<std::string> soundList;

};

#endif /* !Choice_HPP_ */
