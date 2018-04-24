package model.Animals;

import model.Coin;
import model.LinkedList;

/**
 * kelas snail adalah kelas yang diturunkan dari kelas Animals
 * kelas ini akan mengatur seluruh behaviour dari Snail mulai dari eat dan move
 */
public class Snail extends Animals{

    /**
     * Constructor Snail akan membangun objek snail
     * @param x akan mendefinisikan posisi snail pada sumbu x saat pertama kali diciptakan
     * @param y akan mendefinisikan posisi snail pada sumbu y saat pertama kali diciptakan
     */
    public Snail(double x, double y) {
        super(x, y, SNAIL_SPEED);
    }

    /**
     * Method eat adalah method untuk memakan coin yang ada di list coin, dimana method ini
     * akan menghilangkan coin dari list coin dan akan menambahkan uang yang dimiliki aquarium
     * @param listCoin yang berisi coin-coin yang berada di layar
     * @return mengembalikan nilai indeks list coin yang akan dimakan dan mengembalikan 0 jika tidak
     * ada coin di aquarium
     */
    public int eat(LinkedList<Coin> listCoin) {
        if (!listCoin.isEmpty()) {
            int coinIdx = getNearestCoin(listCoin);
            Coin coinTemp = listCoin.get(coinIdx);
            if (beetweenX(coinTemp.getX(),5)){
                if (beetweenY(coinTemp.getY(),10)){
                    int x =  listCoin.get(coinIdx).getValue();
                    listCoin.remove(coinIdx);
                    return x;
                }
            }else{
                if (getX() < coinTemp.getX()){
                    moveRight();
                    setLookAt(LOOKING_RIGHT);
                }else if (getX() > coinTemp.getX()){
                    moveLeft();
                    setLookAt(LOOKING_LEFT);
                }
            }
        }
        return 0;
    }

    /**
     * method ini menerima parameter listCoin lalu mencari coin yang jaraknya paling dekat
     * dengan objek this
     * @param listCoin  listCoin berisi kumpulan coin yang ada di aquarium
     * @return mengembalikan indeks coin dari listCoin
     */
    public int getNearestCoin(LinkedList<Coin> listCoin) {
        if (!listCoin.isEmpty()){
            int n = listCoin.size();
            int coinIdx;
            double distMin, distCurr;

            coinIdx = 0;
            distMin = distance2Point(listCoin.get(coinIdx).getX(), listCoin.get(coinIdx).getY(), getX(), getY());

            for (int i = 1; i < n; i++){
                distCurr = distance2Point(listCoin.get(i).getX(), listCoin.get(i).getY(), getX(), getY());
                if (distCurr <= distMin) {
                    coinIdx = i;
                    distMin = distCurr;
                }
            }
            return coinIdx;
        } else {
            return 0;
        }
    }

    /**
     * method ini digunakan untuk menentukan arah wajah siput
     * jika siput sedang mengarah ke kanan maka akan mengembalikan path gambar siput ke kanan
     * jika siput sedang mengarah ke kiri maka akan mengembalikan path gambar siput ke kiri
     * @return mengembalikan string yang berisi path pada suatu gambar
     */
    public String getImagePath(){
        if (getLookAt() == LOOKING_RIGHT) return PATH_DRAWABLE + "siputkanan.png";
        else return PATH_DRAWABLE + "siputkiri.png";
    }
}
