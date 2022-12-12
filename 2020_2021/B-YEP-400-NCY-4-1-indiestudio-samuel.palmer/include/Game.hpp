/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Game
*/


#ifndef Game_HPP_
#define Game_HPP_

#include "Scene.hpp"

#define palm_obj "resources/models/palm.obj"
#define floor_obj "resources/models/floor.obj"

#define palm_txt_1 "resources/img/palm_trunk.png"
#define palm_txt_2 "resources/img/palm_leaves.png"
#define floor_txt "resources/img/floor.png"

class Game : public Scene {
    public:
        Game(const std::string &);
        virtual ~Game();

        void initPlayer();
        void initScoreboard();
        void generateDecor();
        void generateRandomMap();
        void loadMap(const std::string &file);
        void changeMap(const std::string &name);
        void drawScene3d() const;
        void updateScene();
        void generateBomb(std::shared_ptr<Player> player);
        void generateBonus();
        void destroyBomb();
        void destroyCrate(Vector3 pos, size_t i, std::shared_ptr<Bomb> bomb);
        void updateGameVariable();
        void checkWin();
        void refresh();
        void add_obj(const std::string &obj, const std::string &txt, Vector3 scale, Vector3 pos, int angle);

        //getter for save
        std::vector<std::vector<int>> getGrid() { return (grid);};
        int getCount() { return (count); };
        int getBoom() { return (boom); };
        float getBombTime() { return (bombTime); };
        std::vector<std::shared_ptr<Bomb>> getBombList() { return (bombList); };
        std::vector<std::shared_ptr<Crate>> getCrateList() { return (crateList); };
        std::string getMap() {  return (mapName); };
        //std::string

        //setter for save
        void setGrid(std::vector<std::vector<int>> _grid) { grid = _grid; };
        void setCount(int _count) { count = _count; };
        void setBoom(int _boom) { boom = _boom; text[0]->updateText(std::to_string(boom));};
        void setBombTime(float _bombTime) { bombTime = _bombTime; text[1]->updateText(std::to_string(bombTime));};
        void setBombList(std::vector<std::shared_ptr<Bomb>> _bombList) { bombList = _bombList; };
        void setCrateList(std::vector<std::shared_ptr<Crate>> _crateList) { crateList = _crateList; };
        void setMap(const std::string &_mapName) {  mapName = _mapName; changeMap(mapName); };
    private:
        std::vector<std::vector<int>> grid;
        std::vector<std::string> txt;
        std::vector<std::string> art;
        std::shared_ptr<GameVariable> var;
        int count;
        int boom;
        float bombTime;
        std::string mapName;
        std::vector<std::shared_ptr<Bomb>> bombList;
        std::vector<std::shared_ptr<Crate>> crateList;
        std::vector<std::shared_ptr<Fire>> fireList;
        std::vector<std::shared_ptr<Bonus>> bonusList;
};
#endif /* !Menu_HPP_ */
