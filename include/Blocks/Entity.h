//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_ENTITY_H
#define SFML_GAME_ENTITY_H

#include "SFML/Graphics.hpp"
#include <memory>
#include <iostream>
enum CollisionEnum
{
    CAN_BE_COLLIDET=0,
    CAN_NOT_BE_COLLIDET=1
};

struct SpriteData
{
    int timeToNextFrame=300000; //1000000 = 1s
    int currentTime=0;
    int numbersOfFrame=2;
    int currentFrame=0;
    int spriteWidth=32;
    int spriteHeight=32;
    int spriteOffsetX=0;
    int spriteOffsetY=0;
};
struct Positions
{
    float x=0;
    float y=0;
    int width=32;
    int height=32;
    float xCollision;
    float yCollision;
    float xCollisionWidth;
    float yCollisionHeight;
    Positions & operator =( const Positions & right );
};

class Entity
{
private:
    int id;
    CollisionEnum collisionStatus=CAN_NOT_BE_COLLIDET;
    CollisionEnum collisionAble=CAN_NOT_BE_COLLIDET;
public:
    Positions positions;
    Entity()= delete;
    Entity( float cX,  float cY,  int cWidth,  int cHeight);
    virtual ~Entity();
    virtual void draw(std::shared_ptr<sf::RenderWindow> window) =0;
    virtual void update(const float dt)=0;
    //virtual void input(std::shared_ptr<sf::Event> event)=0;
    void setEntityID(int i);
    int getEntityID();
    bool getCollsionStatus();
    void setCollisionStatus(CollisionEnum newCollisionStatus);
    bool isCollisionAble();
    void setCollisionAble(CollisionEnum newCollisionAble);
};

#endif //SFML_GAME_ENTITY_H
