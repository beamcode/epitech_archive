/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** game
*/

#include "Game.hpp"
#include "Save.hpp"

Game::Game(const std::string &name) : Scene(name)
{
    addMusic("resources/audio/gamemusic.ogg");
    music[0]->set_volume(0.1);
    boom = 1;
    bombTime = 3;
    count = 1;
    addSprite("resources/img/box.png", 800, 100, RAYWHITE, 9);
    addSprite("resources/img/bomb2.png", 800, 0, RAYWHITE, 9);
    addText("resources/fonts/font.ttf", std::to_string(boom), 920, 140, 40);
    addText("resources/fonts/font.ttf", std::to_string(bombTime), 920, 50, 40);
    generateDecor();
    generateRandomMap();
    addSkybox(1.0f, 1.0f, 1.0f, "resources/img/skybox.png");
    initPlayer();
    initScoreboard();
}

Game::~Game()
{
}

void Game::initScoreboard()
{
    std::shared_ptr<Scoreboard> scOne(new Scoreboard());
    std::shared_ptr<Scoreboard> scTwo(new Scoreboard());
    std::shared_ptr<Scoreboard> scThree(new Scoreboard());
    std::shared_ptr<Scoreboard> scFour(new Scoreboard());
    scOne->playerOne();
    scTwo->playerTwo();
    scThree->playerThree();
    scFour->playerFour();
    sc.push_back(scOne);
    sc.push_back(scTwo);
    sc.push_back(scThree);
    sc.push_back(scFour);
}

void Game::generateDecor()
{
    add_obj(floor_obj, floor_txt, Vector3{0.5, 0.5, 0.5}, Vector3{5, -1, 5}, 0);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, 16}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, 25}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{16, 0, 3}, 90);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, -3}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{5, 0, -12}, 0);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
    add_obj(palm_obj, palm_txt_1, Vector3{0.6, 0.6, 0.6}, Vector3{-3, 0, 5}, 90);
    model[model.size() - 1]->load_texture(palm_txt_2, 1);
}

void Game::add_obj(const std::string &obj, const std::string &txt, Vector3 scale, Vector3 pos, int angle)
{
    addModel(obj, txt);
    model[model.size() - 1]->set_scale(scale);
    model[model.size() - 1]->set_pos(pos);
    model[model.size() - 1]->set_angle(angle);
}

void Game::loadMap(const std::string &file)
{
    int i = 0;
    std::string line;
    std::ifstream myfile(file);
    while (getline(myfile,line)) {
        for (size_t t = 0; t < line.size(); t++) {
            char tmp = line[t];
            int z = tmp - 48;
            grid[t].at(i) = z;
            if (z == 4) {
                std::shared_ptr<Crate> crate(new Crate("resources/models/crate.obj", "resources/img/crate.png"));
                crate->set_pos(i + 0.5, 0, t + 0.5);
                crate->set_scale(0.495, 0.495, 0.495);
                crateList.push_back(crate);
            }
        }
        grid.push_back(grid[i]);
        i++;
    }
}

void Game::changeMap(const std::string &name)
{
    std::string open;
    if (name == "map/map1.txt")
        open = "resources/img/map1.png";
    if (name == "map/map2.txt")
        open = "resources/img/map2.png";
    if (name == "map/map3.txt")
        open = "resources/img/map3.png";
    if (name == "map/map4.txt")
        open = "resources/img/map4.png";
    map->changeMap(open);
    loadMap(name);
}

