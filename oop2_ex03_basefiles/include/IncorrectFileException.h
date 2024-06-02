#pragma once

#include <exception>
#include <string>

class IncorrectFileException : public std::exception
{
public:
    IncorrectFileException(const std::string& message) 
    {
        m_message = "Error loading game: " + message;
    }
 
    const char* what() const noexcept override
    {
        return m_message.c_str();
    }
private:
    std::string m_message;
};