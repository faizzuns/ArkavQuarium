#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>

#include "code/Animals/Animals.h"
#include "code/Animals/Fish.h"
#include "code/Animals/Guppy.h"
#include "code/Animals/Piranha.h"
#include "code/Animals/Snail.h"
#include "code/Coin/Coin.h"
#include "code/Coordinate/Coordinate.h"
#include "code/FishFood/FishFood.h"
#include "code/LinkedList/LinkedList.h"
#include "code/Move/Move.h"

const double speed = 75; // pixels per second

#define BASE_EGG_PRICE 30

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

void saveFile(int duit, int telur, LinkedList<Guppy> &listGuppy, LinkedList<Piranha> &listPiranha, LinkedList<FishFood> &listFishFood, LinkedList<Coin> &listCoin, Snail &snail){
  ofstream myfile;

  //duit
  myfile.open("duit.txt");
  if (!myfile.fail()){
    myfile<<duit<<endl;
    myfile.close();
  }

  myfile.open("telur.txt");
  if (!myfile.fail()){
    myfile<<telur<<endl;
    myfile.close();
  }

  myfile.open("guppy.txt");
  if (!myfile.fail()){
    for (int i = 0; i < listGuppy.size(); i++){
      Guppy g = listGuppy.get(i);
      myfile<<g.getX()<<" "<<g.getY()<<" "<<g.getSpeed()<<" "<<g.getLookAt()<<" "<<g.getLifetime()<<" "<<g.getStillFull()<<" "<<g.getCountingDead()<<" "<<g.getRanda().getX()<<" "<<g.getRanda().getY()<<" "<<g.getPhase()<<" "<<g.getTotalEatenFood()<<" "<<g.getCoinValue()<<endl;
    }
    myfile.close();
  }

  myfile.open("piranha.txt");
  if (!myfile.fail()){
    for (int i = 0; i < listPiranha.size(); i++){
      Piranha g = listPiranha.get(i);
      myfile<<g.getX()<<" "<<g.getY()<<" "<<g.getSpeed()<<" "<<g.getLookAt()<<" "<<g.getLifetime()<<" "<<g.getStillFull()<<" "<<g.getCountingDead()<<" "<<g.getRanda().getX()<<" "<<g.getRanda().getY()<<endl;
    }
    myfile.close();
  }

  myfile.open("snail.txt");
  if (!myfile.fail()){
    Snail g = snail;
    myfile<<g.getX()<<" "<<g.getY()<<" "<<g.getSpeed()<<" "<<g.getLookAt()<<endl;
    myfile.close();
  }

  myfile.open("fishFood.txt");
  if (!myfile.fail()){
    for (int i = 0; i < listFishFood.size(); i++){
      FishFood g = listFishFood.get(i);
      myfile<<g.getX()<<" "<<g.getY()<<" "<<g.getSpeed()<<endl;
    }
    myfile.close();
  }

  myfile.open("coin.txt");
  if (!myfile.fail()){
    for (int i = 0; i < listCoin.size(); i++){
      Coin g = listCoin.get(i);
      myfile<<g.getX()<<" "<<g.getY()<<" "<<g.getSpeed()<<" "<<g.getValue()<<endl;
    }
    myfile.close();
  }

}

