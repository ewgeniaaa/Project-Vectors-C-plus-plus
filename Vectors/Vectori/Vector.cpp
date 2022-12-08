//
//  Vector.cpp
//  Vectori
//
//  Created by Simeon Gelovski on 28.04.20.
//  Copyright © 2020 Simeon Gelovski. All rights reserved.
//

#include "Vector.hpp" //Usage of separate compilation; Including the .hpp(header) file of class Vector.

//Definition of the default constructor of class Vector:
Vector::Vector():Point(){}
//Definition of constructor with parameters: three real numbers:
Vector::Vector(double x, double y, double z):Point(x, y, z){}  //The data members from the parent class Point, take the values of the parameters and create an object of type Point.
//Definition of constructor with parameters: two points A and B(objects of class Point) submitted by reference:
Vector::Vector(const Point& A,const Point& B){
    //Creating a vector by subtracting point A(the beggining of the vector) from point B(the end of the vector):
    set_x(B.get_x()-A.get_x());        //sets cordinate x of the vector as: cordinate x of point B subracted by cordinate x of point A.
    set_y(B.get_y()-A.get_y());        //sets cordinate y of the vector as: cordinate y of point B subracted by cordinate y of point A
    set_z(B.get_z()-A.get_z());        //sets cordinate z of the vector as: cordinate z of point B subracted by cordinate z of point A
}
//Definition for overloading the equal sign (=) for objects of type Vector:
Vector &Vector::operator=(const Vector &rhs) {    //Member function with parameter: Point object submitted by reference (rhs: right hand side).
    if(this!=&rhs){                    //An if statement which checkes if the left and right hand side are equal: if they are then we return the left hand side.
        set_x(rhs.get_x());            //The left hand side (this) cordinate x, takes the value of the right hand side cordinate x.
        set_y(rhs.get_y());            //The left hand side (this) cordinate y, takes the value of the right hand side cordinate y.
        set_z(rhs.get_z());            //The left hand side (this) cordinate z, takes the value of the right hand side cordinate z.
    }
    return *this;                      //Return pointer (this) the left hand side with its new value.
}
//Definition of the copy-constructor:
Vector::Vector(const Vector &rhs) {              //Member function with parameter: Point object submitted by reference (rhs: right hand side).
    Point(rhs.get_x(),rhs.get_y(),rhs.get_z());
}
//Definition of the destructor of class Vector:
Vector::~Vector(){}


