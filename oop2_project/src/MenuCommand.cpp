#include "MenuCommand.h"

MenuCommand::MenuCommand()
{
    m_backButton = std::make_unique<Button>(sf::Vector2f(347, 70), BackButton);
}