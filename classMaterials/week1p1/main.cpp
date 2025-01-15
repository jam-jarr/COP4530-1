#include <iostream>  //provide definitions needed for IO
#include <cstdlib> //provide standard system definition
#include "madLibs.cpp"
using namespace std; //make std available
/// Calculate the sum of two numbers
/// \return 0
int main1(){
    int x, y;
    cout << "Please enter two numbers: ";
    cin >> x >> y; //input x and y
    int sum = x + y; //compute sum
    cout << "Sum of the two number is: "<< sum << std::endl;
    return EXIT_SUCCESS; //terminate successfully
}