//Definition of a member function that calculates the lenght of a vector:
double Vector::length(){
    return sqrt(pow(get_x(),2)+pow(get_z(), 2)+pow(get_y(), 2));      //the lenght is calculated by the formula: sqrt(x^2 + y^2 + z^2), where sqrt() is the square root.
}
//Definition of a member function that calculates the direction of a vector:
Vector Vector::direction()
{
    if(this->length()==0){    //if statement to check if the lenght of the vector is equal to zero:
        //the lenght of the vector is equal to zero:
        throw VectorLengthException("The length of the vector cannot be equal to 0.");  //we throw a VectorLenghtException defined by us, because the vector cannot have lenght equal to 0.
    }
    double res_x, res_y, res_z, denominator;  //declaration of three double parameters: res_x(res: result), res_y, res_z and denominator.
    denominator = this->length();             //the denominator takes the value of the lenght of the vector.
    res_x = get_x() / denominator;            //dividing the cordinate x of the vector, by the lenght of the vector.
    res_y = get_y() / denominator;            //dividing the cordinate y of the vector, by the lenght of the vector.
    res_z = get_z() / denominator;            //dividing the cordinate z of the vector, by the lenght of the vector.
    return Vector(res_x, res_y, res_z);       //returning a direction Vector with the new values for x, y and z.
}
//Definition of a boolean member function that checks if all of the cordinates of the vector are equal to zero:
bool Vector::zeroVector()
{
    return(get_x()==get_y()&& get_y()==get_z() && get_z()==0); //checks if x=y=z=0
}
//Definition of a boolean member function that checks if two vectors are parallel to each other:
bool Vector::isParallel(const Vector & rhs) {
    if(this->length()==0){                                                        //if statement that checks if the lenght of the vector is 0
        throw VectorLengthException("One of the vectors has length equal to 0."); //throws VectorLenghtException if the lenght is 0
    }
    double crossX = get_y()*rhs.get_z()+get_z()*rhs.get_y();
    double crossY = get_x()*rhs.get_z()+get_z()*rhs.get_x();
    double crossZ = get_x()*rhs.get_y()+get_y()*rhs.get_x();

    double res = crossX*crossX + crossY*crossY + crossZ*crossZ;
    
    if(res>=-0.1 && res<=0.1)
        return true;
    return false;
}
//Definition of a boolean member function that checks if two vectors are perpendicular to each other:
bool Vector::isPerpen(const Vector &rhs) {
    if(this->length()==0){                                                        //if statement that checks if the lenght of the vector is 0
        throw VectorLengthException("One of the vectors has length equal to 0."); //throws VectorLenghtException if the lenght is 0
    }
    double res=get_x()*rhs.get_x()+get_y()*rhs.get_y()+get_z()*rhs.get_z();       //result = (x(from vector1)*x(from vector2) + y*from vector1)*y(from vector2) + z(from vector1)*z(from vector2))
    return(res==0);  //the vectors are perpendicular if the sum(result) is equal to zero
}
//Definition of a member function for overloading operator+
Vector Vector::operator+(const Vector &rhs) { //giving a name of an object from type const Vector&
    Vector result;  //initialising a Vector with default canstructor, that is called result
    result.set_x(get_x()+rhs.get_x()); //sets cordinate x of vector result: as the sum of the two x cordinates of the vectors
    result.set_y(get_y()+rhs.get_y()); //sets cordinate y of vector result: as the sum of the two x cordinates of the vectors
    result.set_z(get_z()+rhs.get_z()); //sets cordinate z of vector result: as the sum of the two x cordinates of the vectors
    return result; //returns the new vector
}
//Definition of a member function for overloading operator-
Vector Vector::operator-(const Vector &rhs) { //giving a name of an object from type const Vector&
    Vector result;  //initialising a Vector with default canstructor, that is called result
    result.set_x(get_x()-rhs.get_x()); //sets cordinate x of vector result: as the subtraction of the two x cordinates of the vectors
    result.set_y(get_y()-rhs.get_y()); //sets cordinate y of vector result: as the subtraction of the two y cordinates of the vectors
    result.set_z(get_z()-rhs.get_z()); //sets cordinate z of vector result: as the subtraction of the two z cordinates of the vectors
    return result; //returns the new vector
}
//Definition of a member function for overloading operator* (for multiplying vector with a real number):
Vector Vector::operator*(double a) { //giving a name of number from type double
    Vector result;  //initialising a Vector with default canstructor, that is called result
    result.set_x(get_x()*a); //sets cordinate x of vector result: as the multiplycation of the cordinate x of a vector and the number a
    result.set_y(get_y()*a); //sets cordinate y of vector result: as the multiplycation of the cordinate y of a vector and the number a
    result.set_z(get_z()*a); //sets cordinate z of vector result: as the multiplycation of the cordinate z of a vector and the number a
    return result; //returns the new vector
}
//Definition of a member function for overloading operator* (for multiplying vector with a vector):
double Vector::operator*(const Vector &rhs) {  //giving a name of an object from type const Vector&
    return get_x()*rhs.get_x()+get_y()*rhs.get_y()+get_z()*rhs.get_z(); //(x(from vector1)*x(from vector2) + y*from vector1)*y(from vector2) + z(from vector1)*z(from vector2))
}
//Definition of a member function for overloading operator^
Vector Vector::operator^(const Vector &rhs) {  //giving a name of an object from type const Vector&
    Vector result;  //initialising a Vector with default canstructor, that is called result
    result.set_x(get_y()*rhs.get_z()-get_z()*rhs.get_y());
    result.set_y(-get_x()*rhs.get_z()+get_z()*rhs.get_x());
    result.set_z(get_x()*rhs.get_y()-get_y()*rhs.get_x());
    return result;
}
//Definition of a member function for overloading operator()
double Vector::operator()(const Vector& rhs, const Vector& w) { //giving a name for two object from type const Vector&
    Vector result;  //initialising a Vector with default canstructor, that is called result
    result.set_x(get_y()*rhs.get_z()-get_z()*rhs.get_y());  //sets cordinate x of vector result: y(vector1) * z(vector2) - z(vector1) * y(vector2)
    result.set_y(-get_x()*rhs.get_z()+get_z()*rhs.get_x()); //sets cordinate y of vector result: - x(vector1) * z(vector2) + z(vector1) * x(vector2)
    result.set_z(get_x()*rhs.get_y()-get_y()*rhs.get_x());  //sets cordinate z of vector result: x(vector1) * y(vector2) - y(vector1) * x(vector2)
    
   return result*w; //returns the new vector multiplied with the vector w
}
//Definition of the getter of a vector:
Vector Vector::get_Vector()const{
    return Vector(get_x(), get_y(), get_z());   //returns the vector with cordinates x, y, z
}
//Definition of inserter member function:
std::ostream& Vector::ins(std::ostream& out) const{ //giving a name of an object from type const ostream&
    out<<"x = "<<get_x()<<std::endl; //writes "x=" and cordinate x
    out<<"y = "<<get_y()<<std::endl; //writes "y=" and cordinate y
    out<<"z = "<<get_z()<<std::endl; //writes "z=" and cordinate z
    return out; //returns changed object from type ostream&
}
//Definition of extracter member function:
std::istream& Vector::ext(std::istream& in){ //giving a name of an object from type const istream&
    std::cout<<"\nHow do you want to create the vector?\n"; //prints text
    std::cout<<"1) By 3 values\n"; //prints text
    std::cout<<"2) By 2 points\n"; //prints text
    std::cout<<"OPTION: "; //prints text
    int tmp; //initialising an int value with the name tmp(temporary)
    std::cin>>tmp; //reading tmp from input stream
    if (tmp==2) {  //if statement that checks if tmp is equal to 2
        Point P1;  //creating a Point with default constructor
        Point P2;  //creating a Point with default constructor
        std::cin>>P1>>P2; //reading the information for the two points from input stream
        Vector B(P1, P2); //creating a Vector with canstructor with parameters: the two points
        set_x(B.get_x()); //sets x as the cordinate x of the Vector we created
        set_y(B.get_y()); //sets y as the cordinate y of the Vector we created
        set_z(B.get_z()); //sets z as the cordinate z of the Vector we created
    }
    else{ //the value tmp wasn't equal to 2
        double x, y, z; //initialising three double values with the names a, b, c
        std::cout<<"\nEnter coordinates of the vector\n"; //prints text
        std::cout<<"x = "; //prints "x="
        in>>x;             //reads cordinate x
        std::cout<<"y = "; //prints "y="
        in>>y;             //reads cordinate y
        std::cout<<"z = "; //prints "z="
        in>>z;             //reads cordinate z
        set_x(x); //sets x as the x that was just read
        set_y(y); //sets y as the y that was just read
        set_z(z); //sets z as the z that was just read
    }
    return in; //returns changed object from type istream&
}