void Game::generateRandomMap()
{
    addMap();
    std::string name = map->getName();
    std::string open;
    grid = std::vector<std::vector<int>> (13, std::vector<int> (13, 0));
    if (name == "resources/img/map1.png")
        open = "map/map1.txt";
    if (name == "resources/img/map2.png")
        open = "map/map2.txt";
    if (name == "resources/img/map3.png")
        open = "map/map3.txt";
    if (name == "resources/img/map4.png")
        open = "map/map4.txt";
    mapName = open;
    loadMap(open);
}
void Game::initPlayer()
{
    std::shared_ptr<Player> player1(new Player("resources/models/steve/steve.iqm", "resources/img/skin2.png"));
    playerList.push_back(player1);
    std::shared_ptr<Player> player2(new Player("resources/models/steve/steve.iqm", "resources/img/skin2.png"));
    playerList.push_back(player2);
    std::shared_ptr<Player> ia1(new IA("resources/models/steve/steve.iqm", "resources/img/skin2.png"));
    playerList.push_back(ia1);
    std::shared_ptr<Player> ia2(new IA("resources/models/steve/steve.iqm", "resources/img/skin2.png"));
    playerList.push_back(ia2);
    player1->set_pos(1.5f, 0.0f, 1.5f);
    player2->set_pos(11.5f, 0.0f, 11.5f);
    player1->setGrid(grid);
    player2->setGrid(grid);
    ia1->set_pos(1.5f, 0.0f, 11.5f);
    ia2->set_pos(11.5f, 0.0f, 1.5f);
    ia1->setGrid(grid);
    ia2->setGrid(grid);
}

void Game::generateBomb(std::shared_ptr<Player> player)
{
    Vector3 pos = player->get_pos();
    if (grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x)) != 0)
        return;
    float posx = static_cast<int>(pos.x) + 0.5;
    float posz = static_cast<int>(pos.z) + 0.5;
    std::shared_ptr<Bomb> bomb(new Bomb("resources/models/bomb.obj", "resources/img/bombtext.png", count));
    bomb->set_pos(posx, 0, posz);
    bomb->set_scale(0.2, 0.2, 0.2);
    bomb->playSound();
    player->hasPlacedBomb(bomb);
    player->setScore(50);
    grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x)) = 2;
    bombList.push_back(bomb);
    count++;
}

void Game::destroyCrate(Vector3 pos, size_t i, std::shared_ptr<Bomb> bomb)
{
    int tmp = 0;
    for (size_t t = 0; t < playerList.size(); ++t) {
        if (playerList[t]->hasBomb(bomb) == true)
            tmp = t;
    }
    if ((pos.z + i) < 13 && grid.at(static_cast<int>(pos.z) + i).at(static_cast<int>(pos.x)) != 1) {
            if (grid.at(static_cast<int>(pos.z) + i).at(static_cast<int>(pos.x)) == 4) {
                grid.at(static_cast<int>(pos.z) + i).at(static_cast<int>(pos.x)) = 0;
                for (size_t a = 0; a < crateList.size(); a++) {
                    Vector3 p = crateList[a]->get_pos();
                    if (pos.x == p.x && pos.z + i == p.z) {
                        std::shared_ptr<Fire> fire(new Fire("resources/models/fire.obj", "resources/img/fire.png"));
                        fire->set_pos(p.x, 0, p.z);
                        fireList.push_back(fire);
                        crateList.erase(crateList.begin() + a);
                        playerList[tmp]->setScore(25);
                    }
                }
            }
            else
                grid.at(static_cast<int>(pos.z) + i).at(static_cast<int>(pos.x)) = 0;
    }
    if ((pos.z - i) > 0 && grid.at(static_cast<int>(pos.z) - i).at(static_cast<int>(pos.x)) != 1) {
            if (grid.at(static_cast<int>(pos.z) - i).at(static_cast<int>(pos.x)) == 4) {
                grid.at(static_cast<int>(pos.z) - i).at(static_cast<int>(pos.x)) = 0;
                for (size_t a = 0; a < crateList.size(); a++) {
                    Vector3 p = crateList[a]->get_pos();
                    if (pos.x == p.x && pos.z - i == p.z) {
                        std::shared_ptr<Fire> fire(new Fire("resources/models/fire.obj", "resources/img/fire.png"));
                        fire->set_pos(p.x, 0, p.z);
                        fireList.push_back(fire);
                        crateList.erase(crateList.begin() + a);
                        playerList[tmp]->setScore(25);
                    }
                }
            }
            else
                grid.at(static_cast<int>(pos.z) - i).at(static_cast<int>(pos.x)) = 0;
    }
    if ((pos.x + i) < 13 && grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) + i) != 1) {
            if (grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) + i) == 4) {
                grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) + i) = 0;
                for (size_t a = 0; a < crateList.size(); a++) {
                    Vector3 p = crateList[a]->get_pos();
                    if (pos.x + i == p.x && pos.z == p.z) {
                        std::shared_ptr<Fire> fire(new Fire("resources/models/fire.obj", "resources/img/fire.png"));
                        fire->set_pos(p.x, 0, p.z);
                        fireList.push_back(fire);
                        crateList.erase(crateList.begin() + a);
                        playerList[tmp]->setScore(25);
                    }
                }
            }
            else
                grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) + i) = 0;
    }
    if ((pos.x - i) > 0 && grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) - i) != 1) {
            if (grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) - i) == 4) {
                grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) - i) = 0;
                for (size_t a = 0; a < crateList.size(); a++) {
                    Vector3 p = crateList[a]->get_pos();
                    if (pos.x - i == p.x && pos.z == p.z) {
                        std::shared_ptr<Fire> fire(new Fire("resources/models/fire.obj", "resources/img/fire.png"));
                        fire->set_pos(p.x, 0, p.z);
                        fireList.push_back(fire);
                        crateList.erase(crateList.begin() + a);
                        playerList[tmp]->setScore(25);
                    }
                }
            }
            else
                grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x) - i) = 0;
    }
    for (size_t t = 0; t < playerList.size(); ++t)
        playerList[t]->setGrid(grid);
}

