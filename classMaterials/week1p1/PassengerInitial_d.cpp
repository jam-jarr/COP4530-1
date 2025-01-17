// The keyword indicates that the member function
// isFrequentFlyer is an accessor (only read class data)
#include <iostream>
#include<string>
enum MealType { NO_PREF, REGULAR, LOW_FAT, VEGETARIAN };
class Passenger {
public:
    Passenger(); // default constructor
    Passenger(const std::string& nm, MealType mp, const int& ffn = 0);
    Passenger(const Passenger& pass); // copy constructor
    bool isFrequentFlyer() const;
    void makeFrequentFlyer(const int& newFreqFlyerNo);
    void print() const;
private:
    std::string name;
    MealType mealPref;
    bool isFreqFlyer;
    int freqFlyerNo;
};
bool Passenger::isFrequentFlyer() const {
    return isFreqFlyer;
}
void Passenger::makeFrequentFlyer(const int&
newFreqFlyerNo) {
    isFreqFlyer = true;
    freqFlyerNo = newFreqFlyerNo;
}
void Passenger::print() const {
    std::cout << "-----------------------------------------"<< std::endl;
    std::cout << "Passenger name: " << this -> name << std::endl;
    std::cout << "Meal preference: " << this -> mealPref << std::endl;
    std::cout << "Frequent flyer?: " << this  -> isFreqFlyer << std::endl;
    std::cout << "Frequent flyer number: " << this -> freqFlyerNo << std::endl;
}
Passenger::Passenger() {
    name = "--NO NAME--";
    mealPref = NO_PREF; isFreqFlyer = false; freqFlyerNo = 0;
}
Passenger::Passenger(const std::string& nm, MealType mp, const int& ffn) {
    name = nm; mealPref = mp;
    isFreqFlyer = (ffn != 0); // true only if ffn givenfreqFlyerNo = ffn;
}
Passenger::Passenger(const Passenger& pass) {
    name = pass.name; mealPref = pass.mealPref;
    isFreqFlyer = pass.isFreqFlyer; freqFlyerNo = pass.freqFlyerNo;
}
int main()
{
// default constructor
    Passenger p1;
// 2nd constructor
    Passenger p2("John Smith", VEGETARIAN, 293145);
// 2nd constructor
    Passenger p3("Pocahontas", REGULAR);
// Copy constructor
    Passenger p4(p3);
// Copy constructor
    Passenger p5 = p2;
// default constructor
    Passenger* pp1 = new Passenger;
// 2nd constructor
    Passenger* pp2 = new Passenger("JoeBlow", NO_PREF);
// default constructor
    Passenger pa[20];
    p1.print();
    p2.print();
    p3.print();
    p4.print();
    p5.print();
    return 0;
}