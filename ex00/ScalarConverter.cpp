/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:29:48 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/06 16:30:07 by vstockma         ###   ########.fr       */
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
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy);
{
    (void)copy;
    std::cout << "Copy assignment operator called" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Destructor called" << std::endl;
}

static void ScalarConverter::convert(std::string& literal)
{
    
}
