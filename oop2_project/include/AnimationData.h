#pragma once
#include "Macros.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

struct AnimationData
{
    using ListType = std::vector<sf::IntRect>;
    using DataType = std::unordered_map<AnimationState, ListType>;
    DataType m_data;
};
