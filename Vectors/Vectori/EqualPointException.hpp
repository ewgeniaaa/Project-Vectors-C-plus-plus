//
//  EqualPointException.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 18.05.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef EqualPointException_hpp
#define EqualPointException_hpp

#include <iostream>         //Including iostream lybrary.
#include <stdexcept>        //Including stdexcept lybrary.
#include <cstring>          //Including cstring lybrary.

class EqualPointException:public std::exception{ //Creating a class, dirived by the standart class exception.
public: //public access specifier
    EqualPointException(const char* );           //Declaration of copy- constructor with parameter const dynamic char.
    ~EqualPointException();                      //Declaration of public member function that destroies exception (destructor).
    
    virtual const char* what() const noexcept;   //Declaration of public member function that gets string identifying exception.
    
private:       //private access specifier.
    char* txt; //Member data from type: dynamic char.
};

#endif /* EqualPointException_hpp */
