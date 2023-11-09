/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:30:03 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/08 15:16:35 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
# include <sstream>
# include <limits>
# include <cstdlib>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();
    public:
        static void convert(const std::string literal);
        static void convertchar(const std::string literal);
        static void convertint(const std::string literal);
        static void convertfloat(std::string literal);
        static void convertdouble(std::string literal);
        static void checkpseudoliterals(std::string literal);
};

#endif
