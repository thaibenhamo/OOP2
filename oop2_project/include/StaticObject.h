#pragma once
#include "GameObject.h"


class StaticObject : public GameObject {

public:
	StaticObject(sf::Vector2f location, Resources::Object object);
	virtual ~StaticObject() = default;

private:

};
