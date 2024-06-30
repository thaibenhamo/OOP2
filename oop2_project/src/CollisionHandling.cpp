#pragma once
#include "CollisionHandling.h"
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <typeindex>
#include "Player.h"
#include "Wall.h"
#include "Coin.h"
#include "MovingObject.h"
#include "RandomEnemy.h"

namespace // anonymous namespace — the standard way to make function "static"
{
    // primary collision-processing functions

    // ----------------- player -----------------
    // player with wall
    void playerWall(GameObject& p, GameObject& w)
    {
        Player& player = dynamic_cast<Player&>(p);
        Wall& wall = dynamic_cast<Wall&>(w);

        //for the player landing on the wall
        if (player.getPos().y + PLAYER_HIGHT >= wall.getSprite().getPosition().y and
            player.getPos().y + PLAYER_HIGHT < wall.getSprite().getPosition().y + (PLAYER_HIGHT / MIN_SPACE) and
            player.getPos().y < wall.getSprite().getPosition().y + PLAYER_HIGHT) 
        {
            player.handleInput(RELEASE_ON_WALL);
            player.setOnWall(true);
        }  
    }

    // player with coin
    void playerCoin(GameObject& p, GameObject& c)
    {
        Player& player = dynamic_cast<Player&>(p);
        Coin& coin = dynamic_cast<Coin&>(c);

        player.setGameDate(Score, ADD_POINTS);
        coin.setIsDead(true);
        //Resources::instance().playSound(SoundType::CoinSound);
    }

    void playerRandomEnemy(GameObject& p, GameObject& r)
    {
        Player& player = dynamic_cast<Player&>(p);
        RandomEnemy& randomEnemy = dynamic_cast<RandomEnemy&>(r);

        //for the player hit random enemy
        //if(player.getFlickering())
            player.reduceLife();
    }

    using HitFunctionPtr = void (*)(GameObject&, GameObject&);
    using MapKey = std::pair<std::type_index, std::type_index>;
    using HitMap = std::map<MapKey, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        //----------------- player collision ------------------------
        phm[MapKey(typeid(Player), typeid(Wall))] = &playerWall;
        phm[MapKey(typeid(Player), typeid(Coin))] = &playerCoin;
        phm[MapKey(typeid(Player), typeid(RandomEnemy))] = &playerRandomEnemy;
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(GameObject& object1, GameObject& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
    if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }
    phf(object1, object2);
}