package model.Animals;

import model.Coin;
import model.Coordinate;
import model.LinkedList;

public class Fish extends Animals{

    public static int STATE_FULL = 700;
    public static int STATE_DEAD = 1000;
    public static int GUPPY_PRICE = 5;
    public static int PIRANHA_PRICE = 20;

    private int lifetime;
    private int stillFull;
    private int countingDead;
    private Coordinate randa;

    public Fish(double x, double y, double speed) {
        super(x, y, speed);
        setLifetime(0);
        setStillFull(STATE_FULL);
        setCountingDead(STATE_DEAD);
        setLookAt(LOOKING_RIGHT);
        randa.setX(x);
        randa.setY(y);
    }

    public int getLifetime() {
        return lifetime;
    }

    public void setLifetime(int lifetime) {
        this.lifetime = lifetime;
    }

    public int getStillFull() {
        return stillFull;
    }

    public void setStillFull(int stillFull) {
        this.stillFull = stillFull;
    }

    public int getCountingDead() {
        return countingDead;
    }

    public void setCountingDead(int countingDead) {
        this.countingDead = countingDead;
    }

    public Coordinate getRanda() {
        return randa;
    }

    public void setRanda(Coordinate randa) {
        this.randa = randa;
    }

    public void randomMove(){
        int xx = (int) (Math.random() % 10);
        double aa = 0;double bb = 0;
        for (int i = 0; i < xx; i++){
            aa = Math.random() % 620;
            bb =Math.random() % 360 + 80;
        }
        if ((beetweenX(randa.getX(), 20) && beetweenY(randa.getY(), 20)) && getX() > 0  && getX() < 640 && getY() > 80 && getY() < 440) {
            randa.setX(aa);
            randa.setY(bb);
        }

        if (randa.getX() < 20 && randa.getY() < 20){
            randa.setX(320);
            randa.setY(240);
        }
        moveGeneral(randa.getX(), randa.getY());

        if (getX() < randa.getX()){
            setLookAt(LOOKING_RIGHT);
        }else setLookAt(LOOKING_LEFT);
    }

    public boolean notHungry(){
        return stillFull != 0;
    }

    public Coin makeCoin(int phase){return null;}

    public int synhronize(LinkedList<Coin> listCoin){return 0;}
}
