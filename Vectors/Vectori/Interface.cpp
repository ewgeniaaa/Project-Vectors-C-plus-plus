//
//  Interface.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 2.06.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Interface.hpp"


int print_MainMenu() { //definition of function which prints the main menu
    //printing the elements from which the user can choose
    std::cout << "MAIN MENU\n\n";
    std::cout << "Please choose an element.\n";
    std::cout << "1) Point\n";
    std::cout << "2) Vector\n";
    std::cout << "3) Line\n";
    std::cout << "4) Segment\n";
    std::cout << "5) Triangle\n";
    std::cout << "6) Tetrahedron\n";
    std::cout << "OPTION: ";
    
    return 0;
}

int print_PointMenu() { //definition of function which prints the point menu
    std::cout << "\nPlease choose an operation.\n";
    std::cout << "1) Check if 2 points are identical\n";
    std::cout << "OPTION: ";
    
    return 0;
}
int point_Operations(){ //all defined functions in the class Point
    Point A;
    std::cin>>A;
    int sub_choice; //a variable value to choose from
    do {
        print_PointMenu(); //calling the function about point menu
        std::cin>>sub_choice; //the user enters the option which she/he has chosen
        switch (sub_choice) {
            case 1:{ //if option 1
                Point B;
                std::cin>>B;
                std::cout<<std::boolalpha<<(A==B)<<std::noboolalpha<<std::endl; //checking if 2 points are equal
                break;
            }
            default: //there is no such an option
                std::cout<<"Incorrect value\n";
                break;
        }
        std::cout<<"Do you want to choose another operation? (y/n)"; //asking the user if he/she wants to continue
        char ch;
        std::cin>>ch;
        if(ch=='n') //if the user chooses 'n' the program ends
            sub_choice = 0;

    } while (sub_choice); //the program continues while the user enters possible values for a choice
    return 0;
}

int print_VectorMenu(){ //definition of function which prints the vector menu
    std::cout << "\nPlease choose an operation.\n";
    std::cout << "1) Calculate length\n";
    std::cout << "2) Calculate direction\n";
    std::cout << "3) Check for 0 vector\n";
    std::cout << "4) Check if 2 vectors are parallel\n";
    std::cout << "5) Check if 2 vectors are perpendicular\n";
    std::cout << "6) Add 2 vectors\n";
    std::cout << "7) Substract 2 vectors\n";
    std::cout << "8) Multiplication of vector and number\n";
    std::cout << "9) Scalar multiplication of 2 vectors\n";
    std::cout << "10) Vector multiplication of 2 vectors\n";
    std::cout << "11) Combined multiplication of 3 vectors\n";
    std::cout << "OPTION: ";
    
    return 0;
}
int vector_Operations(){ //all defined functions in the class Vector
    Vector A;
    std::cin>>A;
   
       int sub_choice;
       do {
           print_VectorMenu(); //calling the function about vector menu
           std::cin>>sub_choice;
           switch (sub_choice) {
               case 1:{ //if option 1
                   std::cout<<"The length is: "<<std::setprecision(2)<<A.length()<<std::endl; //calculating the length
                   break;
               }
               case 2:{ //if option 2
                   try {
                       std::cout<<"The direction vector is:\n"<<A.direction()<<std::endl; //calculating the direction
                   }
                   //if direction=0 then the function throws exception
                   catch (VectorLengthException& e) {
                       std::cout<<e.what()<<std::endl;
                   }
                   catch (std::exception& e){
                       std::cout<<e.what()<<std::endl;
                   }
                   break;
               }
               case 3:{ //if option 3
                   std::cout<<std::boolalpha<<(A.zeroVector())<<std::noboolalpha<<std::endl; //checking if the vector is equal to 0
                   break;
               }
               case 4:{ //if option 4
                   try{
                       Vector B;
                       std::cin>>B;
                       std::cout<<std::boolalpha<<(A.isParallel(B))<<std::noboolalpha<<std::endl; //checking if the vector is parallel to another vector
                   }
                   //if the vector is equal to 0 then the function throws exception
                   catch (VectorLengthException& e) {
                       std::cout<<e.what()<<std::endl;
                   }
                   catch (std::exception& e){
                       std::cout<<e.what()<<std::endl;
                   }
                   break;
               }
                case 5:{ //if option 5
                    try{
                        Vector B;
                        std::cin>>B;
                        std::cout<<std::boolalpha<<(A.isPerpen(B))<<std::noboolalpha<<std::endl; //checking if the vector is perpendicular to another vector
                    }
                    //if the vector is equal to 0 then the function throws exception
                    catch (VectorLengthException& e) {
                        std::cout<<e.what()<<std::endl;
                    }
                    catch (std::exception& e){
                        std::cout<<e.what()<<std::endl;
                    }
                    break;
                   }
                case 6:{ //if option 6
                   Vector B;
                   std::cin>>B;
                   std::cout<<"The final vector is:\n"<<(A+B)<<std::endl; //sum of two vectors
                   break;
               }
                case 7:{ //if option 7
                    Vector B;
                    std::cin>>B;
                    std::cout<<"The final vector is:\n"<<(A-B)<<std::endl; //subtract of two vectors
                    break;
                }
                case 8:{ //if option 8
                    double x;
                    std::cout<<"Enter number: ";
                    std::cin>>x;
                    std::cout<<"The final vector is:\n"<<(A*x)<<std::endl; //multipling vector and number
                    break;
                }
                case 9:{ //if option 9
                    Vector B;
                    std::cin>>B;
                    std::cout<<(A*B)<<std::endl; //scalar multiplication of two vectors
                    break;
                }
                case 10:{ //if option 10
                    Vector B;
                    std::cin>>B;
                    std::cout<<"The final vector is:\n"<<(A^B)<<std::endl; //vector multiplication
                    break;
                }
                case 11:{ //if option 11
                    Vector B;
                    std::cin>>B;
                    Vector C;
                    std::cin>>C;
                    std::cout<<(A(B,C))<<std::endl; //mixed multiplication of two vectors
                    break;
                }
               default: //there is no such an option
                   std::cout<<"Incorrect value\n";
                   break;
           }
           std::cout<<"Do you want to choose another operation? (y/n)"; //asking the user if he/she wants to continue
           char ch;
           std::cin>>ch;
           if(ch=='n') //if the user chooses 'n' the program ends
               sub_choice = 0;

       } while (sub_choice); //the program continues while the user enters possible values for a choice
    return 0;
}

