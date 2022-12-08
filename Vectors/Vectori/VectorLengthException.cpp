//
//  VectorLengthException.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 30.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "VectorLengthException.hpp"

//definition of copy constructor
VectorLengthException::VectorLengthException(const char *txt): std::exception(), txt(new char[strlen(txt)+1]){
    strcpy(this->txt, txt);
    
}

//definition of destructor
VectorLengthException::~VectorLengthException() {
    if(txt!=NULL){
        delete[] txt;
        txt=nullptr;
    }
}

//definition of function for exceptions when Vector = 0
const char* VectorLengthException::what() const noexcept{
    return txt;
}
