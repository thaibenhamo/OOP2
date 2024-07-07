#pragma once
#include "MovingObject.h"

class Arrow : public MovingObject 
{
public:
    Arrow(sf::Vector2f location, Resources::Object object, float scale);
    ~Arrow();

    void update(sf::Time delta) override;
    void setSoundPlayed(bool played) { m_soundPlayed = played; }
    bool getSoundPlayed() const { return m_soundPlayed; }

private:
    bool m_soundPlayed = false;
};