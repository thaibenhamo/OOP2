#pragma once

#include <string>
#include <iostream>

template<typename T>
class ValuesToNames 
{
public:
    ValuesToNames();
    ValuesToNames(int option);
    int getOption() const;
    std::string valuesAndNames() const;

    template<typename T>
    friend std::istream& operator>>(std::istream& is, ValuesToNames<T>& value);
    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const ValuesToNames<T>& value);
private:
    T m_options;
    int m_option;
};

template<typename T>
std::istream& operator>>(std::istream& is, ValuesToNames<T>& value);

template<typename T>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<T>& value);

template<typename T>
ValuesToNames<T>::ValuesToNames() : m_option(-1) {}

template<typename T>
ValuesToNames<T>::ValuesToNames(int option) : m_option(option) {}

template<typename T>
int ValuesToNames<T>::getOption() const
{
    return m_option;
}

template<typename T>
std::string ValuesToNames<T>::valuesAndNames() const
{
    return m_options.optionsToString();
}

template<typename T>
 std::istream& operator>>(std::istream& is, ValuesToNames<T>& value)
{
    is >> value.m_option;
    return is;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<T>& value)
{
    os << value.m_options.getName(value.getOption());
    return os;
}

template<typename T>
bool operator<(const ValuesToNames<T>& value1, const ValuesToNames<T>& value2)
{
    return (value1.getOption() < value2.getOption());
}

template<typename T>
bool operator>=(const ValuesToNames<T>& value1, const ValuesToNames<T>& value2)
{
    return !(value1.getOption() < value2.getOption());
}
