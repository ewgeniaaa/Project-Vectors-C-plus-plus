//
//  VectorLengthException.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 30.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef VectorLengthException_hpp
#define VectorLengthException_hpp

#include <iostream>
#include <stdexcept>
#include <cstring>

class VectorLengthException:public std::exception{ //class declaration; inherits standard class for exceptions
public: //access specifier
    VectorLengthException(const char* ); //copy constructor declaration
    ~VectorLengthException(); //declaration of destructor
    virtual const char* what() const noexcept;//throws exceptions if the length of Vector is equal to 0
    
private: //access specifier
    //data member declaration
    char* txt; 
};


#endif /* VectorLengthException_hpp */
