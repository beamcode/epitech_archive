/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** test
*/

#include "Core.hpp"

#define GLSL_VERSION 330

Core::Core() : window(1920, 1080, "-= BomberMan =-")
{
    index = 1;
    std::shared_ptr<IScene> game(new Game("game"));
    sceneList.push_back(game);
    std::shared_ptr<Save> _save(new Save(std::dynamic_pointer_cast<Game>(sceneList[0])));
    save = _save;
    std::shared_ptr<IScene> menu(new Menu("menu", save));
    sceneList.push_back(menu);
    std::shared_ptr<IScene> options(new Options("options"));
    sceneList.push_back(options);
    std::shared_ptr<IScene> end(new End("end"));
    sceneList.push_back(end);
    std::shared_ptr<IScene> charactersChoices(new CharactersChoice("choice"));
    sceneList.push_back(charactersChoices);
}

Core::~Core()
{
    save->fillSave();
}

int Core::loop()
{
    while (!WindowShouldClose() && sceneList[index]->isClosed() == false) {
        update();
        draw();
    }
    return (0);
}

void Core::draw() const
{
    BeginDrawing();
    BeginMode3D(camera.get_camera());
    ClearBackground(RAYWHITE);
    sceneList[index]->drawScene3d();
    EndMode3D();
    sceneList[index]->drawScene2d();
    DrawFPS(10, 10);
    EndDrawing();
}

void Core::update()
{
    std::string scene;

    if (IsKeyReleased(KEY_P))
        camera.free_camera();
    camera.update_camera();
    sceneList[index]->updateScene();
    scene = sceneList[index]->changeScene();
    if (scene != "none") {
        for (size_t i = 0; i < sceneList.size(); ++i) {
            if (sceneList[i]->getName() == scene) {
                index = i;
                sceneList[index]->refresh();
            }
        }
    }
}
