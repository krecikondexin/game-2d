//
// Created by Root on 13.01.2018.
//

#include <iostream>
#include "Blocks/Player.h"


Player::Player(float cX, float cY, int cWidth, int cHeight, float cSpeed)
        : Dynamic(cX, cY, cWidth, cHeight, cSpeed) {
    setTypeOfEntity(PLAYER);
    setCollisionAble(CollisionEnum::CAN_BE_COLLIDET);
    if (texture.loadFromFile("resource/image/playerJMP.png")) {
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, getSpriteData().spriteWidth, getSpriteData().spriteHeight));
        sprite.setPosition(cX, cY);
    };
}

void Player::draw(std::shared_ptr<sf::RenderWindow> window) {
    switch (getStatus()) {
        case MOVING:
            switch (getDirection()) {
                case UP:
                    //y=94px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 96, 32, 32));
                    break;
                case DOWN:
                    //y=0px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 0, 32, 32));
                    break;
                case LEFT:
                    //y=32px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 32, 32, 32));
                    break;
                case RIGHT:
                    //y=64px
                    sprite.setTextureRect(sf::IntRect(getSpriteData().currentFrame * 32, 64, 32, 32));
                    break;
            };
            break;
        case IDLE:

            break;
        case STOP:
            //x=32 + value of dir(y)
            switch (getDirection()) {
                case UP:
                    //y=94px
                    sprite.setTextureRect(sf::IntRect(32, 96, 32, 32));
                    break;
                case DOWN:
                    //y=0px
                    sprite.setTextureRect(sf::IntRect(32, 0, 32, 32));
                    break;
                case LEFT:
                    //y=32px
                    sprite.setTextureRect(sf::IntRect(32, 32, 32, 32));
                    break;
                case RIGHT:
                    //y=64px
                    sprite.setTextureRect(sf::IntRect(32, 64, 32, 32));
                    break;
            };
            break;
    };
    window->draw(sprite);
}

void Player::update(const float dt) {
    if (getCollsionStatus() == IsCollidet::NO_COLLISION) {
        setPositions(getOldPositions());
    } else {
        setOldPositions(getPositions());

        sprite.setPosition(getPositions().x, getPositions().y);
    }

    switch (getStatus()) {
        case MOVING: {


            SpriteData tempSpriteData;
            tempSpriteData = getSpriteData();
            tempSpriteData.currentTime += dt;
            if (tempSpriteData.currentTime >= tempSpriteData.timeToNextFrame) {
                tempSpriteData.currentTime = 0;
                if (tempSpriteData.currentFrame >= tempSpriteData.numbersOfFrame) {
                    tempSpriteData.currentFrame = 0;
                } else {
                    tempSpriteData.currentFrame++;
                }
            }
            setSpriteData(tempSpriteData);
        }
            switch (getDirection()) {
                case UP:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveUp(dt);
                    break;
                case DOWN:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveDown(dt);
                    break;
                case LEFT:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveLeft(dt);
                    break;
                case RIGHT:
                    setStatus(MOVING);
                    idleTime = 0;
                    moveRight(dt);
                    break;
            };
            break;
        case IDLE:
            std::cout << "PLAYER: IDLE STATUS " << std::endl;

            break;
        case STOP:

            break;
    };

    if (getStatus() != IDLE) {
        idleTime += dt;
    }
}


void Player::input(std::shared_ptr<sf::Event> event) {
    // need change to switch()
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        setStatus(MOVING);
        setDirection(UP);
        return;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        setStatus(MOVING);
        setDirection(DOWN);
        return;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        setStatus(MOVING);
        setDirection(LEFT);
        return;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        setStatus(MOVING);
        setDirection(RIGHT);
        return;
    } else {
        if (idleTime > 8000000) {
            setStatus(IDLE);
        } else {
            setStatus(STOP);
        }
    }

}


