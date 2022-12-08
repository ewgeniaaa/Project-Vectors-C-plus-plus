//
//  Vector.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 28.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//
#include "Point.hpp"                         //Usage of separate compilation; including the .hpp(header) file of the class Point.
#ifndef Vector_hpp
#define Vector_hpp

#include <iostream>                          //Including iostream lybrary.
#include <cmath>                             //Including cmath lybrary.
#include "VectorLengthException.hpp"         //Usage of separate compilation; including the .hpp(header) file of the class VectorLenghthException.

class Vector :public Point                   //Creating a class, dirived by the class Point that makes a vector.
{
public:      //public access specifier
    Vector();                                //Declaration of the default constructor of class Vector.
    Vector(const Point&, const Point&);      //Declaration of constructor with parameters: two points(objects of class Point) submitted by reference.
    Vector(double, double, double);          //Declaration of constructor with parameters: three real numbers(double values), which are the cordinates: (x, y, z)
    ~Vector();                               //Declaration of the destructor of class Vector.
    Vector(const Vector&);                   //Declaration of the copy-constructor.
    Vector& operator=(const Vector&);        //Declaration for overloading the equal sign (=) for objects of type Vector.
    
    double length();         //Declaration of a member function that calculates the lenght of a vector, returns a double type.
    bool zeroVector();       //Declaration of a member function that checks if all of the cordinates of the vector are equal to zero, returns a boolean type.
    Vector direction();      //Declaration of a member function that calculates the direction of a vector, returns a Vector type.
    
    Vector operator+(const Vector&);         //Declaration of a member function for overloading operator+, that returns a Vector type.
    Vector operator-(const Vector&);         //Declaration of a member function for overloading operator-, that returns a Vector type.
    Vector operator*(double);                //Declaration of a member function for overloading operator* (for multiplying vector with a real number), that returns a Vector type.
    double operator*(const Vector&);         //Declaration of a member function for overloading operator* (for multiplying vector with a vector), that returns a double type.
    Vector operator^(const Vector&);         //Declaration of a member function for overloading operator^, that returns a Vector type.
    double operator()(const Vector&, const Vector&);   //Declaration of a member function for overloading operator(), that returns a double type.
    
    bool isParallel(const Vector&);          //Declaration of a member function that checks if two vector are parallel, returns a boolean type.
    bool isPerpen(const Vector&);            //Declaration of a member function that checks if two vector are perpendicular, returns a boolean type.
    
    Vector get_Vector() const;                     //Declaration of a getter of the Vector.
    std::ostream& ins(std::ostream&) const;  //Declaration of inserter member function.
    std::istream& ext(std::istream&);        //Declaration of extracter member function.
};

#endif /* Vector_hpp */
