//
//  Triangle.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 18.05.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Triangle.hpp" //separate compilation; including the .hpp(header) file of the class Triangle

//big five definition
Triangle::Triangle(){} //definition of default constructor

Triangle::Triangle(Point p1, Point p2, Point p3):p1(p1), p2(p2), p3(p3), a(p1,p2), b(p2,p3), c(p1,p3){ //definiton of constructor with parameters; giving names of the objects
    if(p1==p2 || p1==p3 || p2==p3) //check if two of the points are equal
        throw EqualPointException("A triangle could not be created because 2 or more of the points are equal."); //thrown exception from const char* type
}

Triangle::Triangle(const Triangle& rhs):p1(rhs.p1), p2(rhs.p2), p3(rhs.p3), a(p1,p2), b(p2,p3), c(p1,p3){} //definition of copy constructor

Triangle::~Triangle(){} //definition of destructor

Triangle& Triangle::operator=(const Triangle& rhs){ //overloading operator =; giving a name of an object from type const Triangle&
    if(this!=&rhs){ //check if the pointer is different from submitted object
        //assign the value of the objects rhs to the current object
        this->p1=rhs.p1;
        this->p2=rhs.p2;
        this->p3=rhs.p3;
        //creating vectors from 2 points(calling constructor)
        Vector tmp1(p1, p2);
        Vector tmp2(p2, p3);
        Vector tmp3(p1, p3);
        //assign the value of the objects from type Vector(tmp1,tmp2, tmp3) to the sides of a triangle(a, b, c)
        a=tmp1;
        b=tmp2;
        c=tmp3;
    }
    return *this; //return pointer 'this'
}

int Triangle::triangle_type(){ //definition of a function which determines the type of a triangle
    //creating 3 variable values from type double which are equal to the corresponding length
    double aL=a.length();
    double bL=b.length();
    double cL=c.length();
    
    if(aL==bL && bL==cL){ //check if 2 lengths are equal
        std::cout<<"The triangle is equilatral"; //if 2 lengths are equal then the triangle is equilatral
    }
    else if((aL==bL && cL!=bL) || (cL==bL && aL!=bL) || (cL==aL && bL!=aL)) //check if all the sides are different
        std::cout<<"The triangle is isosceles"; //if they are different then the triangle is isosceles
    else
        std::cout<<"The triangle is scalene"; //if the all sides are not equal and not different then the triangle is scalene
    
    if((aL*aL==bL*bL+cL*cL) || (bL*bL==aL*aL + cL*cL) || (cL*cL==aL*aL + bL*bL)) //verification by Pythagorean theorem c^2=a^2+b^2
        std::cout<<" and right-angled."<<std::endl; //if it is true then the triangle is right-angled
    else if((pow(aL, 2)>pow(bL, 2)+pow(cL, 2)) || (pow(bL, 2)>pow(aL, 2)+pow(cL, 2)) || (pow(cL, 2)>pow(aL,2 )+pow(bL, 2))) //check if one of the sides of the triangle is bigger than the sum of the other 2 sides
        std::cout<<" and obtuse-angled."<<std::endl; //if it is true then the triangle is obtuse-angled
    else
        std::cout<<" and acute-angled."<<std::endl; //if it is false then the triangle is acute-angled
    return 0;
}

double Triangle::area(){ //definition of a function which find the area of a triangle
    //creating 3 variable values from type double which are equal to the corresponding length
    double aL=a.length();
    double bL=b.length();
    double cL=c.length();
    double p=(aL+bL+cL)/2; //semi-perimeter
    
    return sqrt(p*(p - aL)*(p - bL)*(p - cL)); //S = √p(p - a)(p - b)(p - c) Heron formula
}

double Triangle::perimeter(){ //definition of a function which find the perimeter of a triangle
    return a.length()+b.length()+c.length(); //a+b+c; sum of the 3 sides
}

Point Triangle::medicenter(){ //definition of a function which find the medicenter of a triangle
    //creating 3 variable values from type double which are equal to the sum of each x, y, and z coordinates of the points divided by 3
    double x=(p1.get_x()+p2.get_x()+p3.get_x())/3; //(x1+x2+x3)/3
    double y=(p1.get_y()+p2.get_y()+p3.get_y())/3; //(y1+y2+y3)/3
    double z=(p1.get_z()+p2.get_z()+p3.get_z())/3; //(z1+z2+z3)/3
    return Point(x,y,z); //returns a point(coordinates) which is the medicenter
}

bool operator<(const Point& P, const Triangle& t){ //overloading operator <; giving names of the objects from type const Point& and const Triangle&
    
    Triangle APB(t.getP1(), t.getP2(), P); //creating a triangle from 3 points(calling constructor)
    float APB_area = APB.area(); //calculating the area of this triangle
    
    Triangle BPC(t.getP2(), t.getP3(), P); //creating a triangle from 3 points(calling constructor)
    float BPC_area = BPC.area(); //calculating the area of this triangle
    
    Triangle CPA(t.getP1(), t.getP3(), P); //creating a triangle from 3 points(calling constructor)
    float CPA_area = CPA.area(); //calculating the area of this triangle
    
    Triangle ABC(t.getP1(),t.getP2(), t.getP3()); //creating a triangle from 3 points(calling constructor)
    float ABC_area = ABC.area(); //calculating the area of this triangle
    
    if(ABC_area>((APB_area + BPC_area + CPA_area)-0.00002) && ABC_area<((APB_area + BPC_area + CPA_area)+0.00002)) //greater accuracy
        return true;
    return false;
}

