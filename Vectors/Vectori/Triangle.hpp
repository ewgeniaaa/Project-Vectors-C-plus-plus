//
//  Triangle.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 18.05.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef Triangle_hpp
#define Triangle_hpp

#include <iostream>
#include "Point.hpp" //separate compilation; including the .hpp(header) file of the class Point
#include "Vector.hpp" //separate compilation; including the .hpp(header) file of the class Vector
#include "EqualPointException.hpp" // separate compilation; including the .hpp(header) file of the class EqualPointException

class Triangle: public Point{ //class declaration; class Point inherits class Triangle(inheritance)
public: //access specifier
    //big five
    Triangle(); //default constructor of class Triangle
    Triangle(Point, Point, Point); //constructor with parameters; defining a triangle with 3 points;
    Triangle(const Triangle&); //copy constructor
    ~Triangle(); //destructor
    Triangle& operator=(const Triangle&); //overloading operator =
    
    int triangle_type(); //function which determines the type of a triangle
    double area(); //function which finds the area of a triangle
    double perimeter(); //function which finds the perimeter of a triangle
    Point medicenter(); //function which finds the medicenter of a triangle
    
    //setters declaration
    int setP1(Point);
    int setP2(Point);
    int setP3(Point);
    int setA(Vector);
    int setB(Vector);
    int setC(Vector);
    
    //getters declaration
    Point getP1()const;
    Point getP2()const;
    Point getP3()const;
    Vector getA()const;
    Vector getB()const;
    Vector getC()const;

    std::ostream& ins(std::ostream&) const; //declaration of inserter
    std::istream& ext(std::istream&); //declaration of extractor
    
private:
    //data member declaration
    Point p1;
    Point p2;
    Point p3;
    
    Vector a;
    Vector b;
    Vector c;
};

bool operator<(const Point&, const Triangle&); //overloading operator <; declaration like an external function; returns boolean type
bool operator>(const Point&, const Triangle&); //overloading operator >; declaration like an external function; returns boolean type
bool operator==(const Point&, const Triangle&); //overloading operator ==; declaration like an external function; returns boolean type

bool isBetween(const Point&, const Point&, const Point& P); //function which check if a point is between two other points; declaration like an external function; returns boolean type

#endif /* Triangle_hpp */
