#pragma once
#include "GameObject.h"
#include <unordered_map>

template <typename T>
class Factory
{
public:
    static Factory& instance()
    {
        static auto instance = Factory();
        return instance;
    }

    using FuncType = std::unique_ptr<T>(*)(sf::Vector2f position, Resources::Object resourceType);

    bool registerType(ObjectType t, FuncType f)
    {
        m_map.emplace(t, f);
        return true;
    }

    std::unique_ptr<T> create(ObjectType t, sf::Vector2f position, Resources::Object resourceType) const
    {
        if (!m_map.contains(t)) 
            return nullptr;
        return m_map.at(t)(position, resourceType);
    }

private:
    Factory() = default;
    Factory(const Factory&) = delete;
    void operator=(const Factory&) = delete;
    std::unordered_map<ObjectType, FuncType> m_map;
};
