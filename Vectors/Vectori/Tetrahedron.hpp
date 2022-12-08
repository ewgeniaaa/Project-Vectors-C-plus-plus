//
//  Tetrahedron.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 22.05.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef Tetrahedron_hpp
#define Tetrahedron_hpp

#include <iostream>
#include "Point.hpp" //separate compilation; including the .hpp(header) file of the class Point
#include "EqualPointException.hpp" //separate compilation; including the .hpp(header) file of the class EqualPointException
#include "Vector.hpp" //separate compilation; including the .hpp(header) file of the class Vector
#include "Triangle.hpp" //separate compilation; including the .hpp(header) file of the class Triangle

class Tetrahedron : public Point{ //class declaration; clas Tetrahedron inherits the class Point(inheritance)
public: //access specifier
    //big five
    Tetrahedron(); //default constructor of the class Tetrahedron
    Tetrahedron(Point, Point, Point, Point); //constructor with parameters; defining a tetrahedron with 4 points;
    Tetrahedron(const Tetrahedron&); //copy constructor
    Tetrahedron& operator=(const Tetrahedron&); //overloading operator =
    ~Tetrahedron(); //destructor
    
    bool isRight(); //function which checks if the tetrahedron is right
    bool isOrthocentric(); //function which checks if the tetrahedron is orthocentric
    double Area(); //function which calculates the area of a tetrahedron
    double Volume(); //function which calculates the volume of a tetrahedron
    
    //setters declaration
    int setA(Point);
    int setB(Point);
    int setC(Point);
    int setD(Point);

    //getters declaration
    Point getA() const;
    Point getB() const;
    Point getC() const;
    Point getD() const;

    std::ostream& ins(std::ostream&) const; //declaration of inserter
    std::istream& ext(std::istream&); //declaration of extractor
    
private:
    //data members declaration
    Point A;
    Point B;
    Point C;
    Point D;
};

bool operator<(const Point&, const Tetrahedron&); //overloading operator <; declaration like a friend function; return boolean type
bool operator>(const Point&, const Tetrahedron&); //overloading operator >; declaration like a friend function; return boolean type
bool operator==(const Point&, const Tetrahedron&); //overloading operator ==; declaration like a friend function; return boolean type

#endif /* Tetrahedron_hpp */
