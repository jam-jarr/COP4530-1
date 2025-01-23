#include <iostream>
#include <ostream>
#include <string>
using namespace std;
class Point{
    // private: access only within the parent class
    // protected: use in this class but also
    // can be used in inherent class
    // public: can bes access outside of class
    // within inherited classes or within the class
private:
    int x;
    int y;
public:
    Point(); //default constructor
    // this is a parametrized constructor
    Point(int x,int y);
    //getters
    int getx(){ return x; };
    int gety(){ return y; };

    //setter
    void setx(int x){this->x = x;};
    void sety(int y){this->y = y;};

    void print();
};

// now I want to define my default constructor
Point::Point(){
    x = 0;
    y = 0;
}

//parameterized constructor definition
Point::Point(int x, int y){
    this -> x = x;
    this -> y = y;
}

//Create a function that compares 2 points and
// return True if they are the same
// operator overloading for ==
bool operator==(Point p1, Point p2){
    if (p1.getx() == p2.getx() && p1.gety() == p2.gety()){
        return true;
    }
    else {
        return false;
    }
}
void Point::print(){
    cout << "X = " << x << " Y = " << y << endl;
}

int main(){
    Point p1;
    p1.setx(3); // now x should be equal to 3
    p1.sety(5); // now y should be equal to 5
    p1.print();
    Point p2(8, 9);
    p2.print();
    p1.setx(100);
    p1.sety(9);
    p1.print();

    if (p1 == p2){
        cout<<"They are equal"<< endl;
    }
    else {
        cout<<"They are not equal"<< endl;
    }
    return 0;
}