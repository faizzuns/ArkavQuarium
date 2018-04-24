package model.Animals;

import model.Coin;
import model.LinkedList;

/**
 * Kelas Snail merupakan kelas yang inheritance dari kelas Animal
 */
public class Snail extends Animals{
    private int DEFAULT_VALUE = 0;

    /**
     * Constructor berparatemer
     * akan memanggil constructor animals dengan
     * parameter x dan y
     *
     * @param x koordinat x
     * @param y koordinat y
     */
    public Snail(double x, double y) {
        super(x, y, SNAIL_SPEED);
    }

    /**
     *
     * @param listCoin list of coin yang akan di olah didalam
     * @return mengembalikan value coin yang berhasil dimakan,
     * akan mengembalikan DEFAULT_VALUE jika tidak berhasil makan
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
        return DEFAULT_VALUE;
    }

    /**
     * method ini menerima parameter listCoin
     *
     * @param listCoin  listCoin
     * @return mengembalikan indeks coin dari listCoin
     */
    int getNearestCoin(LinkedList<Coin> listCoin) {
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
            return DEFAULT_VALUE;
        }
    }

    /**
     *
     * @return mengembalikan path image untuk snail
     */
    public String getImagePath(){
        if (getLookAt() == LOOKING_RIGHT) return PATH_DRAWABLE + "siputkanan.png";
        else return PATH_DRAWABLE + "siputkiri.png";
    }
}
