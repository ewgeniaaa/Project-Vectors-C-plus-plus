//
//  Elements.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 2.06.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Elements.hpp" //separate compilation; connecting this .cpp(source) file with its .hpp(header) file

//definition of inserter
std::ostream& Elements::ins(std::ostream& out) const{ //giving a name of an object from type ostream&
    return out; //the function returns changed object from type ostream&
}

//definition of extractor
std::istream& Elements::ext(std::istream& in){ //giving a name of an object from type istream&
    return in; //the function returns changed object from type istream&
}

//overloading operator << (definition)
std::ostream& operator<<(std::ostream& out, const Elements& rhs){ //giving names of the objects from type ostream& and const Elements&
    return rhs.ins(out); //returns the virtual function inserter which is a part from the relevant herediraty class
}

//overloading operator >> (definition)
std::istream& operator>>(std::istream& in, Elements& rhs){ //giving names of the objects from type istream& and const Elements&
    return rhs.ext(in); //returns the virtual function extractor which is a part from the relevant herediraty class
}