int print_LineMenu(){ //definition of function which prints the line menu
    std::cout << "\nPlease choose an operation.\n";
    std::cout << "1) Find direction\n";
    std::cout << "2) Find normal vector\n";
    std::cout << "3) Find the angle between 2 lines\n";
    std::cout << "4) Check if a point lies on the line\n";
    std::cout << "5) Check if a line is parallel to another line\n";
    std::cout << "6) Chech if a line is identical to another line\n";
    std::cout << "7) Check if a line intersects another line\n";
    std::cout << "8) Check if a line is skew to another line\n";
    std::cout << "9) Check if a line is perpendicular to another line\n";
    std::cout << "OPTION: ";
    
    return 0;
}
int line_Operations(){ //all defined functions in the class Line
    Line A;
    std::cin>>A;
   
       int sub_choice;
       do {
           print_LineMenu(); //calling the function about line menu
           std::cin>>sub_choice;
           switch (sub_choice) {
               case 1:{ //if option 1
                    try {
                        std::cout<<"The direction is:\n"<<A.direction()<<std::endl; //calculating the direction of the line
                    }
                    ////if the vector is equal to 0 then the function throws exception
                    catch (VectorLengthException& e) {
                        std::cout<<e.what()<<std::endl;
                    }
                    catch (std::exception& e){
                        std::cout<<e.what()<<std::endl;
                    }
                    break;
                }
        
               case 2:{ //if option 2
                   std::cout<<"The normal vector is:\n"<<A.normal()<<std::endl; //finding the normal vector
                   break;
               }
               case 3:{ //if option 3
                   Line B;
                   std::cin>>B;
                   std::cout<<"The angle is: "<<A.angle(B)<<" rad"<<std::endl; //finding the angle between two lines
                   break;
               }
               case 4:{ //if option 4
                   Point P;
                   std::cin>>P;
                   std::cout<<std::boolalpha<<(A+P)<<std::noboolalpha<<std::endl; //checking if a point lies on a line
                   break;
               }
                case 5:{ //if option 5
                    Line B;
                    std::cin>>B;
                    std::cout<<std::boolalpha<<(A||B)<<std::noboolalpha<<std::endl; //checking if a line is parallel to another line
                    break;
                   }
                case 6:{ //if option 6
                   Line B;
                   std::cin>>B;
                   std::cout<<std::boolalpha<<(A==B)<<std::noboolalpha<<std::endl; //checking if a line coincides with another line
                    break;
               }
                case 7:{ //if option 7
                    Line B;
                    std::cin>>B;
                    std::cout<<std::boolalpha<<(A&&B)<<std::noboolalpha<<std::endl; //checking if a line intersects another line
                    break;
                }
                case 8:{ //if option 8
                    Line B;
                    std::cin>>B;
                    std::cout<<std::boolalpha<<(A!=B)<<std::noboolalpha<<std::endl; //checking if a line crosses another line
                    break;
                }
                case 9:{ //if option 9
                    Line B;
                    std::cin>>B;
                    std::cout<<std::boolalpha<<(A|B)<<std::noboolalpha<<std::endl; //checking if a line is perpendicular to another line
                    break;
                }
               default: //there is no such an option
                   std::cout<<"Incorrect value\n";
                   break;
           }
           std::cout<<"Do you want to choose another operation? (y/n)"; //asking the user if he/she wants to continue
           char ch;
           std::cin>>ch;
           if(ch=='n') //if the user chooses 'n' the program ends
               sub_choice = 0;

       } while (sub_choice); //the program continues while the user enters possible values for a choice
    
    return 0;
}

