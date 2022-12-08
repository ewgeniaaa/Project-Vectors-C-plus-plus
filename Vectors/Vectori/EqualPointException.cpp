//
//  EqualPointException.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 18.05.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "EqualPointException.hpp"  //Usage of separate compilation; including the .hpp(header) file of the class EqualPointException.

//Definition of copy- constructor: member function with parameter: const dynamic char (txt):
EqualPointException::EqualPointException(const char *txt): std::exception(), txt(new char[strlen(txt)+1]){ //creating an exception with default constructor; memory allocation for dynamic char txt.
    strcpy(this->txt, txt); //copying the text from the parameter
}
//Definition of public member function that destroies exception (destructor):
EqualPointException::~EqualPointException() {
    if(txt!=NULL){  //if statement that checks if the char pointer is a null pointer.
        //if it is not:
        delete[] txt;  //deleting the allocated memory for the dynamic char.
        txt = nullptr; //deleting everything in the pointer.
    }
}
//Definition of public member function that gets string identifying exception:
const char* EqualPointException::what() const noexcept{
    return txt; //returns the member data of type: dynamic char.
}
