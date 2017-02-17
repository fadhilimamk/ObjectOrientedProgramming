#include <iostream>
using namespace std;

class Point {
    // Constructor
    // Set titik mula-mula ke (0, 0)
    public: Point();
    // Getter
    int getAbsis();
    int getOrdinat();
    // Setter
    void setAbsis(int x);
    void setOrdinat(int y);
    void print(); // print absis, kemudian ordinat dengan memanfaatkan Printer
    private: int x, y; // abscissa and ordinate
};

class Printer {
    public: 
    static void print(string str); 
    static void print(int val);
};

Point::Point(){
	this->x = 0;
	this->y = 0;
}

int Point::getAbsis(){
	return this->x;
}
int Point::getOrdinat(){
	return this->y;
}
void Point::setAbsis(int x){
	this->x = x;
}
void Point::setOrdinat(int y){
	this->y = y;
}
void Point::print(){
	Printer mPrinter = Printer();
	mPrinter.print(this->x);
	mPrinter.print(this->y);
}
