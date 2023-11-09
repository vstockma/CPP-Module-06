/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:21:51 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/09 12:19:58 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{ std::cout << "Defaults constructor called" << std::endl; }

Serializer::~Serializer()
{ std::cout << "Destructor called" << std::endl; }

Serializer::Serializer(const Serializer& copy)
{
    (void)copy;
    std::cout << "Copy constructor called" << std::endl;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
    (void)copy;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw;
    raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr;
    ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}
