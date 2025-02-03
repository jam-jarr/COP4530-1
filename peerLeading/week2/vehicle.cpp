#include <iostream>
#include <string>
using namespace std;

class Vehicle{
    //1. Constructor 2. print 3 set owner 4 change owner
public:
    Vehicle();
    Vehicle(string owner, int year_old);
    // virtual means the function can be overwritten
    virtual void print_info();
    void setOwner(string owr){
        this->owner = owr;
    };
// Can be accessed within the class and classes that inherit from the class
protected:
    string owner;
    int year_old;
};

class Car : public Vehicle{
public:
    Car();
    Car(string owr, int y_old, string mdl, double m_driven);
    virtual void print_info();

protected:
    string model;
    double miles_driven;
};
// Constructors
// They are keep outside the classes because
// you can only declare function in classes
// Make that way so that the code is more maintainable
Vehicle :: Vehicle(): owner(""), year_old(-1){};

Vehicle :: Vehicle(string owr, int y_old): owner(owr), year_old(y_old){};

Car :: Car() : Vehicle("", -1), model(""), miles_driven(-1){};

Car :: Car(string owr, int y_old, string mdl, double m_driven)
: Vehicle(owr, y_old), model(mdl), miles_driven(m_driven){};

void Vehicle :: print_info(){
    cout << "This is a vehicle with owner named " << owner << " and it has "
    << year_old << " years on it" << endl;
}
void Car :: print_info(){
    cout << "This is a car with owner named " << owner << " and it has "
    << year_old << " years on it and it is a car model of " << model
    << " and it has been driven for " << miles_driven << "." << endl;
}

int main(){
    Vehicle v1("Bob", 3);
    v1.print_info();
    Car c1("Mike", 7, "audi", 1000000);
    c1.print_info();

    // object pointers
    // instead of malloc we have new in C++
    Vehicle *v2 = new Vehicle;
    v2->print_info();

    v2->setOwner("Frank");
    v2->print_info();

    Car *c2 = new Car;
    c2->print_info();
    c2->setOwner("Mark");
    c2->print_info();

    delete c2;
    return 0;
}
