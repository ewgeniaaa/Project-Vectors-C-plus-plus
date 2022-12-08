//
//  Line.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 30.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <iostream>
#include "Vector.hpp" //separate compilation; including the .hpp(header) file of class Vector
#include "Point.hpp" //separate compilation; including the .hpp(header) file of class Point

class Line:public Vector{ //class declaration; class Line inherits class Vector(inheritance)
public: //access specifier
    
    Line(); //default constructor of class Line
    Line(Point, Point); //initializing Line with 2 Points;
    Line(Point, Vector&); //initializing Line with Point and Vector;
    Line(const Line &); //copy constructor
    Line & operator=(const Line &); //overloading operator =
    ~Line(); //destructor

    Vector direction(); //function finding direction of Line; returns Vector parallel to the Line
    Vector normal(); //function finding normal Vector; returns Vector perpendicular to the Line
    double angle(const Line&); //function finding the angle between 2 Lines; returns the value of angle in radians

    bool operator+(const Point&); //overloading operator +;returns boolean type
    bool operator||(const Line&); //overloading operator ||;returns boolean type
    bool operator==(const Line&); //overloading operator ==;returns boolean type
    bool operator&&(const Line&); //overloading operator &&;returns boolean type
    bool operator!=(const Line&); //overloading operator !=;returns boolean type
    bool operator|(const Line&); //overloading operator |;returns boolean type
    
    //getter of Point declaration
    Point getP1()const;
    
    //setter of Point declaration
    int setP1(Point);
    
    std::ostream& ins(std::ostream&) const; //inserter
    std::istream& ext(std::istream&); //extractor
    private:
    //data member declaration
        Point p1;
    };

    
#endif /* Line_hpp */