bool operator>(const Point& P, const Triangle& t){ //overloading operator >; giving a names of objects from type const Point& and const Triangle&
    //creating vectors from 2 points(calling constructor)
    Vector v1(t.getP1(), t.getP2());
    Vector v2(t.getP1(), t.getP3());
       //calculating the coefficients; a, b and c are the coefficients we get from the Cartesian work
       double a = v1.get_y() * v2.get_z() - v1.get_z() * v2.get_y(); //i
       double b = -(v1.get_x() * v2.get_z() - v1.get_z() * v2.get_x()); //j
       double c = (v1.get_x() * v2.get_y() - v1.get_y() * v2.get_x()); //k
    
       double d = - (a * t.getP1().get_x() + b * t.getP1().get_y() + c * t.getP1().get_z()); //formula for the distance between a point and a plane
       double temp = abs(a * P.get_x() + b * P.get_y() + c * P.get_z() + d); //numerator
       double denominator = sqrt(a * a + b * b + c * c); //denominator

       double distance = temp / denominator * 0.1; //calculating the distance
       
    
    return (!distance && !(P<t)); //if distance is different from 0 and the point is outside the triangle, the function returns true
}

bool operator==(const Point& P, const Triangle& t){ //overloading operator ==; giving a names of objects from type const Point& and const Triangle&
    //creating points which are equal to points from the triangle
    Point A=t.getP1();
    Point B=t.getP2();
    Point C=t.getP3();
    if(isBetween(A, B, P)) return true; //calling isBetween function which check if a point lies on some side of a triangle; if this point lies between A and B->true
    else if(isBetween(B, C, P)) return true; //calling isBetween function which check if a point lies on some side of the triangle; if this point lies between B and C->true
    else if(isBetween(A, C, P)) return true; //calling isBetween function which check if a point lies on some side of the triangle; if this point lies between A and C->true
    return false;
}

bool isBetween(const Point& A, const Point& B, const Point& P){ //definition of a function which check if a point lies on some side of a triangle
    //creating vectors from 2 points(calling constructors)
    Vector AB(A,B);
    Vector AP(A, P);
    Vector PB(P, B);
    double temp = AP.length()+PB.length(); //creating a variable value which calculate the length from the beginning of the vector to the point and from the point to the end of the vector; AP+PB
    return AB.length()>(temp-0.00001) && AB.length()<(temp+0.00001); //if the vector is equal to the value obtained with temp then the function returns true, so the point lies on some of the sides of a triangle
}

//declaration of a setter for object p1 from type Point
int Triangle::setP1(Point p1) {
    this->p1 = p1;
    return 0;
}

//declaration of a setter for object p2 from type Point
int Triangle::setP2(Point p2) {
    this->p2 = p2;
    return 0;

//declaration of a setter for object p3 from type Point
}int Triangle::setP3(Point p3) {
    this->p3 = p3;
    return 0;
}

//declaration of a getter for object p1 from type Point
Point Triangle::getP1() const {
    return p1;
}

//declaration of a getter for object p2 from type Point
Point Triangle::getP2() const {
    return p2;
}

//declaration of a getter for object p3 from type Point
Point Triangle::getP3() const {
    return p3;
}

// declaration of a setter for object a from type Vector
int Triangle::setA(Vector a) {
    this->a = a;
    return 0;
}

// declaration of a setter for object b from type Vector
int Triangle::setB(Vector b) {
    this->b = b;
    return 0;

// declaration of a setter for object c from type Vector
}int Triangle::setC(Vector c) {
    this->c = c;
    return 0;
}

//declaration of a getter for object a from type Vector
Vector Triangle::getA() const {
    return a;
}

//declaration of a getter for object b from type Vector
Vector Triangle::getB() const {
    return b;
}

//declaration of a getter for object c from type Vector
Vector Triangle::getC() const {
    return c;
}

std::ostream& Triangle::ins(std::ostream& out) const { //definition of inserter; giving a name of an object from type const ostream&
    out << "A:\n" << p1 << std::endl; //print A
    out << "B:\n" << p2 << std::endl; //print B
    out << "C:\n" << p3 << std::endl; //print C
    return out; //returns changed object from type ostream&
}

std::istream& Triangle::ext(std::istream& in) { //definition of extractor; giving a name of an object from type const istream&
    //creating objects from type Point
    Point A;
    Point B;
    Point C;

    std::cin >> A >> B >> C; //entering coodinates of the points
    Triangle tmp(A, B, C); //creating an object from type Triangle with 3 point
    *this = tmp; //pointer 'this' approptiates the data which object 'tmp' contains
    return in; //returns changed object from type istream&
}


