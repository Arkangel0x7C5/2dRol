#ifndef CHARACTER_H
#define CHARACTER_H

#include <gameobject.h>
#include <terrain.h>
#include <Interfaces/objectfactory.h>
#include <animateterrain.h>

class Character;

class CharacterCtor:public ObjectCtor<GameObject>{
    public:
        CharacterCtor(std::string cfgPath);
        virtual GameObject* create() override;
    private:
        std::string m_cfgPath;
};

class Character:public GameObject{
    public:
        Character();
        virtual drawable* getDrawable() override;
        virtual Rect2D boundBox() override;
        virtual externAnimation* animation() override;

        Terrain *terrain() const;
        void setTerrain(Terrain *terrain);
        void addAnimation(const std::string& name,AnimateTerrain* animation);

        Point2d direction() const;
        void setDirection(const Point2d &d);

    private:
        PropertyInt m_life;
        PropertyInt m_maxLife;

        Terrain* m_terrain;
        Point2d m_vecDirector;
        std::map<std::string,AnimateTerrain*> m_animations;

};



#endif // CHARACTER_H
