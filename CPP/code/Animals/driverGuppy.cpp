#include "Guppy.h"
#include <iostream>

using namespace std;

int main(){
    Guppy G(10, 20);
    LinkedList<FishFood> listFood;

    FishFood F0(10, 10);
    FishFood F1(20, 20);
    FishFood F2(30, 30);

    listFood.add(F0);
    listFood.add(F1);
    listFood.add(F2);

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

    cout << "Coordinate X Guppy = " << x << endl;
    cout << "Coordinate Y Guppy = " << y << endl;
    cout << "Speed Guppy        = " << speed << endl;
    cout << "" << endl;
    cout << "Test getLookAt() method" << endl;
    cout << "Guppy Direction    = " << looks << endl;
    

    G.setLookAt(1);
    look = G.getLookAt();
    
    if (look == 0){
        looks = "Looking Left";
    } else {
        looks = "Looking Right";
    }

    cout << "Test setLookAt() method" << endl;
    cout << "Guppy Direction    = " << looks << endl;
    cout << "" << endl;

    cout << "Test getLifetime() method" << endl;
    cout << "Guppy Lifetime       = " << lf << endl;

    G.setLifetime(60);
    lf = G.getLifetime();
    cout << "Test setLifetime() method" << endl;
    cout << "Guppy Lifetime       = " << lf << endl;
    cout << "" << endl;

    cout << "Test getStillFull() method" << endl;
    cout << "Guppy StillFull      = " << lf << endl;

    G.setStillFull(40);
    lf = G.getStillFull();
    cout << "Test setStillFull() method" << endl;
    cout << "Guppy StillFull      = " << lf << endl;

    cout << "Test getCountingDead() method" << endl;
    cout << "Guppy CountingDead   = " << countDead << endl;

    G.setCountingDead(2000);
    countDead = G.getCountingDead();
    cout << "Test setCountingDead() method" << endl;
    cout << "Guppy CountingDead   = " << countDead << endl;

    cout << "Test notHungry() method" << endl;
    string prompt;
    if (notHungry){
        prompt = "TRUE";
    }
    cout << "Guppy is not hungry "<< prompt << endl;

    cout << "Test getPhase() method -> Phase pertama :"<< G.getPhase() << endl;
    G.setPhase(2);
    cout << "Test setPhase() method -> Phase set 2 :"<< G.getPhase() << endl;
    G.nextPhase();
    cout << "Test nextPhase() method -> Phase next Phase :"<< G.getPhase() << endl;

    cout << "Link fish food size = " << listFood.size() << endl;
    G.eat(listFood);
    cout << "Link fish food setelah satu food dimakan            = " << listFood.size() << endl;
    int near = G.getNearestFood(listFood);
    double a, b;
    a = listFood.get(near).getX();
    b = listFood.get(near).getY();
    cout << "Fish food terdekat dari dalam list berada di index  = " << near << endl;
    cout << "Dengan posisi guppy    = (" << G.getX() << "," << G.getY() << ")" << endl;
    cout << "Dengan posisi makanan  = (" << a << "," << b << ")" << endl;

    Coin c1 = G.makeCoin(G.getPhase());
    cout <<"Nilai Coin : " << c1.getValue() <<endl;

    cout << "Total eaten food : " << G.getTotalEatenFood() << endl;

    LinkedList<Coin> listCoin;
    cout << "Synchronize : " << G.synchronize(listCoin) << " Jika 2 maka tahap kenyang" << endl;  


    return 0;
}