void Game::destroyBomb()
{
    for (size_t i = 0; i < bombList.size(); ++i) {
        if (bombList[i]->timeToDestroy() == true && bombList[i]->destroy() == true) {
            Vector3 pos = bombList[i]->get_pos();
            for (int z = 1; z <= boom; z++) {
                destroyCrate(pos, z, bombList[i]);
                for (size_t t = 0; t < playerList.size(); t++) {
                    if (playerList[t]->hasKilledPlayer(pos, z) == true && playerList[t]->isDead() == false) {
                        if (playerList[t]->hasBomb(bombList[i]) == true)
                            playerList[t]->setScore(200);
                    }
                }
            }
            grid.at(static_cast<int>(pos.z)).at(static_cast<int>(pos.x)) = 0;
            bombList.erase(bombList.begin());
        }
    }
}

void Game::checkWin()
{
    int count = 0;
    size_t t = 0;

    for (size_t i = 0; i < playerList.size(); i++) {
        if (playerList[i]->isDead() == false) {
            count++;
            t = i;
        }
    }
    if (count == 1) {
        std::ofstream myfile;
        myfile.open ("saves/winner.txt");
        myfile << playerList[t]->getTexture() << std::endl;
        myfile << art[t] << std::endl;
        myfile << playerList[t]->getScore() << std::endl;
        myfile << t << std::endl;
        newscene = "end";
    }
}

void Game::updateGameVariable()
{
    playerList[0]->movePlayerOne();
    playerList[1]->movePlayerTwo();
    playerList[2]->moveIA();
    playerList[3]->moveIA();
    if (var->boomDistance() == true) {
        boom++;
        text[0]->updateText(std::to_string(boom));
    }
    if (var->bombTime() == true) {
        if (bombTime != 0.5)
            bombTime -= 0.5;
        for (size_t t = 0; t < playerList.size(); ++t)
            playerList[t]->setTimeBomb(bombTime);
        text[1]->updateText(std::to_string(bombTime));
    }
    for (size_t i = 0; i < fireList.size(); ++i) {
        if (fireList[i]->timeToStop() == true)
            fireList.erase(fireList.begin() + i);
    }
}

