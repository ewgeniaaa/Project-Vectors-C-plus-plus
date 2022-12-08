//
//  Segment.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 2.06.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef Segment_hpp
#define Segment_hpp
#include "Line.hpp"//separate compilation; including the .hpp(header) file of class Line
#include <iostream>

class Segment : public Line{//class declaration; class Segment inherits class Line(inheritance)
public://access specifier
   
    Segment();//default constructor of class Line
    Segment(Point, Vector, double);//initializing a Line with Point and Vector with interval [0,1]
    Segment & operator=(const Segment &);//overloading operator =
    Segment(const Segment &);//copy constructor
    ~Segment();//destructor

    // Segment lenght
    double length();

    // Segment middle coordinates
    Point middlePoint();

    // Operator ==; returns boolean type
    bool operator==(const Point &);

    
    std::ostream& ins(std::ostream&) const; //inserter
    std::istream& ext(std::istream&);//extractor
    
private://access specifier
    //data member declaration
    double t;
};

#endif /* Segment_hpp */
