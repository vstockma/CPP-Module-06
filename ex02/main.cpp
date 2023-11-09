/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:21:07 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/09 14:06:10 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
    Base object;
    Base* obj = object.generate();

    obj->identify(obj);
    obj->identify(*obj);

    delete obj;

    return 0;
}