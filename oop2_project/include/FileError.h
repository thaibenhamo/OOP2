#pragma once
#include <exception>

class FileError : public std::exception
{
public:
	const char* what() const noexcept
	{
		return "Can't read from file";
	}
};
