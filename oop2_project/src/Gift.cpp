#pragma once
#include "Gift.h"
#include "SpeedGift.h"

static auto registerIt = Factory<StaticObject>::instance().registerType(
    ObjectType::GiftChar,
    [](sf::Vector2f position, Resources::Object object) -> std::unique_ptr<StaticObject>
    {
        //מגריל סוג המתנה וכך בהתאם שולח את הסוג המתאים עם התמונה המתאימה
        return std::make_unique<SpeedGift>(position, object);
    }
);