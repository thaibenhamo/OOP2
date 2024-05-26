#include <iostream>

class TextureLoadException : public std::exception 
{
public:
    TextureLoadException(const std::string& filename) : filename(filename) {}

    virtual const char* what() const noexcept
    {
        return errorMessage.c_str();
    }

private:
    std::string filename;
    std::string errorMessage = "Failed to load texture: " + filename;
};