int main( int argc, char* args[] )
{
    int mouseX, mouseY;
    init();
    //Aquarium aquarium;
    LinkedList<Guppy> listGuppy;
    LinkedList<Piranha> listPiranha;
    LinkedList<FishFood> listFishFood;
    LinkedList<Coin> listCoin;
    Snail snail(SCREEN_WIDTH / 2, 400);
    int telur = 0;
    int duit = 10;

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;
    double midX = cx;
    double midY = cy;

    bool load = false;

    if (load){
      //stream untuk membaca file
       ifstream myfile;
       //membuka file yang telah ada
       myfile.open("duit.txt");
       if (!myfile.fail()){
         char data[100];
         while (myfile >> data){
           duit = stoi(data);
         }
         myfile.close();
       }

       myfile.open("telur.txt");
       if (!myfile.fail()){
         char data[100];
         while (myfile >> data){
           telur = stoi(data);
         }
         myfile.close();
       }

       myfile.open("guppy.txt");
       if (!myfile.fail()){
         char data[100];
         while (myfile >> data){
           double x =double(stoi(data));
           myfile >> data;
           double y = double(stoi(data));
           myfile >> data;
           double speed = GUPPY_SPEED;
           myfile >> data;
           int lookAt = stoi(data);
           myfile >> data;
           int lifetime = stoi(data);
           myfile >> data;
           int stillFull = stoi(data);
           myfile >> data;
           int countingDead = stoi(data);
           myfile >> data;
           double randaX = double(stoi(data));
           myfile >> data;
           double randaY = double(stoi(data));
           myfile >> data;
           int phase = stoi(data);
           myfile >> data;
           int totalEatenFood = stoi(data);
           myfile >> data;
           int coinValue = stoi(data);

           Guppy g(x,y);
           g.setLookAt(lookAt);
           g.setLifetime(lifetime);
           g.setStillFull(stillFull);
           g.setCountingDead(countingDead);
           g.setRandaX(randaX);
           g.setRandaY(randaY);
           g.setPhase(phase);
           g.setTotalEatenFood(totalEatenFood);
           g.setCoinValue(coinValue);

           listGuppy.add(g);
         }
         myfile.close();
       }

       myfile.open("piranha.txt");
       if (!myfile.fail()){
         char data[100];
         while (myfile >> data){
           double x =double(stoi(data));
           myfile >> data;
           double y = double(stoi(data));
           myfile >> data;
           double speed = GUPPY_SPEED;
           myfile >> data;
           int lookAt = stoi(data);
           myfile >> data;
           int lifetime = stoi(data);
           myfile >> data;
           int stillFull = stoi(data);
           myfile >> data;
           int countingDead = stoi(data);
           myfile >> data;
           double randaX = double(stoi(data));
           myfile >> data;
           double randaY = double(stoi(data));

           Piranha g(x,y);
           g.setLookAt(lookAt);
           g.setLifetime(lifetime);
           g.setStillFull(stillFull);
           g.setCountingDead(countingDead);
           g.setRandaX(randaX);
           g.setRandaY(randaY);

           listPiranha.add(g);
         }
         myfile.close();
       }

       myfile.open("fishFood.txt");
       if (!myfile.fail()){
         char data[100];
         while (myfile >> data){
           double x =double(stoi(data));
           myfile >> data;
           double y = double(stoi(data));
           myfile >> data;
           double speed = GUPPY_SPEED;

           FishFood g(x,y);

           listFishFood.add(g);
         }
         myfile.close();
       }

    myfile.open("coin.txt");
    if (!myfile.fail()){
      char data[100];
      while (myfile >> data){
        double x =double(stoi(data));
        myfile >> data;
        double y = double(stoi(data));
        myfile >> data;
        double speed = GUPPY_SPEED;
        myfile >> data;
        int value = stoi(data);

        Coin g(x,y,value);

        listCoin.add(g);
      }
      myfile.close();
    }

    myfile.open("snail.txt");
    if (!myfile.fail()){
      char data[100];
      while (myfile >> data){
        double x =double(stoi(data));
        myfile >> data;
        double y = double(stoi(data));
        myfile >> data;
        double speed = GUPPY_SPEED;
        myfile >> data;
        int lookAt = stoi(data);

        snail.setLookAt(lookAt);
      }
      myfile.close();
    }

   }else{
     Guppy g(midX, midY);
     listGuppy.add(g);
   }

    bool running = true;

    double prevtime = time_since_start();

    while (running) {

        mouseX = -1;
        mouseY = -1;
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input(&mouseX,&mouseY);
        if (quit_pressed()) {
            running = false;
        }

        int i = 0;
        while (i < listFishFood.size()){
          listFishFood.getRef(i)->moveGeneral(listFishFood.get(i).getX(), 400);

          if (listFishFood.get(i).getY() > 400){
            listFishFood.remove(i);
          }else i++;
        }

        i = 0;
        while (i < listCoin.size()){
          if (!listCoin.get(i).beetweenY(400, 2)){
            listCoin.getRef(i)->moveGeneral(listCoin.get(i).getX(), 400);
          }
          i++;
        }

        i = 0;
        while (i < listGuppy.size()){
          int j = listGuppy.getRef(i)->synchronize(listCoin);
          if (j == 0){
            listGuppy.remove(i);
          }else {
            if (j == 1){
              //lapar
              listGuppy.getRef(i)->eat(listFishFood);
            }else {
              // ga lapar
              listGuppy.getRef(i)->randomMove();
            }
            i++;
          }
        }

        i = 0;
        while (i < listPiranha.size()){
          int j = listPiranha.getRef(i)->synchronize(listCoin);
          if (j == 0){
            listPiranha.remove(i);
          }else{
            if (j == 1){
              //laper
              listPiranha.getRef(i)->eat(listGuppy, listCoin);
            }else{
              //ga laper
              listPiranha.getRef(i)->randomMove();
            }
            i++;
          }
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
            }
        }

        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
              cy = SCREEN_HEIGHT / 2;
              cx = SCREEN_WIDTH / 2;
              break;
            //x untuk keluar
            case SDLK_x:
              running = false;
              break;
            case SDLK_a:
              //guppy
              if (duit >= GUPPY_PRICE){
                duit -= GUPPY_PRICE;
                int xx = rand() % 10;
                double aa = 0;double bb = 0;
                for (int i = 0; i < xx; i++){
                  aa =double(rand() % 300) + 100;
                  bb =double(rand() % 200) + 100;
                }
                if (aa < 20 && bb < 20){
                  aa = midX;
                  bb = midY;
                }
                Guppy g(aa, bb);
                listGuppy.add(g);
              }
              break;
            case SDLK_s:
            //piranha
              if (duit >= PIRANHA_PRICE){
                duit -= PIRANHA_PRICE;
                int xx = rand() % 10;
                double aa = 0;double bb = 0;
                for (int i = 0; i < xx; i++){
                  aa =double(rand() % 300) + 100;
                  bb =double(rand() % 200) + 100;
                }
                if (aa < 20 && bb < 20){
                  aa = midX;
                  bb = midY;
                }
                Piranha p(aa, bb);
                listPiranha.add(p);
              }
              break;
            case SDLK_t:
              if (duit >= BASE_EGG_PRICE * (telur + 1)){
                telur++;
                duit -= BASE_EGG_PRICE * telur;
              }
              break;
            case SDLK_q:
              //save;
              saveFile(duit, telur, listGuppy, listPiranha, listFishFood, listCoin, snail);
              running = false;
              break;
            }
        }

        if (!running) break;

        //Mouse Event
        if (mouseX != -1 && mouseY != -1){
          int i = 0;
          while(i < listCoin.size()){
            if (listCoin.get(i).beetweenX(mouseX, 20) && listCoin.get(i).beetweenY(mouseY, 20)){
              break;
            }
            i++;
          }
          if (i != listCoin.size()){
            duit += listCoin.get(i).getValue();
            listCoin.remove(i);
          }else if (mouseY > 20 && mouseY < 400){
            if (duit - 2 >= 0){
              duit -= 2;
              FishFood ff(mouseX, mouseY);
              listFishFood.add(ff);
            }
          }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }

        //snail.eat(listCoin);
        int dapat = snail.eat(listCoin);
        duit += dapat;
        // Gambar ikan di posisi yang tepat.
        //cx += speed * sec_since_last;
        clear_screen();
        draw_image("background.jpg", midX, midY);

        //fish food
        for (int i = 0; i < listFishFood.size(); i++){
          draw_image("burger.png", listFishFood.get(i).getX(),listFishFood.get(i).getY());
        }

        //coin
        for (int i = 0; i < listCoin.size(); i++){
          draw_image("draw/Diamond.png", listCoin.get(i).getX(),listCoin.get(i).getY());
        }

        //snail
        string snailImg = snail.getLookAt() == LOOKING_RIGHT? "draw/siputkanan.png" : "draw/siputkiri.png";
        draw_image(snailImg, snail.getX(), snail.getY());

        //Guppy
        //tahapan, ngeliat kemana
        for (int i = 0; i <listGuppy.size(); i++){
          string tahapImg = std::to_string(listGuppy.get(i).getPhase());
          string lookImg = listGuppy.get(i).getLookAt() == LOOKING_RIGHT ? "kanan" : "kiri";
          string lapar = listGuppy.get(i).notHungry() ? "" : "lapar";

          draw_image("draw/guppy" + tahapImg + lookImg + lapar + ".png", listGuppy.get(i).getX(), listGuppy.get(i).getY());
        }

        //Piranha
        //lookAt
        for (int i = 0; i < listPiranha.size(); i++){
          string lapar = listPiranha.get(i).notHungry() ? "" : "";
          string img = listPiranha.get(i).getLookAt() == LOOKING_RIGHT ? "draw/Carnivorekanan" + lapar + ".png" : "draw/Carnivore" + lapar + ".png";
          draw_image(img, listPiranha.get(i).getX(), listPiranha.get(i).getY());
        }

        std::string jmlCoin = "Jumlah Coin : " + std::to_string(duit);
        draw_text(jmlCoin, 18, 10, 10, 0, 0, 0);
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        // draw_image("aim.png", cx, cy);

        //check for win/lose
        if (telur == 3){
          //win
          running = false;
          draw_text("WIN", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10, 0, 0, 0);
        }else{
          if (listCoin.size() == 0 && listGuppy.size() == 0 && listPiranha.size() == 0 && duit < GUPPY_PRICE){
            running = false;
            draw_text("LOSE", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 10, 0, 0, 0);
          }
        }
        update_screen();
    }

    close();

    return 0;
}
