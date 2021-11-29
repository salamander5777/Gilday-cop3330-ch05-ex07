/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Michael Gilday
 */

#include "main.h"

int main() {
  double a, b, c;
  std::cout << "Input the value of 'a': ";
  std::cin >> a;
  std::cout << "Input the value of 'b': ";
  std::cin >> b;
  std::cout << "Input the value of 'c': ";
  std::cin >> c;

  root_solver(a, b, c);

  //The results appear plausible and are believed to be correct as they appear to be the same results when worked out by hand or when compared to the results of an online quadratic calculator.
}
