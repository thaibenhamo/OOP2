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

namespace 
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
        else
        {
            if (player.getDir() == Direction::DownLeft || 
                player.getDir() == Direction::DownRight)
            {
                player.setDir(Direction::Down);
            }  
            if (player.getDir() == Direction::UpLeft || 
                player.getDir() == Direction::UpRight)
            {
                player.setDir(Direction::Up);
            }
            player.setPos(player.getPrevLoc());
        }
    }

    // player with coin
    void playerCoin(GameObject& p, GameObject& c)
    {
        Player& player = dynamic_cast<Player&>(p);
        Coin& coin = dynamic_cast<Coin&>(c);

        player.setGameData(Score, ADD_POINTS);
        coin.setIsDead(true);
        Resources::instance().playSound(SoundType::CollectCoin);
    }

    void playerSpeedGift(GameObject& p, GameObject& c)
    {
        Player& player = dynamic_cast<Player&>(p);
        SpeedGift& speedGift = dynamic_cast<SpeedGift&>(c);

        player.setGameData(Score, ADD_POINTS);
        player.setSuperSpeed(true);
        speedGift.setIsDead(true);
        Clock::instance().getSpeedGiftClock().restart();
        Resources::instance().playSound(SoundType::CollectGift);
    }

    void playerInvincibleGift(GameObject& p, GameObject& g)
    {
        Player& player = dynamic_cast<Player&>(p);
        BubbleGift& bubbleGift = dynamic_cast<BubbleGift&>(g);

        player.setInvincible(true);
        bubbleGift.setIsDead(true);
        Clock::instance().getBubbleGiftClock().restart();

        Resources::instance().playSound(SoundType::CollectGift);
    }

    void playerLifeGift(GameObject& p, GameObject& g)
    {
        Player& player = dynamic_cast<Player&>(p);
        LifeGift& lifeGift = dynamic_cast<LifeGift&>(g);

        if (player.getGameData()[Lives] != START_LIVES)
        {
            player.setGameData(Lives, 1);
        }
        lifeGift.setIsDead(true);

        Resources::instance().playSound(SoundType::CollectGift);
    }

    void playerEnemy(GameObject& p, GameObject&)
    {
        Player& player = dynamic_cast<Player&>(p);

        //for the player hit random enemy
        if (!player.getFlickering() && !player.getInvincible())
        {
            player.hittedByEnemy();
            Resources::instance().playSound(SoundType::EnemyHitPlayer);
        }
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

    // ----------------- nothing -----------------------
    void nothingShouldHappen(GameObject&, GameObject&)
    {}
    // ----------------- randomEnemy -----------------

    void randomEnemyWall(GameObject& m, GameObject& w)
    {
        RandomEnemy& randomEnemy = dynamic_cast<RandomEnemy&>(m);
        Wall& wall = dynamic_cast<Wall&>(w);

        sf::FloatRect wallBounds = wall.getSprite().getGlobalBounds();
        sf::FloatRect enemyBounds = randomEnemy.getSprite().getGlobalBounds();

        randomEnemy.setChangeDir(true);   
    }

    void randomEnemyArrow(GameObject& r, GameObject& a)
    {
        RandomEnemy& randomEnemy = dynamic_cast<RandomEnemy&>(r);
        Arrow& arrow = dynamic_cast<Arrow&>(a);

        if (arrow.getDir() != Direction::Stay)
        {
            arrow.setMakeCoin();
            arrow.setIsDead(true);
            randomEnemy.setPos(randomEnemy.getPrevLoc());
            randomEnemy.setIsDead(true);
            Resources::instance().playSound(SoundType::ArrowHitEnemy);     
        }
        else
        {
            randomEnemy.setChangeDir(true);
        }    
    }

    // ----------------- flyingEnemy -----------------

    void flyingEnemyWall(GameObject& g, GameObject&)
    {
        FlyingEnemy& flyingEnemy = dynamic_cast<FlyingEnemy&>(g);

        flyingEnemy.setPos(flyingEnemy.getPrevLoc());
        flyingEnemy.changeDir();
    }

    void flyingEnemyArrow(GameObject& f, GameObject& a)
    {
        FlyingEnemy& flyingEnemy = dynamic_cast<FlyingEnemy&>(f);
        Arrow& arrow = dynamic_cast<Arrow&>(a);
        
        if (arrow.getDir() != Direction::Stay)
        {
            arrow.setIsDead(true);
            flyingEnemy.setMakeCoin();
            flyingEnemy.setPos(flyingEnemy.getPrevLoc());
            flyingEnemy.setIsDead(true);
            Resources::instance().playSound(SoundType::ArrowHitEnemy);
        }
        else
        {
            flyingEnemy.setPos(flyingEnemy.getPrevLoc());
            flyingEnemy.changeDir();
        }   
    }

    void ArrowWall(GameObject& b, GameObject& w)
    {
        Arrow& arrow = dynamic_cast<Arrow&>(b);
        Wall& wall = dynamic_cast<Wall&>(w);

        if (arrow.getSprite().getScale().x == 1)
        {
            if (arrow.getPos().x + arrow.getSprite().getGlobalBounds().width / 2 - 10.f <
                wall.getSprite().getPosition().x - 20.f)
            {
                arrow.setDir(Direction::Stay);

                if (!arrow.getSoundPlayed())
                {
                    Resources::instance().playSound(SoundType::ArrowHitWall);
                    arrow.setSoundPlayed(true);
                }
            }
            else
            {
                arrow.setIsDead(true);
            }
        }
        else
        {
            if (arrow.getPos().x - arrow.getSprite().getGlobalBounds().width >
                wall.getSprite().getPosition().x + wall.getSprite().getGlobalBounds().width / 2 + 5.f)
            {
                arrow.setDir(Direction::Stay);
                if (!arrow.getSoundPlayed())
                {
                    Resources::instance().playSound(SoundType::ArrowHitWall);
                    arrow.setSoundPlayed(true);
                }
            }
            else
            {
                arrow.setIsDead(true);
            }
        }
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
        phm[MapKey(typeid(Player), typeid(RandomEnemy))] = &playerEnemy;
        phm[MapKey(typeid(Player), typeid(FlyingEnemy))] = &playerEnemy;
        phm[MapKey(typeid(Player), typeid(Arrow))] = &playerArrow;
        phm[MapKey(typeid(Player), typeid(SpeedGift))] = &playerSpeedGift;
        phm[MapKey(typeid(Player), typeid(BubbleGift))] = &playerInvincibleGift;
        phm[MapKey(typeid(Player), typeid(LifeGift))] = &playerLifeGift;

        phm[MapKey(typeid(FlyingEnemy), typeid(Wall))] = &flyingEnemyWall;
        phm[MapKey(typeid(FlyingEnemy), typeid(Arrow))] = &flyingEnemyArrow;
        phm[MapKey(typeid(FlyingEnemy), typeid(RandomEnemy))] = &nothingShouldHappen;
        phm[MapKey(typeid(FlyingEnemy), typeid(Coin))] = &nothingShouldHappen;
        phm[MapKey(typeid(FlyingEnemy), typeid(SpeedGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(FlyingEnemy), typeid(LifeGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(FlyingEnemy), typeid(BubbleGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(FlyingEnemy), typeid(FlyingEnemy))] = &nothingShouldHappen;
        phm[MapKey(typeid(FlyingEnemy), typeid(Player))] = &playerEnemy;

        phm[MapKey(typeid(RandomEnemy), typeid(Player))] = &playerEnemy;
        phm[MapKey(typeid(RandomEnemy), typeid(Wall))] = &randomEnemyWall;
        phm[MapKey(typeid(RandomEnemy), typeid(Arrow))] = &randomEnemyArrow;
        phm[MapKey(typeid(RandomEnemy), typeid(RandomEnemy))] = &nothingShouldHappen;
        phm[MapKey(typeid(RandomEnemy), typeid(FlyingEnemy))] = &nothingShouldHappen;
        phm[MapKey(typeid(RandomEnemy), typeid(Coin))] = &nothingShouldHappen;
        phm[MapKey(typeid(RandomEnemy), typeid(SpeedGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(RandomEnemy), typeid(LifeGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(RandomEnemy), typeid(BubbleGift))] = &nothingShouldHappen;

        phm[MapKey(typeid(Arrow), typeid(RandomEnemy))] = &nothingShouldHappen/*ArrowEnemy*/;
        phm[MapKey(typeid(Arrow), typeid(FlyingEnemy))] = &nothingShouldHappen/*ArrowEnemy*/;
        phm[MapKey(typeid(Arrow), typeid(Wall))] = &ArrowWall;
        phm[MapKey(typeid(Arrow), typeid(Arrow))] = &nothingShouldHappen;
        phm[MapKey(typeid(Arrow), typeid(SpeedGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(Arrow), typeid(LifeGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(Arrow), typeid(BubbleGift))] = &nothingShouldHappen;
        phm[MapKey(typeid(Arrow), typeid(Coin))] = &nothingShouldHappen;
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