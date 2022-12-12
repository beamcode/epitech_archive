/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Scene
*/

#ifndef Scene_HPP_
#define Scene_HPP_

#include "IScene.hpp"

class Save;

/** @brief Class that manage scene

    @date June 2021
    */
class Scene : public IScene {
    public:
         /** My constructor. Initializes scene.
        @param string - name of the scene
        */
        
        Scene(const std::string &);
        
        /** My second constructor. Initializes scene.
        @param string - name of the scene
        @param shared_ptr - ptr to previous save scene
        */
    
        Scene(const std::string &, std::shared_ptr<Save>);
        
        virtual ~Scene();
         /**Draw the 3D scene
        */
        virtual void drawScene3d() const;
        /**Draw the 2D scene
        */
        virtual void drawScene2d() const;
        /**Update the actual scene
        */
        virtual void updateScene() = 0;
        /**Refresh the scene
        */
        virtual void refresh() = 0;
        /**Add a new music to the scene
        */
        void addMusic(const std::string &path);
        /**Add a skybox to the scene
        @param path - the path of the ressource file
        @param width - width of the skybox  
        @param height - height of the skybox
        @param lenght - lenght of the skybox
        */
        void addSkybox(float width, float height, float lenght, const std::string &path);
        
        /**Add a Map to the scene
        */
        
        void addMap();
        
        /**Add a Model to the scene
         @param a - is the obj
         @param b - is the texture
        */
        
        void addModel(const std::string &a, const std::string &b);
        
        /** add sprite to the scene
        @param path - the path of the ressource file
        @param x - x coordinate of the point
        @param y - y coordinate of the point 
        @param color - color color of the sprite 
        @param index - index of the sprite
        */

        void addSprite(const std::string &path, int x, int y, Color color, int index);
        /**Add text to the scene
        @param fontPath - the path of the ressource file
        @param txt - the path of the txt ressource file
        @param x - x coordinate of the point
        @param y - y coordinate of the point 
        @param fontSize - size of the font
        */

        void addText(const std::string &fontPath, const std::string &txt, float x, float y, int fontSize);
        
        /**Name getter
        @return name of the actual scene
        */
        
        std::string getName() const;
        
        /**Change scene
        @return the scene dto be display
        */
        
        std::string changeScene() const;
        
        /**check if the scene is closed
        @return true if the game should be close closed
        */
        
        bool isClosed() const;

    protected:
        std::vector<std::shared_ptr<_Music>> music;/**<Vector for all music*/
        std::vector<std::shared_ptr<_Skybox>> skybox;/**<Vector for all skybox*/
        std::vector<std::shared_ptr<Sprite>> sprite;/**<Vector for all sprite*/
        std::vector<std::shared_ptr<Player>> playerList;/**<Vector for all player*/
        std::vector<std::shared_ptr<Scoreboard>> sc;/**<Vector for all scoreboard*/
        std::vector<std::shared_ptr<_Model>> model;/**<Vector for all model*/
        std::vector<std::shared_ptr<Text>> text;/**<Vector for all text*/
        std::shared_ptr<_Map> map;/**<ptr for actual map*/
        std::shared_ptr<Event> event;/**<ptr for actual event*/
        std::shared_ptr<Save> save;/**<ptr for actual saving config*/
        std::string name;/**<name for the obj*/
        std::string newscene;/**<name for the new name*/
        bool close;/**<bool to check if the scene is close*/
};

#include "Save.hpp"
#endif /* !Scene_HPP_ */
