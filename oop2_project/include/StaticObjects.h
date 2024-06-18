#pragma once
#include "GameObject.h"


class StaticObjects : public GameObject {

public:
	using GameObject::GameObject;
	virtual ~StaticObjects() = default;

	StaticObjects(const StaticObjects&) = default;
	StaticObjects& operator=(const StaticObjects&) = default;
	StaticObjects(StaticObjects&&) = default;
	StaticObjects& operator=(StaticObjects&&) = default;

private:

};