int print_SegmentMenu(){ //definition of function which prints the segment menu
    std::cout << "\nPlease choose an operation.\n";
       std::cout << "1) Calculate the length\n";
       std::cout << "2) Calculate the middle point\n";
       std::cout << "3) Check if a point lies on the segment\n";
       std::cout << "OPTION: ";
    return 0;
}
int segment_Operations(){ //all defined functions in the class Segment
    Segment A;
     std::cin>>A;
    
        int sub_choice;
        do {
            print_SegmentMenu(); //calling the function about segment menu
            std::cin>>sub_choice;
            switch (sub_choice) {
                case 1:{ //if option 1
                    std::cout<<"The length is: "<<A.length()<<std::endl; //calculating the length of the segment
                     break;
                 }
         
                case 2:{ //if option 2
                    std::cout<<"The middle point is:\n"<<A.middlePoint()<<std::endl; //finding the middle of the segment
                    break;
                }
                case 3:{ //if option 3
                    Point P;
                    std::cin>>P;
                    std::cout<<std::boolalpha<<(A==P)<<std::noboolalpha<<std::endl; //checking if a point lies on a segment
                    break;
                }
                default: //there is no such an option
                    std::cout<<"Incorrect value\n";
                    break;
            }
            std::cout<<"Do you want to choose another operation? (y/n)"; //asking the user if he/she wants to continue
            char ch;
            std::cin>>ch;
            if(ch=='n') //if the user chooses 'n' the program ends
                sub_choice = 0;

        } while (sub_choice); //the program continues while the user enters possible values for a choice
    return 0;
}

