/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:20:16 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/09 12:19:01 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data data;
    Data* ptr;
    uintptr_t raw;

    ptr = &data;
    data.member = "String";

    raw = Serializer::serialize(ptr);

    Data* ptr1;
    ptr1 = Serializer::deserialize(raw);

    std::cout << ptr1->member << std::endl;

    std::cout << ptr->member << std::endl;
    return 0;
}