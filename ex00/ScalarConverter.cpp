/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:29:48 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/09 10:55:57 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    (void)copy;
    std::cout << "Copy constructor called" << std::endl;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    (void)copy;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;
}

bool Isdouble(std::string literal)
{
    int i = 0;
    if (literal[i] == '-')
        i++;
    while (literal[i] && literal[i] != '.')
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    i++;
    while (literal[i])
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

bool Isfloat(std::string literal)
{
    int i = 0;
    if (literal[i] == '-')
        i++;
    while (literal[i] && literal[i] != '.')
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    i++;
    while (literal[i] && literal[i] != 'f')
    {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    if (literal[i + 1] != '\0')
        return false;
    return true;
}

bool IsInteger(const std::string& str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    while (str[i] )
    {
        if (!std::isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        convertchar(literal);
    else if (IsInteger(literal))
        convertint(literal);
    else if (literal.length() > 1 && Isfloat(literal))
        convertfloat(literal);
    else if (Isdouble(literal))
        convertdouble(literal);
    else
        checkpseudoliterals(literal);
}

void ScalarConverter::convertchar(std::string literal)
{
    char character = literal[0];
    if (std::isprint(literal[0]))
        std::cout << "char: " << literal << std::endl;
    else
        std::cout << "char: Non displayable\n";
    int intval = static_cast<int>(character);
    std::cout << "int: " << intval << std::endl;
    float floatval = static_cast<float>(character);
    std::cout << "float: " << floatval << ".0f" << std::endl;
    double doubleval = static_cast<double>(character);
    std::cout << "double: " << doubleval << ".0" << std::endl;
}

void ScalarConverter::convertint(std::string literal)
{
    char* end;
    long long longValue = std::strtol(literal.c_str(), &end, 10);
    if (longValue >= 32 && longValue <= 127)
    {
        char character = static_cast<char>(longValue);
        std::cout << "char: " << character << std::endl;
    }
    else if (longValue >= 0 && longValue <= 31)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: Impossible\n";
    int intval = static_cast<int>(longValue);
    std::cout << "int: " << intval << std::endl;
    float floatval = static_cast<float>(longValue);
    std::cout << "float: " << floatval << ".0f" << std::endl;
    double doubleval = static_cast<double>(longValue);
    std::cout << "double: " << doubleval << ".0" << std::endl;
}

void ScalarConverter::convertfloat(std::string literal)
{
    char* end;
    float floatval = std::strtof(literal.c_str(), &end);
    if (floatval >= 32 && floatval <= 127)
    {
        char character = static_cast<char>(floatval);
        std::cout << "char: " << character << std::endl;
    }
    else if (floatval >= 0 && floatval <= 31)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: Impossible\n";
    int intval = static_cast<int>(floatval);
    std::cout << "int: " << intval << std::endl;
    std::cout << "float: " << floatval << "f" << std::endl;
    double doubleval = static_cast<double>(floatval);
    std::cout << "double: " << doubleval << std::endl;
}

void ScalarConverter::convertdouble(std::string literal)
{
    char* end;
    double doubleval = std::strtod(literal.c_str(), &end);
    if (doubleval >= 32 && doubleval <= 127)
    {
        char character = static_cast<char>(doubleval);
        std::cout << "char: " << character << std::endl;
    }
    else if (doubleval >= 0 && doubleval <= 31)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "char: Impossible\n";
    int intval = static_cast<int>(doubleval);
    std::cout << "int: " << intval << std::endl;
    float floatval = static_cast<float>(doubleval);
    std::cout << "float: " << floatval << "f" << std::endl;
    std::cout << "double: " << doubleval << std::endl;
}

void ScalarConverter::checkpseudoliterals(std::string literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal + "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;   
    }
}
