#pragma once

#include <memory>
#include <string>
#include "Validator.h"

class IdValidator : public Validator<uint32_t>
{
public:
    IdValidator();
    bool validate(const uint32_t& input) const;
    std::string getErrorMessage() const;
private:
};
