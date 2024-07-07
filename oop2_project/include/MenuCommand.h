#pragma once

#include <memory>
#include "Button.h"

class MenuCommand
{
public:
    MenuCommand();
    virtual bool execute(sf::RenderWindow& window, int& numOfLevel) = 0;
    virtual ~MenuCommand() = default;

    virtual void handleMove(const sf::Vector2f& location) = 0;
    virtual bool handleClick(const sf::Vector2f& location, int& numOfLevel) = 0;
    virtual void show(sf::RenderWindow& window) const = 0;

protected:
    std::unique_ptr<Button> m_backButton;
    bool m_inMenu = true;
};

