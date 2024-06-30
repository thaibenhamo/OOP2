#pragma once
#include "GameObject.h"
#include "StaticObject.h"
#include "Factory.h"

StaticObject::StaticObject(sf::Vector2f location, Resources::Object object)
	: GameObject(location, object)
{
	m_sprite.setTexture(Resources::instance().get(object));
	m_sprite.setOrigin(m_sprite.getGlobalBounds().width / 2.f,
					   m_sprite.getGlobalBounds().height / 2.f);
}
