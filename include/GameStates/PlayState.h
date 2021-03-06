//
// Created by Streaming on 2017-12-13.
//

#ifndef SFML_GAME_PLAYSTATE_H
#define SFML_GAME_PLAYSTATE_H

#include <Blocks/Player.h>
#include <Blocks/Rat.h>
#include <Blocks/Ground.h>
#include "GameState.h"
#include "Buttoms/Button.h"
#include "Systems/CollisionChecker.h"
#include "Systems/CreatureSpawner.h"
#include "Blocks/Water.h"
class PlayState : public GameState
{
private:
    sf::Vector2i currentOffSet;
    sf::View viewe;
    bool gridMapCollision[320][180];
    std::shared_ptr<sf::Event> event;
    std::shared_ptr<Rat> simpleRat;
    std::shared_ptr<CreatureSpawner> cSpawner;
    CollisionChecker ch;
    std::shared_ptr<Player> player;
    std::vector<std::shared_ptr<Entity>> mapEntity;
public:
    ~PlayState();
    void draw();
    void update(const float dt);
    void input();
    PlayState(std::shared_ptr<Game> game);

};


#endif //SFML_GAME_PLAYSTATE_H
