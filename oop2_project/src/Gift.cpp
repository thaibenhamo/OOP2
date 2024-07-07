#pragma once
#include "Gift.h"
#include "SpeedGift.h"
#include "LifeGift.h"
#include "BubbleGift.h"

static auto registerIt = Factory<StaticObject>::instance().registerType(
    ObjectType::GiftChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<StaticObject>
    {
        //get a random gift
        object = Resources::Object((rand() % 3) + int(object));

        if (object == Resources::SpeedGift)
        {
            return std::make_unique<SpeedGift>(position, object);
        }
        else if (object == Resources::BubbleGift)
        {
            return std::make_unique<BubbleGift>(position, object);
        }
        else
        {
            return std::make_unique<LifeGift>(position, object);
        }
    }
);

void Gift::startGiftTime()
{
    m_timeGiftClock.restart();
    m_isOn = true;
}