int print_TriangleMenu(){ //definition of function which prints the triangle menu
    std::cout << "\nPlease choose an operation.\n";
       std::cout << "1) Find the triangle type\n";
       std::cout << "2) Calculate the area\n";
       std::cout << "3) Calculate the perimeter\n";
       std::cout << "4) Find the incenter\n";
       std::cout << "5) Check if a point lies inside the triangle\n";
       std::cout << "6) Chech if a point lies on the same plane as the triangle but is not inside it\n";
       std::cout << "7) Check if a point lies on one of the sides of the triangle\n";
       std::cout << "OPTION: ";
    return 0;
}
int triangle_Operations(){ //all defined functions in the class Triangle
    Triangle A;
    try {
        std::cin>>A;
    }
    //if two or more of the point coincides the function throws an exception
    catch (EqualPointException& e) {
        std::cout<<e.what()<<std::endl;
    }
    catch (std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
          int sub_choice;
          do {
              print_TriangleMenu(); //calling the function about triangle menu
              std::cin>>sub_choice;
              switch (sub_choice) {
                  case 1:{ //if option 1
                      A.triangle_type(); //a function about triangle's type
                      break;
                   }
                  case 2:{ //if option 2
                      std::cout<<"The area is: "<<std::setprecision(2)<<A.area()<<std::endl; //calculating the area of a triangle
                      break;
                  }
                  case 3:{ //if option 3
                      std::cout<<"The perimeter is: "<<A.perimeter()<<std::endl; //calculating the perimeter of a triangle
                      break;
                  }
                  case 4:{ //if option 4
                      std::cout<<"The medicenter is:\n"<<A.medicenter()<<std::endl; //finding the medicenter of a triangle
                      break;
                  }
                   case 5:{ //if option 5
                       Point B;
                       std::cin>>B;
                       std::cout<<std::boolalpha<<(B<A)<<std::noboolalpha<<std::endl; //checking if a point lies on the triangle's plane and is inside it
                       break;
                      }
                   case 6:{ //if option 6
                      Point B;
                      std::cin>>B;
                      std::cout<<std::boolalpha<<(B>A)<<std::noboolalpha<<std::endl; //checking if a point lies on the triangle's plane and is outside it
                       break;
                  }
                   case 7:{ //if option 7
                       Point B;
                       std::cin>>B;
                       std::cout<<std::boolalpha<<(B==A)<<std::noboolalpha<<std::endl; //checking if a point lies on a side of a triangle
                       break;
                   }
                  default: //there is no such an option
                      std::cout<<"Incorrect value\n";
                      break;
              }
              std::cout<<"Do you want to choose another operation? (y/n)"; //asking the user if he/she wants to continue
              char ch;
              std::cin>>ch;
              if(ch=='n') //if the user chooses 'n' the program ends
                  sub_choice = 0;

          } while (sub_choice); //the program continues while the user enters possible values for a choice
       
    return 0;
}

int print_TetrahedronMenu(){ //definition of function which prints the tetrahedron menu
    std::cout << "\nPlease choose an operation.\n";
       std::cout << "1) Check if it is right\n";
       std::cout << "2) Check if it orthocentric\n";
       std::cout << "3) Calculate the area\n";
       std::cout << "4) Calculate the volume\n";
       std::cout << "5) Check if a point lies on the tetrahedron\n";
       std::cout << "6) Chech if a point lies on one of the planes of the tetrahedron but is not on it\n";
       std::cout << "7) Check if a point lies on one of the edges of the tetrahedron\n";
       std::cout << "OPTION: ";
    return 0;
}
int tetrahedron_Operations(){ //all defined functions in the class Tetrahedron
    Tetrahedron A;
    try {
        std::cin>>A;
    }
    //if two or more of the point coincides the function throws an exception
    catch (EqualPointException& e) {
        std::cout<<e.what()<<std::endl;
    }
    catch (std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
          int sub_choice;
          do {
              print_TetrahedronMenu(); //calling the function about tetrahedron menu
              std::cin>>sub_choice;
              switch (sub_choice) {
                  case 1:{ //if option 1
                      std::cout<<std::boolalpha<<A.isRight()<<std::noboolalpha<<std::endl; //checking if a tetrahedron is right
                      break;
                   }
                  case 2:{ //if option 2
                      std::cout<<std::boolalpha<<A.isOrthocentric()<<std::noboolalpha<<std::endl; //checking if a tetrahedron is orthocentric
                      break;
                  }
                  case 3:{ //if option 3
                      std::cout<<"The area is: "<<A.Area()<<std::endl; //calculating the tetrahedron's area
                      break;
                  }
                  case 4:{ //if option 4
                      std::cout<<"The volume is:\n"<<A.Volume()<<std::endl; //calculating the tetrahedron's volume
                      break;
                  }
                   case 5:{ //if option 5
                       Point B;
                       std::cin>>B;
                       std::cout<<std::boolalpha<<(B<A)<<std::noboolalpha<<std::endl; //checking if a point lies on the tetrahedron's plane and is inside it
                       break;
                      }
                   case 6:{ //if option 6
                      Point B;
                      std::cin>>B;
                      std::cout<<std::boolalpha<<(B>A)<<std::noboolalpha<<std::endl; //checking if a point lies on the tetrahedron's plane and is outside it
                       break;
                  }
                   case 7:{ //if option 7
                       Point B;
                       std::cin>>B;
                       std::cout<<std::boolalpha<<(B==A)<<std::noboolalpha<<std::endl; //checking if a point lies on a side of a tetrohedron
                       break;
                   }
                  default: //there is no such an option
                      std::cout<<"Incorrect value\n";
                      break;
              }
              std::cout<<"Do you want to choose another operation? (y/n)"; //asking the user if he/she wants to continue
              char ch;
              std::cin>>ch;
              if(ch=='n') //if the user chooses 'n' the program ends
                  sub_choice = 0;

          } while (sub_choice); //the program continues while the user enters possible values for a choice
       
    return 0;
}
