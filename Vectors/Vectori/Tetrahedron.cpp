//
//  Tetrahedron.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 22.05.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Tetrahedron.hpp" //separate compilation; including the .hpp(header) file of the class Tetrahedron

//big five definiton
Tetrahedron::Tetrahedron(){} //definition of default constructor
Tetrahedron::Tetrahedron(Point A, Point B, Point C, Point D):A(A), B(B), C(C), D(D){ //defition of a constructor with parameters; giving names of the objects
    if(A==B || A==C || A==D || B==C || B==D || C==D){ //check if 2 or more of the points are equal
            throw EqualPointException("A tetrahedron could not be created because 2 or more of the points are equal."); //if 2 or more of the points are equal then the function returns exception from const char* type
    }
}
Tetrahedron::Tetrahedron(const Tetrahedron& rhs):A(rhs.A), B(rhs.B), C(rhs.C), D(rhs.D){} //definition of copy constructor
Tetrahedron::~Tetrahedron(){} //definition of destructor

Tetrahedron& Tetrahedron::operator=(const Tetrahedron& rhs){ //overloading operator =; giving a name of an object from type const Tetrahedron&
    if(this!=&rhs){ //check if the pointer 'this' is different from the submitted object
        //assign the value of the rhs objects to the current objects
        A=rhs.A;
        B=rhs.B;
        C=rhs.C;
        D=rhs.D;
    }
    return *this; //return pointer 'this'
}

bool Tetrahedron::isRight(){ //function which checks if a tetrahedron is right
    //creating vectors from 2 points(calling constructor)
    Vector AB(A, B);
    Vector AC(A, C);
    Vector AD(A, D);
    Vector BC(B, C);
    Vector BD(B, D);
    Vector CD(C, D);
    
    return(AB.length()==AC.length()==AD.length()==BC.length()==BD.length()==CD.length()); //if all the edges are eqaul then the function returns true which means that the tetrahedron is right
}

bool Tetrahedron::isOrthocentric(){ //function which checks if a tetrahedron is orthocentric
    //creating vectors from 2 points(calling constructor)
    Vector AB(A, B);
    Vector AC(A, C);
    Vector AD(A, D);
    Vector BC(B, C);
    Vector BD(B, D);
    Vector CD(C, D);
    
    return AB.isPerpen(CD) && AC.isPerpen(BD) && BC.isPerpen(AD); //if 2 opposite edges are perpendicular then the function returns true which means that the tetrahedron is orthocentric
}

double Tetrahedron::Area(){ //definiton of a function which find the area of a tetrahedron
    //creating triangles from 3 points(calling constructors)
    Triangle ADC(A, D, C);
    Triangle ADB(A, D, B);
    Triangle BDC(B, D, C);
    
    return ADC.area()+ADB.area()+BDC.area(); //summing the areas of the 3 triangles and calculating the area of the tetrahedron
}

double Tetrahedron::Volume(){ //definiton of a function which find the volume of a tetrahedron
    //creating vectors from 2 points(calling constructors)
    Vector AB(A, B);
    Vector AC(A, C);
    Vector AD(A, D);

    return ((AB^AC)*AD)/6; //calculating the area of the tetrahedron [det.(vector AB, vector AC, vector AD)]/6
}

bool operator<(const Point& P, const Tetrahedron& ABCD){ //overloading operator <; giving names of object from type const Point& and const Tetrahedron&
    //creating triangles from 3 of the sides of a tetrahedron
    Triangle ADC(ABCD.getA(), ABCD.getD(), ABCD.getC());
    Triangle ADB(ABCD.getA(), ABCD.getD(), ABCD.getB());
    Triangle BDC(ABCD.getB(), ABCD.getD(), ABCD.getC());
    Triangle ABC(ABCD.getA(), ABCD.getB(), ABCD.getC());
    
    return P<ADC || P<ADB || P<BDC || P<ABC; //calling overloading operator < from class Triangle
}

bool operator>(const Point& P, const Tetrahedron& ABCD){ //overloading operator >; giving names of object from type const Point& and const Tetrahedron&
    //creating triangles from 3 of the sides of a tetrahedron
    Triangle ADC(ABCD.getA(), ABCD.getD(), ABCD.getC());
    Triangle ADB(ABCD.getA(), ABCD.getD(), ABCD.getB());
    Triangle BDC(ABCD.getB(), ABCD.getD(), ABCD.getC());
    Triangle ABC(ABCD.getA(), ABCD.getB(), ABCD.getC());
    
    return P>ADC || P>ADB || P>BDC || P>ABC; //calling overloading operator > from class Triangle
}

bool operator==(const Point& P, const Tetrahedron& ABCD){ //overloading operator ==; giving names of object from type const Point& and const Tetrahedron&
    //creating triangles from 3 of the sides of a tetrahedron
    Triangle ADC(ABCD.getA(), ABCD.getD(), ABCD.getC());
    Triangle ADB(ABCD.getA(), ABCD.getD(), ABCD.getB());
    Triangle BDC(ABCD.getB(), ABCD.getD(), ABCD.getC());
    Triangle ABC(ABCD.getA(), ABCD.getB(), ABCD.getC());
    
    return (P==ADC) || (P==ADB) || (P==BDC) || (P==ABC); //calling overloading operator == from class Triangle
}

//declaration of a setter for object A from type Point
int Tetrahedron::setA(Point  A) {
    this->A = A;
    return 0;
}

//declaration of a setter for object B from type Point
int Tetrahedron::setB(Point B) {
    this->B = B;
    return 0;
}

//declaration of a setter for object C from type Point
int Tetrahedron::setC(Point C) {
    this->C = C;
    return 0;
}

//declaration of a setter for object D from type Point
int Tetrahedron::setD(Point D) {
    this->D = D;
    return 0;
}

//declaration of a getter for object A from type Point
Point Tetrahedron::getA() const {
    return A;
}

//declaration of a getter for object B from type Point
Point Tetrahedron::getB() const {
    return B;
}

//declaration of a getter for object C from type Point
Point Tetrahedron::getC() const {
    return C;
}

//declaration of a getter for object D from type Point
Point Tetrahedron::getD() const {
    return D;
}

std::ostream& Tetrahedron::ins(std::ostream& out) const { //definition of inserter; giving a name of an object from type const ostream&
    out << "A:\n" << A << std::endl; //print A
    out << "B:\n" << B << std::endl; //print B
    out << "C:\n" << C << std::endl; //print C
    out << "D:\n" << D << std::endl; //print D
    return out; //returns changed object from type ostream&
}

std::istream& Tetrahedron::ext(std::istream& in) { //definition of extractor; giving a name of an object from type const istream&
    //creating objects from type Point
    Point A;
    Point B;
    Point C;
    Point D;
    std::cin >> A >> B >> C >> D; //entering coodinates of the points
    Tetrahedron tmp(A, B, C, D); //creating an object from type Tetrahedron with 4 point
    *this = tmp; //pointer 'this' approptiates the data which object 'tmp' contains
    return in; //returns changed object from type istream&
}
