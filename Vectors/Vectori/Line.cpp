//
//  Line.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 30.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Line.hpp"//separate compilation; including the .hpp(header) file of class Line
#include <iostream>
#include <cmath>

Line::Line():Vector(), p1(){}//definition of default constructor

//constructor Point and Point definition
Line::Line(Point p1, Point p2):p1(p1){
    set_x(p2.get_x()-p1.get_x());
    set_y(p2.get_y()-p1.get_y());
    set_z(p2.get_z()-p1.get_z());
}

//constructor Point and Vector definition
Line::Line(Point p1, Vector& v1):p1(p1) {
    set_x(v1.get_x());
    set_y(v1.get_y());
    set_z(v1.get_z());
}

//copy constructor definition
Line::Line(const Line & rhs):Vector(rhs) {
    this->p1 = rhs.p1;
}

//destructor
Line::~Line() {}

Line & Line::operator=(const Line & rhs) {//overloading operator =; giving a name of an object from type const Line&
    if(this != &rhs) {//check if the pointer is different from submitted object
        Vector::operator=(rhs);
        //assign the value of the object rhs to the current object
        p1 = rhs.p1;
    }
    return *this;//return pointer 'this'
}

//definition of getter
Point Line::getP1()const{
    return p1;
}

//definition of setter
int Line::setP1(Point p1){
    this->p1=p1;
    return 0;
}

//definition of function finding Direction of Vector
Vector Line::direction() {
    Vector v(get_x(),get_y(), get_z());
    return v.direction(); //returns Vector parallel of the Line
}

Vector Line::normal(){//definition of function finding normal Vector
    double x=1, y=1, z;
    z=-1*(get_x()*x + get_y()*y)/get_z();
    Vector res(x, y, z);
    return res; //returns Vector perpendicullar of the Line
}

double Line::angle(const Line& rhs){//definition of function finding angle between two Lines
    Vector v1(get_x(), get_y(),get_z());
    Vector v2(rhs.get_x(), rhs.get_y(), rhs.get_z());
    double res;
    res=(v1*v2)/(v1.length()*v2.length());
    return acos(res); //returns the value of the angle in radians
}

bool Line::operator+(const Point& p2){//overloading operator +
    Vector v1(p1, p2);
    Vector v2 = get_Vector();
    double distance = (v2^v1).length()/v1.length();
    //checks if the given Point is on the Line
    if (distance==0) {
        //returns true or false
        return true;
    }
    return false;
}

bool Line::operator==(const Line& rhs){//overloading operator ==
    //checks if a Line is identical with another Line
    if((*this||rhs) && (*this+rhs.getP1()))
        //returns true or false
        return true;
    return false;
}

bool Line::operator&&(const Line& rhs){//overloading operator &&
    //checks if a Line interceps another Line; returns true or false
    return !(*this||rhs);
}

bool Line::operator!=(const Line& rhs){//overloading operator !=
    //checks if a Line is crossed with another Line; returns true or false
    return !(*this==rhs);
}

bool Line::operator||(const Line& rhs){//overloading operator ||
    //checks if given Line is parallel to another Line
    Vector a(get_x(),get_y(),get_z());
    Vector b(rhs.get_x(),rhs.get_y(), rhs.get_z());
    return a.isParallel(b); //returns true or false
}

bool Line::operator|(const Line& rhs){//overloading operator |
    //checks if a Line is perpendicullar to another Line
    Vector a(get_x(),get_y(),get_z());
    Vector b(rhs.get_x(),rhs.get_y(), rhs.get_z());
    return a.isPerpen(b);//returns true or false
}


//definition of the inserter
std::ostream& Line::ins(std::ostream& out) const{
    out<<"\nVector information\n";
    Vector::ins(out);
    out<<"\nPoint information\n";
    out<<p1;
    return out;
}


//definition of the extractor
std::istream& Line::ext(std::istream& in){
    std::cout<<"\nHow do you want to create it?\n";
    std::cout<<"1) By point and vector\n";
    std::cout<<"2) By 2 points\n";
    std::cout<<"OPTION: ";
    int tmp;
    std::cin>>tmp;
    //checks which option is chosen by the user
    if (tmp==2) {
        Point P1;
        Point P2;
        std::cin>>P1>>P2;
        Line B(P1, P2);
        *this=B;
    }
    else{ //option 1
        Point P1;
        Vector V1;
        std::cin>>P1>>V1;
        Line tmp(P1, V1);
        *this=tmp;
    }
    return in;
}


