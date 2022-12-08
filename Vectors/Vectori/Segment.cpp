//
//  Segment.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 2.06.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Segment.hpp"//separate compilation; including the .hpp(header) file of class Segment

// Constructors
Segment::Segment():Line(), t(0){}//definition of default constructor

Segment::Segment(Point p, Vector v, double t):Line(p, v), t(t){}//constructor of Line with Point and Vector with interval t[0,1]

Segment::Segment(const Segment & rhs): Line(rhs), t(rhs.t){}//copy constructor definition

Segment & Segment::operator=(const Segment & rhs){//overloading operator =; giving a name of an object from type const Segment&
    if(this!=&rhs){//check if the pointer is different from submitted object
        Line::operator=(rhs);
        //assign the value of the object rhs to the current object
        this->t=rhs.t;
    }
    return *this;//return pointer 'this'
}

Segment::~Segment(){}//destructor definition


double Segment::length(){//function finds length of Segment; returns real number
        double x2 = getP1().get_x() + (get_x() * t);
        double y2 = getP1().get_y() + (get_y() * t);
        double z2 = getP1().get_z() + (get_z() * t);

        double x = x2 - getP1().get_x();
        double y = y2 - getP1().get_y();
        double z = z2 - getP1().get_z();

        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); //returning the length t[0,1]
}


Point Segment::middlePoint(){ //function finds the middle Point and returns Point with coordinates ((xA + xB)/2,(yA + yB)/2,(zA + zB)/2)
        double x2 = getP1().get_x() + (get_x())*t;
        double y2 = getP1().get_y() + (get_y())*t;
        double z2 = getP1().get_z() + (get_z())*t;
        
        double x = (x2 + getP1().get_x())/2;
        double y = (y2 + getP1().get_y())/2;
        double z = (z2 + getP1().get_z())/2;
        
        Point A(x, y, z);
        return A;//returns the Point
}


bool Segment::operator==(const Point & rhs){//definition of overloading operator ==;returns boolean type
    double x1 = getP1().get_x();
    double y1 = getP1().get_y();
    double z1 = getP1().get_z();
    
    double x2 = getP1().get_x() + (get_x())*t;
    double y2 = getP1().get_y() + (get_y())*t;
    double z2 = getP1().get_z() + (get_z())*t;
    //checks if given Point on the Segment and returns true or false
    if ((rhs.get_x()>=x1 && rhs.get_x()<=x2) && (rhs.get_y()>=y1 && rhs.get_y()<=y2) && (rhs.get_z()>=z1 && rhs.get_z()<=z2))
        return true;
    return false;
}

std::ostream& Segment::ins(std::ostream& out) const{ //definition of inserter
    Line::ins(out);
    out<<"Time: "<<t;
    return out;
}

std::istream& Segment::ext(std::istream& in){//definition of extractor
    Point P1;
    Point P2;
    std::cin>>P1>>P2;
    setP1(P1);
    set_x(P2.get_x()-P1.get_x());
    set_y(P2.get_y()-P1.get_y());
    set_z(P2.get_z()-P1.get_z());
    std::cout<<"Enter the interval in seconds: ";
    in>>t;
    return in;
}
