#pragma once

#include <exception>
#include <string>

class InvalidGameStateException : public std::exception
{
public:
    InvalidGameStateException(const std::string& message)
    {
        m_message = "Invalid game state:" + message;
    }

    const char* what() const noexcept override
    {
        return m_message.c_str();
    }
private:
    std::string m_message;
};