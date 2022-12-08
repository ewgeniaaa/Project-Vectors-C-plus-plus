//
//  Point.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 28.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Point.hpp"      //Usage of separate compilation; Including the .hpp(header) file of class Point

//Definition of the default constructor, where we give the member data default values:
Point::Point():cord_x(0),cord_y(0),cord_z(0){}
//Definition of the constructor with parameters, where the data members take the values of the given parameters:
Point::Point(double x, double y, double z) :cord_x(x), cord_y(y), cord_z(z){}
//Definition of the copy-constructor:
Point::Point(const Point& rhs) : cord_x(rhs.cord_x), cord_y(rhs.cord_y), cord_z(rhs.cord_z) {}
//Definition of the destructor of class Point:
Point::~Point(){}
//Definition for overloading the equal sign: operator =, for objects of type Point:
Point& Point::operator=(const Point& rhs){         //Member function with parameter: Point object submitted by reference (rhs: right hand side).
    if(this!=&rhs){                                //An if statement which checkes if the left and right hand side are equal: if they are then we return the left hand side.
        cord_x=rhs.cord_x;                         //The left hand side (this) cordinate x, takes the value of the right hand side cordinate x.
        cord_y=rhs.cord_y;                         //The left hand side (this) cordinate y, takes the value of the right hand side cordinate y.
        cord_z=rhs.cord_z;                         //The left hand side (this) cordinate z, takes the value of the right hand side cordinate z.
    }
    return *this;                                  //Return pointer (this) the left hand side with its new value
}
//Definition of the setter of the cordinate x:
void Point::set_x(double x)
{
    cord_x = x;    //The member data cord_x gets the value of the argument x.
}
//Definition of the setter of the cordinate y:
void Point::set_y(double y)
{
    cord_y = y;                                    //The member data cord_y gets the value of the argument y.
}
//Definition of the setter of the cordinate z:
void Point::set_z(double z)
{
    cord_z = z;                                    //The member data cord_z gets the value of the argument z.
}
//Definition of the getter of the cordinate x:
double Point::get_x() const
{
    return cord_x;                                 //Returns the member data cord_x.
}
//Definition of the getter of the cordinate y:
double Point::get_y() const
{
    return cord_y;                                 //Returns the member data cord_y.
}
//Definition of the getter of the cordinate z:
double Point::get_z() const
{
    return cord_z;                                 //Returns the member data cord_z.
}
//Definition of inserter member function:
std::ostream& Point::ins(std::ostream& out) const { //giving a name of an object from type const ostream&
    out << "x = " << cord_x << std::endl; //writes "x=" and cordinate x
    out << "y = " << cord_y << std::endl; //writes "y=" and cordinate y
    out << "z = " << cord_z << std::endl; //writes "z=" and cordinate z
    return out;  //returns changed object from type ostream&
}
//Definition of extracter member function:
std::istream& Point::ext(std::istream& in) {  //giving a name of an object from type const istream&
    std::cout << "\nEnter coordinates of the point\n";   //prints text
    std::cout << "x = "; //prints "x="
    in >> cord_x;        //reads cordinate x
    std::cout << "y = "; //prints "y="
    in >> cord_y;        //reads cordinate y
    std::cout << "z = "; //prints "z="
    in >> cord_z;        //reads cordinate z
    return in;  //returns changed object from type istream&
}
//Definition of an external function for overloading operator (==).
bool operator==(const Point& lhs, const Point& rhs) //checks if two point(lhs= left hand side and rhs= right hand side) coincide with each other
{   //if statement that checks if the cordinates of the lhs point are equal to the cortinates of the rhs point
    if (lhs.get_x() == rhs.get_x() && lhs.get_y() == rhs.get_y() && lhs.get_z() == rhs.get_z()) return true; //if true, then the points coincide, returns true
    return false; //if false, then the points do not coincide, returns false
}

