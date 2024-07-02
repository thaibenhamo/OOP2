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
#include "FlyingEnemy.h"
#include "Arrow.h"
#include "SpeedGift.h"
#include "BubbleGift.h"
#include "LifeGift.h"

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
        if (player.getPos().y + PLAYER_HIGHT / 2 <= wall.getSprite().getPosition().y - TOP_WALL)
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

    void playerSpeedGift(GameObject& p, GameObject& c)
    {
        Player& player = dynamic_cast<Player&>(p);
        SpeedGift& speedGift = dynamic_cast<SpeedGift&>(c);

        player.setGameDate(Score, ADD_POINTS);
        player.setSuperSpeed(true);
        speedGift.setIsDead(true);

        //Resources::instance().playSound(SoundType::SpeedGiftSound);
    }

    void playerInvincibleGift(GameObject& p, GameObject& g)
    {
        Player& player = dynamic_cast<Player&>(p);
        BubbleGift& bubbleGift = dynamic_cast<BubbleGift&>(g);

        player.setInvincible(true);
        bubbleGift.setIsDead(true);

        //Resources::instance().playSound(SoundType::SpeedGiftSound);
    }

    void playerLifeGift(GameObject& p, GameObject& g)
    {
        Player& player = dynamic_cast<Player&>(p);
        LifeGift& lifeGift = dynamic_cast<LifeGift&>(g);

        player.setGameDate(Lives, 1);
        lifeGift.setIsDead(true);

        //Resources::instance().playSound(SoundType::SpeedGiftSound);
    }

    void playerRandomEnemy(GameObject& p, GameObject& )
    {
        Player& player = dynamic_cast<Player&>(p);
        //RandomEnemy& randomEnemy = dynamic_cast<RandomEnemy&>(r);

        //for the player hit random enemy
        if (!player.getFlickering() && !player.getInvincible())
        {
            player.reduceLife();
        }
    }

    void playerFlyingEnemy(GameObject& p, GameObject&)
    {
        Player& player = dynamic_cast<Player&>(p);
        //FlyingEnemy& flyingEnemy = dynamic_cast<FlyingEnemy&>(r);

        //for the player hit random enemy
        if (!player.getFlickering() && !player.getInvincible())
            player.reduceLife();

    }

    void playerArrow(GameObject& p, GameObject& a)
    {
        Player& player = dynamic_cast<Player&>(p);
        Arrow& arrow = dynamic_cast<Arrow&>(a);

        if (player.getPos().y + DIF_PLAYER_ARROW <= arrow.getPos().y)
        {
            player.handleInput(RELEASE_ON_WALL);
            player.setOnWall(true);
        }
    }
    // ----------------- randomEnemy -----------------

    void randomEnemyWall(GameObject& m, GameObject& w)
    {
        RandomEnemy& randomEnemy = dynamic_cast<RandomEnemy&>(m);
        Wall& wall = dynamic_cast<Wall&>(w);

        //check if the enemy is on the wall
        //check if the enemy is on the wall
        if (wall.getSprite().getGlobalBounds().contains(randomEnemy.getSprite().getPosition().x - randomEnemy.getSprite().getGlobalBounds().width,
            randomEnemy.getSprite().getPosition().y + randomEnemy.getSprite().getGlobalBounds().height)) 
        {
            randomEnemy.setChangeDir(false);
        }
        else if (wall.getSprite().getGlobalBounds().contains(randomEnemy.getSprite().getPosition().x + randomEnemy.getSprite().getGlobalBounds().width,
            randomEnemy.getSprite().getPosition().y + randomEnemy.getSprite().getGlobalBounds().height)) 
        {
            randomEnemy.setChangeDir(false);
        }
    }

    void randomEnemyArrow(GameObject& r, GameObject& a)
    {
        RandomEnemy& randomEnemy = dynamic_cast<RandomEnemy&>(r);
        Arrow& arrow = dynamic_cast<Arrow&>(a);

        arrow.setIsDead(true);
        randomEnemy.setCurrPos(randomEnemy.getPrevLoc());
        randomEnemy.handleEnemyDeath();
        //Resources::instance().playSound(SoundType::DeathRandomEnemySound);
    }

    // ----------------- flyingEnemy -----------------

    void flyingEnemyWall(GameObject& g, GameObject&)
    {
        FlyingEnemy& flyingEnemy = dynamic_cast<FlyingEnemy&>(g);

        flyingEnemy.setCurrPos(flyingEnemy.getPrevLoc());
        flyingEnemy.changeDir();
    }

    void flyingEnemyArrow(GameObject& f, GameObject&)
    {
        FlyingEnemy& flyingEnemy = dynamic_cast<FlyingEnemy&>(f);
        //Arrow& arrow = dynamic_cast<Arrow&>(a);

        flyingEnemy.setCurrPos(flyingEnemy.getPrevLoc());
        flyingEnemy.handleEnemyDeath();
        //Resources::instance().playSound(SoundType::DeathflyingEnemySound);
    }

    // ----------------- Arrow -----------------

    void ArrowEnemy(GameObject& b, GameObject&)
    {
        Arrow& arrow = dynamic_cast<Arrow&>(b);

        arrow.setIsDead(true);
    }

    void ArrowWall(GameObject& b, GameObject&)
    {
        Arrow& arrow = dynamic_cast<Arrow&>(b);
        //Wall& wall = dynamic_cast<Wall&>(w);

        arrow.setDir(Direction::Stay);

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
        phm[MapKey(typeid(Player), typeid(FlyingEnemy))] = &playerFlyingEnemy;
        phm[MapKey(typeid(Player), typeid(Arrow))] = &playerArrow;
        phm[MapKey(typeid(Player), typeid(SpeedGift))] = &playerSpeedGift;
        phm[MapKey(typeid(Player), typeid(BubbleGift))] = &playerInvincibleGift;
        phm[MapKey(typeid(Player), typeid(LifeGift))] = &playerLifeGift;

        phm[MapKey(typeid(FlyingEnemy), typeid(Wall))] = &flyingEnemyWall;
        phm[MapKey(typeid(FlyingEnemy), typeid(Arrow))] = &flyingEnemyArrow;

        phm[MapKey(typeid(RandomEnemy), typeid(Wall))] = &randomEnemyWall;
        phm[MapKey(typeid(RandomEnemy), typeid(Arrow))] = &randomEnemyArrow;

        phm[MapKey(typeid(Arrow), typeid(RandomEnemy))] = &ArrowEnemy;
        phm[MapKey(typeid(Arrow), typeid(FlyingEnemy))] = &ArrowEnemy;
        phm[MapKey(typeid(Arrow), typeid(Wall))] = &ArrowWall;
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