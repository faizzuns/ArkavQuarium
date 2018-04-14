package model.Animals;

import model.Coin;
import model.LinkedList;

public class Snail extends Animals{

    public Snail(double x, double y) {
        super(x, y, SNAIL_SPEED);
    }

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
            return 0;
        }
    }
}
