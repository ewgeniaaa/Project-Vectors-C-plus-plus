//
//  Elements.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 2.06.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef Elements_hpp
#define Elements_hpp

#include <iostream>

class Elements{ //class declaration
public: //access specifier
    virtual std::ostream& ins(std::ostream&) const; //declaration of a virtual function-inserter(using for output <<)
    virtual std::istream& ext(std::istream&); //declaration of a virtual function-extractor(using for input >>)
};

std::ostream& operator<<(std::ostream&, const Elements&); //overloading operator << (for output); declaration like an external function;
std::istream& operator>>(std::istream&, Elements&); //overloading operator >> (for input); declaration like an external function;

#endif /* Elements_hpp */
