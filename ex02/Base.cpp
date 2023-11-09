/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:22:12 by vstockma          #+#    #+#             */
/*   Updated: 2023/11/09 14:52:57 by vstockma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"


Base::~Base()
{
    std::cout << "Base destructor called\n";
}

Base*   Base::generate(void)
{
    std::srand((std::time(NULL)));
    int random = std::rand() % 3;
    switch (random)
    {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
            break ;
        default: return NULL;
    }
    return NULL;
}

void    Base::identify(Base* p)
{
    if (A* derived = dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (B* derived = dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (C* derived = dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown Type" << std::endl;
    }
}

void    Base::identify(Base& p)
{
    try
    {
        A& derivedA = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        (void)derivedA;
    }
    catch (const std::exception& e)
    {
        try
        {
            B& derivedB = dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            (void)derivedB;
        }
        catch (const std::exception& e)
        {
            try
            {
                C& derivedC = dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                (void)derivedC;
            }
            catch (const std::exception& e)
            {
                std::cout << "Unknown Type" << std::endl;
            }
        }
    }
}
