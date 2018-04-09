#include "oop.hpp"
#include <iostream>
#include <math.h>
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

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
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

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    int duit = 10;

    double midX = cx;
    double midY = cy;
    Guppy g(midX, midY);
    listGuppy.add(g);

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
            cout<<"huhui "<<i<<endl;
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
                Guppy g(midX, midY);
                listGuppy.add(g);
              }
              break;
            case SDLK_s:
            //piranha
              if (duit >= PIRANHA_PRICE){
                duit -= PIRANHA_PRICE;
                Piranha p(midX, midY);
                listPiranha.add(p);
              }
              break;
            }
        }

        //Mouse Event
        if (mouseX != -1 && mouseY != -1){
          if (mouseY > 20 && mouseY < 400){
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
          string lapar = listPiranha.get(i).notHungry() ? "" : "lapar";
          string img = listPiranha.get(i).getLookAt() == LOOKING_RIGHT ? "draw/Carnivorekanan" + lapar + ".png" : "draw/Carnivore" + lapar + ".png";
          draw_image(img, listPiranha.get(i).getX(), listPiranha.get(i).getY());
        }

        std::string jmlCoin = "Jumlah Coin : " + std::to_string(duit);
        draw_text(jmlCoin, 18, 10, 10, 0, 0, 0);
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        draw_image("aim.png", cx, cy);
        update_screen();
    }

    close();

    return 0;
}
