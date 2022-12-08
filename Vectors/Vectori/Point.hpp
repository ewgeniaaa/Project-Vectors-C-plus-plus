//
//  Point.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 28.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp
#include <iostream>                            //Including iostream lybrary.
#include "Elements.hpp"                        //Usage of separate compilation; including the .hpp(header) file of the abstract class Elements.

class Point : public Elements{                 //Creating a class, dirived by the abstract class Elements that makes a geometrical point with 3 cordinates.
public:     //public access specifier
    Point();                                   //Declaration of the default constructor of class Point.
    Point(double, double, double);             //Declaration of the constructor with parameters: three real numbers(double values), which are the cordinates: (x, y, z)
    Point(const Point&);                       //Declaration of the copy-constructor.
    ~Point();                                  //Declaration of the destructor of class Point.
    Point& operator=(const Point&);            //Declaration for overloading the equal sign (=) for objects of type Point.
    void set_x(double);                        //Declaration of the setter of the cordinate x.
    void set_y(double);                        //Declaration of the setter of the cordinate y.
    void set_z(double);                        //Declaration of the setter of the cordinate z.
    double get_x() const;                      //Declaration of the getter of the cordinate x.
    double get_y() const;                      //Declaration of the getter of the cordinate y.
    double get_z() const;                      //Declaration of the getter of the cordinate z.
    
    std::ostream& ins(std::ostream&) const;    //Declaration of inserter member function.
    std::istream& ext(std::istream&);          //Declaration of extracter member function.
   
private:    //private access specificator
    double cord_x;                             //Member data of the double cordinate x.
    double cord_y;                             //Member data of the double cordinate y.
    double cord_z;                             //Member data of the double cordinate z.
};

 bool operator==(const Point&, const Point&); //Declaration of an external function for overloading operator (==).
 
#endif /* Point_hpp */
