#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>

#include "code/Animals/Animals.h"
// #include "code/Animals/Fish.h"
// #include "code/Animals/Guppy.h"
// #include "code/Animals/Piranha.h"
#include "code/Animals/Snail.h"
// #include "code/Aquarium/Aquarium.h"
// #include "code/Aquarium/mainMenu.h"
// #include "code/Aquarium/MenuBar.h"
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
    LinkedList<FishFood> list;
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
        while (i < list.size()){
          list.getRef(i)->moveGeneral(list.get(i).getX(), 400);

          if (list.get(i).getY() > 400){
            list.remove(i);
          }else i++;
        }

        i = 0;
        while (i < listCoin.size()){
          if (!listCoin.get(i).beetweenY(400, 2)){
            listCoin.getRef(i)->moveGeneral(listCoin.get(i).getX(), 400);
          }
          i++;
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
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            case SDLK_a:
                if (duit - 2 >= 0){
                  duit -= 2;
                  FishFood ff(cx, 20);
                  list.add(ff);
                }
                break;
              case SDLK_s:
              cout<<"1"<<endl;
                Coin cc(cx, 20, 10);
                cout<<"2"<<endl;
                listCoin.add(cc);
                cout<<"3"<<endl;
                break;
            }
        }

        //Mouse Event
        if (mouseX != -1 && mouseY != -1){
          if (mouseY > 110){
            FishFood ff(mouseX, mouseY);
            list.add(ff);
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
        for (int i = 0; i < list.size(); i++){
          draw_image("burger.png", list.get(i).getX(),list.get(i).getY());
        }

        for (int i = 0; i < listCoin.size(); i++){
          draw_image("draw/Diamond.png", listCoin.get(i).getX(),listCoin.get(i).getY());
        }

        string snailImg = snail.getLookAt() == LOOKING_RIGHT? "draw/siputkanan.png" : "draw/siputkiri.png";
        draw_image(snailImg, snail.getX(), snail.getY());

        std::string jmlCoin = "Jumlah Coin : " + patch::to_string(duit);
        draw_text(jmlCoin, 18, 10, 10, 0, 0, 0);
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        draw_image("aim.png", cx, cy);
        update_screen();
    }

    close();

    return 0;
}
