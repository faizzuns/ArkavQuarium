#include "Piranha.h"
#include <iostream>

using namespace std;


int main(){
    Piranha G(10, 20);
    LinkedList<Guppy> listGuppy;
    
    LinkedList<Coin> listCoin;
    

    Guppy F0(10, 10);
    Guppy F1(20, 20);
    Guppy F2(30, 30);

    listGuppy.add(F0);
    listGuppy.add(F1);
    listGuppy.add(F2);

    double x, y, speed;
    int look, lf, stFull, countDead;
    bool notHungry;
    Coordinate randa;

    x = G.getX();
    y = G.getY();
    speed = G.getSpeed();
    look = G.getLookAt();
    lf = G.getLifetime();
    stFull =  G.getStillFull();
    countDead = G.getCountingDead();
    notHungry = G.notHungry();

    string looks = "";
    if (look == 0){
        looks = "Looking Left";
    } else {
        looks = "Looking Right";
    }

    cout << "Coordinate X Piranha = " << x << endl;
    cout << "Coordinate Y Piranha = " << y << endl;
    cout << "Speed Piranha        = " << speed << endl;
    cout << "" << endl;
    cout << "Test getLookAt() method" << endl;
    cout << "Piranha Direction    = " << looks << endl;
    

    G.setLookAt(1);
    look = G.getLookAt();
    
    if (look == 0){
        looks = "Looking Left";
    } else {
        looks = "Looking Right";
    }

    cout << "Test setLookAt() method" << endl;
    cout << "Piranha Direction    = " << looks << endl;
    cout << "" << endl;

    cout << "Test getLifetime() method" << endl;
    cout << "Piranha Lifetime       = " << lf << endl;

    G.setLifetime(60);
    lf = G.getLifetime();
    cout << "Test setLifetime() method" << endl;
    cout << "Piranha Lifetime       = " << lf << endl;
    cout << "" << endl;

    cout << "Test getStillFull() method" << endl;
    cout << "Piranha StillFull      = " << lf << endl;

    G.setStillFull(40);
    lf = G.getStillFull();
    cout << "Test setStillFull() method" << endl;
    cout << "Piranha StillFull      = " << lf << endl;

    cout << "Test getCountingDead() method" << endl;
    cout << "Piranha CountingDead   = " << countDead << endl;

    G.setCountingDead(2000);
    countDead = G.getCountingDead();
    cout << "Test setCountingDead() method" << endl;
    cout << "Piranha CountingDead   = " << countDead << endl;

    cout << "Test notHungry() method" << endl;
    string prompt;
    if (notHungry){
        prompt = "TRUE";
    }
    cout << "Piranha is not hungry "<< prompt << endl;

    

    cout << "Link guppy size = " << listGuppy.size() << endl;
    G.eat(listGuppy, listCoin);
    cout << "Link Piranha setelah satu food dimakan            = " << listGuppy.size() << endl;
    int near = G.getNearestGuppy(listGuppy);
    double a, b;
    a = listGuppy.get(near).getX();
    b = listGuppy.get(near).getY();
    cout << "Piranha terdekat dari dalam list berada di index  = " << near << endl;
    cout << "Dengan posisi Piranha    = (" << G.getX() << "," << G.getY() << ")" << endl;
    cout << "Dengan posisi makanan  = (" << a << "," << b << ")" << endl;

    Coin c1 = G.makeCoin(listGuppy.get(near).getPhase());
    cout <<"Nilai Coin : " << c1.getValue() <<endl;


    cout << "Synchronize : " << G.synchronize(listCoin) << " Jika 2 maka tahap kenyang" << endl;  
    return 0;
}

   
    