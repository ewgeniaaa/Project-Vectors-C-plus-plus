//
//  Interface.hpp
//  Vectori
//
//  Created by Simeon Gelovski on 2.06.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#ifndef Interface_hpp
#define Interface_hpp

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "Point.hpp"
#include "Vector.hpp"
#include "Line.hpp"
#include "Segment.hpp"
#include "Triangle.hpp"
#include "Tetrahedron.hpp"

//main menu
int print_MainMenu(); //а function which prints the main menu from which the user chooses an element

//point
int print_PointMenu(); //а function which prints the point menu from which the user chooses a task
int point_Operations(); //all the functions which are defined in the class Point

//vector
int print_VectorMenu(); //а function which prints the vector menu from which the user chooses how to create a vector and a task
int vector_Operations(); //all the functions which are defined in the class Vector and which execute after the choice

//line
int print_LineMenu(); //а function which prints the Line menu from which the user chooses how to create a line and a task
int line_Operations(); //all the functions which are defined in the class Line and which execute after the choice

//Segment
int print_SegmentMenu(); //а function which prints the Segment menu from which the user chooses how to create a segment and a task
int segment_Operations(); //all the functions which are defined in the class Segment and which execute after the choice

//Triangle
int print_TriangleMenu(); //а function which prints the Triangle menu from which the user chooses a task
int triangle_Operations(); //all the functions which are defined in the class Triangle and which execute after the choice

//Tetrahedron
int print_TetrahedronMenu(); //а function which prints the Segment menu from which the user chooses a task
int tetrahedron_Operations();//all the functions which are defined in the class Tetrahedron and which execute after the choice

#endif /* Interface_hpp */