void Game::generateBonus()
{
    int x = rand() % 12;
    int z = rand() % 12;
    if (rand() % 200 == 1 && grid.at(z).at(x) == 0)  {
        std::shared_ptr<Bonus> bonus(new Bonus("resources/models/bonus_star.obj", "resources/img/bonus_star.png", 1));
        bonus->set_pos(z + 0.5, 0, x + 0.5);
        bonusList.push_back(bonus);
    }
    if (rand() % 300 == 2 && grid.at(z).at(x) == 0) {
        std::shared_ptr<Bonus> bonus(new Bonus("resources/models/crate.obj", "resources/img/bonus_box.png", 2));
        bonus->set_pos(z + 0.5, 0, x + 0.5);
        bonus->set_scale(0.3, 0.3, 0.3);
        bonusList.push_back(bonus);
    }
    for (size_t t = 0; t < playerList.size(); ++t) {
        for (size_t i = 0; i < bonusList.size(); ++i) {
            if (bonusList[i]->hasPlayerOn(playerList[t]) == true) {
                playerList[t]->applyBonus(bonusList[i]);
                bonusList.erase(bonusList.begin() + i);
            }
        }
        playerList[t]->bonusHasEnd();
    }
}

void Game::updateScene()
{
    for (size_t i = 0; i < sc.size(); ++i) {
        float time = playerList[i]->timeToBomb();
        sc[i]->update(time, playerList[i]->getScore());
    }
    updateGameVariable();
    generateBonus();
    if (IsKeyDown(KEY_SPACE) && playerList[0]->canPlaceBomb() == true && playerList[0]->isDead() == false)
        generateBomb(playerList[0]);
    if (IsKeyDown(KEY_Q) && playerList[1]->canPlaceBomb() == true && playerList[1]->isDead() == false)
        generateBomb(playerList[1]);
    if ((rand() % 400 == 0) && playerList[2]->canPlaceBomb() == true && playerList[2]->isDead() == false)
        generateBomb(playerList[2]);
    if ((rand() % 400 == 1) && playerList[3]->canPlaceBomb() == true && playerList[3]->isDead() == false)
        generateBomb(playerList[3]);
    destroyBomb();
    checkWin();
    for (size_t i = 0; i < music.size(); i++)
        music[i]->update_music();
}

void Game::drawScene3d() const
{
    for (size_t i = 0; i < skybox.size(); ++i)
        skybox[i]->draw();
    map->draw();
    for (size_t i = 0; i < model.size(); ++i)
        model[i]->draw();
    for (size_t i = 0; i < bombList.size(); ++i)
        bombList[i]->draw();
    for (size_t i = 0; i < crateList.size(); i++)
        crateList[i]->draw();
    for (size_t i = 0; i < fireList.size(); ++i)
        fireList[i]->draw();
    for (size_t i = 0; i < bonusList.size(); ++i)
        bonusList[i]->draw();
    for (size_t i = 0; i < playerList.size(); ++i) {
        if (playerList[i]->isDead() == false)
            playerList[i]->draw();
    }
}

void Game::refresh()
{
    std::string line;
    std::ifstream myfile ("saves/char.txt");
    std::ifstream artw ("saves/artwork.txt");
    std::ifstream set ("saves/settings.txt");
    std::vector<std::string> v;
    std::shared_ptr<GameVariable> _var(new GameVariable());
    var = _var;

    if (myfile.is_open()) {
      while (getline(myfile,line))
          txt.push_back(line);
      myfile.close();
    }
    if (artw.is_open()) {
      while (getline(artw,line))
          art.push_back(line);
      artw.close();
    }
    if (set.is_open()) {
      while (getline(set,line))
          v.push_back(line);
      set.close();
    }
    int range = stoi(v[1]);
    int delay = stoi(v[2]);
    var->setRange(range);
    var->setDelay(delay);
    for (size_t i = 0; i < playerList.size(); ++i) {
        playerList[i]->load_texture(txt[i], 0);
        sc[i]->changeArtwork(art[i]);
    }
}
