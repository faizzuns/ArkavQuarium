#include <iostream>
#include "Animals.h"
#include <string>

using namespace std;

int main (){
    Animals A(50, 100, 5);

    double x, y, speed;
    int look;

    x = A.getX();
    y = A.getY();
    speed = A.getSpeed();
    look = A.getLookAt();

    string looks = "";
    if (look == 0){
        looks = "Looking Left";
    } else {
        looks = "Looking Right";
    }

    cout << "Coordinate X Animals = " << x << endl;
    cout << "Coordinate Y Animals = " << y << endl;
    cout << "Speed Animals        = " << speed << endl;
    cout << "" << endl;
    cout << "Test getLookAt() method" << endl;
    cout << "Animals Direction    = " << looks << endl;
    cout << "" << endl;

    A.setLookAt(1);
    look = A.getLookAt();
    
    if (look == 0){
        looks = "Looking Left";
    } else {
        looks = "Looking Right";
    }

    cout << "Test setLookAt() method" << endl;
    cout << "Animals Direction    = " << looks << endl;
    cout << "" << endl;
    

    return 0;
}