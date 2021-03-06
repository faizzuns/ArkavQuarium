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

    bool run = true;

    while (run){
      clear_screen();
      draw_image("background.jpg", midX, midY);
      draw_image("draw/button_start.png", midX, midY - 30);
      draw_image("draw/button_load.png", midX, midY + 30);

      mouseX = -1;
      mouseY = -1;
      handle_input(&mouseX,&mouseY);

      if (mouseX != -1 && mouseY != -1){
        //start
        cout<<mouseX<<" "<<mouseY<<endl;
        if (mouseX > 278 && mouseX < 360 && mouseY > 193 && mouseY < 225){
          load = false;
          run = false;
        }else if (mouseX > 278 && mouseX < 360 && mouseY > 253 && mouseY < 285){
          load = true;
          run = false;
        }
      }

      update_screen();

      if (quit_pressed()){ run = false;}
    }


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
    bool selesai = false;

    double prevtime = time_since_start();

    while (running || !selesai) {

        mouseX = -1;
        mouseY = -1;
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input(&mouseX,&mouseY);
        if (quit_pressed()) {
            running = false;
            selesai = true;
        }

        if (running){
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

          int dapat = snail.eat(listCoin);
          duit += dapat;
        }

        //Mouse Event
        if (mouseX != -1 && mouseY != -1){
          cout<<mouseX<<" "<<mouseY<<endl;
          int i = 0;
          while(i < listCoin.size()){
            if (listCoin.get(i).beetweenX(mouseX, 20) && listCoin.get(i).beetweenY(mouseY, 20)){
              break;
            }
            i++;
          }
          if (!running) {
            selesai = true;
          }else if (i != listCoin.size()){
            duit += listCoin.get(i).getValue();
            listCoin.remove(i);
          }else if (mouseX > 54 - 30 && mouseX < 54 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
            saveFile(duit, telur, listGuppy, listPiranha, listFishFood, listCoin, snail);
            running = false;
            selesai = true;
            break;
          }else if (mouseX > 482 - 30 && mouseX < 482 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
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
          }else if (mouseX > 395 - 30 && mouseX < 395 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
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
          }else if (mouseX > 575 - 30 && mouseX < 575 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
            if (duit >= BASE_EGG_PRICE * (telur + 1)){
              telur++;
              duit -= BASE_EGG_PRICE * telur;
            }
          }else if (mouseY > 80 && mouseY < 400){
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

        draw_image("draw/bar.png", SCREEN_WIDTH / 2 ,83 /2);
        draw_image("draw/guppy0kanan.png",482, 32);
        draw_text("Rp. " + std::to_string(GUPPY_PRICE),12, 471, 59, 255, 255, 255);
        draw_image("draw/Carnivorekanankecill.png",395,32);
        draw_text("Rp. " + std::to_string(PIRANHA_PRICE),12, 377, 59, 255, 255, 255);
        draw_image("draw/Diamond.png",302,32);
        draw_text("Rp. " + std::to_string(duit),10, 282, 61, 255, 255, 255);
        draw_text("SAVE",20, 33, 18, 255, 255, 255);
        // draw_image("draw/button_save.png",590, 30);
        // draw_image("draw/button_buy-guppy.png", 460, 30);
        // draw_image("draw/button_buy-piranha.png", 300, 30);
        // //draw_image("draw/button_buy-egg.png", 150, 40);
        if (telur < 3){
          string telurImg = "draw/State" + std::to_string(telur + 1) + ".png";
          draw_image(telurImg, 575, 32);
          draw_text("Rp. " + std::to_string(BASE_EGG_PRICE * (telur + 1)),12, 559, 59, 255, 255, 255);
        }
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        // draw_image("aim.png", cx, cy);

        //check for win/lose
        if (telur == 3){
          //win
          running = false;
          draw_text("WIN",50, SCREEN_WIDTH / 2 - 35, SCREEN_HEIGHT / 2 - 35, 0, 0, 0);
        }else{
          if (listCoin.size() == 0 && listGuppy.size() == 0 && listPiranha.size() == 0 && duit < GUPPY_PRICE){
            running = false;
            draw_text("LOSE",50, SCREEN_WIDTH / 2 - 35, SCREEN_HEIGHT / 2 - 35, 0, 0, 0);
          }
        }

        update_screen();
    }

    close();

    return 0;
}
