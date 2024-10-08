#pragma once

#include "Stick.h"

class CompareScores 
{
public:
    bool operator()(const Stick* stick1, const Stick* stick2) const 
    {
        // Compare first by score
        if (stick1->getScore() == stick2->getScore()) 
        {
            // If scores are equal, compare by ID
            return stick1->getId() < stick2->getId();
        }
        // Otherwise, order by score
        return stick1->getScore() > stick2->getScore();
    }
};