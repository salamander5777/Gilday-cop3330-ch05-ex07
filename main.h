/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Michael Gilday
 */

#include <iostream>
#include <cmath>

//Chapter 5, exercise #7 - (Program that solves for the quadratic roots when given the input of a, b, and c.)

double discriminant(double a, double b, double c)
{
  double disc = (b*b)-(4*a*c);
  return disc;
}

double alpha_zero(double b, double c)
{
  double a0 = (-c/b);
  return a0;
}

double root1(double a, double b, double disc)
{
  double root = ((-b+sqrt(disc))/(2*a));
  return root;
}

double root2(double a, double b, double disc)
{
  double nroot = ((-b-sqrt(disc))/(2*a));
  return nroot;
}

double imaginary_1(double a, double b)
{
  double imroot = (-b/(2*a));
  return imroot;
}

double imaginary_2(double a, double disc)
{
  double imroot = (sqrt(-disc)/(2*a));
  return imroot;
}

int main() {
  double a, b, c;
  std::cout << "Input the value of 'a': ";
  std::cin >> a;
  std::cout << "Input the value of 'b': ";
  std::cin >> b;
  std::cout << "Input the value of 'c': ";
  std::cin >> c;

  double disc = discriminant(a, b, c);

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
  else if(disc < 0){
    std::cout << "The roots of are: " << imaginary_1(a, b) << "+" << imaginary_2(a, disc) << "i, " << imaginary_1(a, b) << "-" << imaginary_2(a, disc) << "i";
  }
  else if(disc == 0){
    double x = root1(a, b, disc);
    std::cout << "The root is: " << x;
  }
  else if(disc > 0){
    double x1 = root1(a, b, disc);
    double x2 = root2(a, b, disc);
    std::cout << "The roots are: " << x1 << ", " << x2;
  }

  //The results appear plausible and are believed to be correct as they appear to be the same results when worked out by hand or when compared to the results of an online quadratic calculator.
} 