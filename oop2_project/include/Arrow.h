#pragma once
#include "MovingObject.h"

class Arrow : public MovingObject 
{
public:
    Arrow(sf::Vector2f location, Resources::Object object);
    ~Arrow();

    void update(sf::Time delta) override;
    void setSoundPlayed(bool played) { m_soundPlayed = played; }
    bool getSoundPlayed() const { return m_soundPlayed; }
    void setDir(const Direction dir) override;

private:
    bool m_soundPlayed = false;
};