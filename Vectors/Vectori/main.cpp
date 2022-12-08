//
//  main.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 28.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include <iostream>         //Including iostream lybrary.
#include <iomanip>          //Including iomanip lybrary.
#include "Interface.hpp"    //Usage of separate compilation; including the .hpp(header) file of Interface.
#include "Vector.hpp"       //Usage of separate compilation; including the .hpp(header) file of the class Vector.
#include "Point.hpp"        //Usage of separate compilation; including the .hpp(header) file of the class Point.
#include "Line.hpp"         //Usage of separate compilation; including the .hpp(header) file of the class Line.
#include "Segment.hpp"      //Usage of separate compilation; including the .hpp(header) file of the class Segment.
#include "Triangle.hpp"     //Usage of separate compilation; including the .hpp(header) file of the class Triangle.
#include "Tetrahedron.hpp"  //Usage of separate compilation; including the .hpp(header) file of the class Tetrahedron.

int main() {
    int choice;              //initialising a parameter of type integer.
    //do, while statement:
    do{
        print_MainMenu();    //calling a print function for the main menu.
        std::cin>>choice;    //reading from istream and putting the value in the integer.
        //switch statement:
        switch (choice) {
            case 1:{ //code to be executed if choice is equal to 1:
                point_Operations();       //calling funtion for all the functions which are defined in the class Point.
                break;                    //break statement: Causes the enclosing statement to terminate.
            }
            case 2:{ //code to be executed if choice is equal to 2:
                vector_Operations();      //calling funtion for all the functions which are defined in the class Vector and which execute after the choice.
                break;                    //break statement: Causes the enclosing statement to terminate.
            }
            case 3:{ //code to be executed if choice is equal to 3:
                line_Operations();        //calling funtion for all the functions which are defined in the class Line and which execute after the choice.
                break;                    //break statement: Causes the enclosing statement to terminate.
            }
            case 4:{ //code to be executed if choice is equal to 4:
                segment_Operations();     //calling funtion for all the functions which are defined in the class Segment and which execute after the choice.
                break;                    //break statement: Causes the enclosing statement to terminate.
            }
            case 5:{ //code to be executed if choice is equal to 5:
                triangle_Operations();    //calling funtion for all the functions which are defined in the class Triangle and which execute after the choice.
                break;                    //break statement: Causes the enclosing statement to terminate.
            }
            case 6:{ //code to be executed if choice is equal to 6:
                tetrahedron_Operations();  //calling funtion for all the functions which are defined in the class Tetrahedron and which execute after the choice.
                break;                     //break statement: Causes the enclosing statement to terminate.
            }
            default:                             //The default keyword specifies some code to run if there is no case match.
                std::cout<<"Incorrect value\n";  //for default: print text.
                break;                           //break statement: Causes the enclosing statement to terminate.
        }
        
        std::cout<<"Do you want to choose another ELEMENT? (y/n)";  //prints text.
        char ch;         //initialising a parameter of type char.
        std::cin>>ch;    //reading from istream and putting the value in the char.
        if(ch=='n')      //if statement that checks if the character is n.
            choice = 0;  //if it is the integer choice becomes equal to zero.
    }while(choice);      //do while choice is different that 0.
    
    std::cout << " GO ON, YOU CAN DO IT! \n"; //Prints uplifting text, so we can motivate ourselves! <3
    return 0;  //exit code for ensuring the program works.
}
