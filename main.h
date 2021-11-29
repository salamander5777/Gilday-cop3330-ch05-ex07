/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Michael Gilday
 */

#include <iostream>
#include <cmath>

//Chapter 5, exercise #7 - (Program that solves for the quadratic roots when given the input of a, b, and c.)
//The general formula for solving an equation in the format of ax^2+bx+c is x = (-b (+/-) sqrt(b^2-4ac))/2a

//This method is used to find the disciminant which is the math found under the square root in the equation.
double discriminant(double a, double b, double c)
{
  double disc = (b*b)-(4*a*c);
  return disc;
}

//This method is used when a is set to 0.
double alpha_zero(double b, double c)
{
  double a0 = (-c/b);
  return a0;
}

//This method solves for the root where the formula uses -b+sqrt....
double root1(double a, double b, double disc)
{
  double root = ((-b+sqrt(disc))/(2*a));
  return root;
}

//This method solves for the root where the formula uses -b-sqrt....
double root2(double a, double b, double disc)
{
  double nroot = ((-b-sqrt(disc))/(2*a));
  return nroot;
}

//This method solves for the imaginary root when the discriminant is negative, as negatives under a squareroot create some issues.
double imaginary_1(double a, double b)
{
  double imroot = (-b/(2*a));
  return imroot;
}

//This method solves for the second imaginary root when the discriminant is negative, as negatives under a squareroot create some issues.
double imaginary_2(double a, double disc)
{
  double imroot = (sqrt(-disc)/(2*a));
  return imroot;
}

//This method is used to call the respective methods used to roots.
void root_solver(double a, double b, double c){
  double disc = discriminant(a, b, c);
  
  //This 'if' staircase verifies if the input of 'a' is 0 and then whether 'b' & 'c' are also 0, as these can create different errors in solving for roots.
  if(a == 0){
    if(b == 0){
      if(c == 0){
        std::cout << "0";
      }
      else{
        std::cout << "Undefined roots.";
      }
    }
    else{
      std::cout << "The root is: " << alpha_zero(b, c);
    } 
  }
  else if(disc < 0){ //The roots would be imaginary as the formula can not normally account for sqrt(negative#)
    std::cout << "The roots of are: " << imaginary_1(a, b) << "+" << imaginary_2(a, disc) << "i, " << imaginary_1(a, b) << "-" << imaginary_2(a, disc) << "i";
  }
  else if(disc == 0){ //There is only one root as there is no +/- for a discriminant of 0.
    double x = root1(a, b, disc);
    std::cout << "The root is: " << x;
  }
  else if(disc > 0){ //The discriminant is positive which implies the existence of two normal roots.
    double x1 = root1(a, b, disc);
    double x2 = root2(a, b, disc);
    std::cout << "The roots are: " << x1 << ", " << x2;
  }
}
