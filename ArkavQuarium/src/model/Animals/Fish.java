package model.Animals;

import model.Coordinate;

import java.util.Random;
/**
 * kelas Fish adalah kelas yang diturunkan dari kelas Animals dan meurunkan sifat sifat dari Animals
 */
public class Fish extends Animals{

    public static final int STATE_FULL = 700;
    public static final int STATE_DEAD = 1000;
    public static final int GUPPY_PRICE = 5;
    public static final int PIRANHA_PRICE = 20;

    private int lifetime;
    private int stillFull;
    private int countingDead;
    private Coordinate randa;

    /**
     * Constructor ini akan digunakan untuk membangun objek dengan posisi x dan y
     * @param x adalah posisi objek pada sumbu horizontal
     * @param y adalah posisi objek pada sumbu vertical
     * @param speed adalah kecepatan yang dimiliki fish
     */
    public Fish(double x, double y, double speed) {
        super(x, y, speed);
        setLifetime(0);
        setStillFull(STATE_FULL);
        setCountingDead(STATE_DEAD);
        setLookAt(LOOKING_RIGHT);
        randa = new Coordinate(x, y);
    }

    /**
     * mengembalikkan nilai lifetime
     * @return mengembalikkan nilai lifetime
     */
    public int getLifetime() {
        return lifetime;
    }

    /**
     * memasang nilai lifetime
     * @param lifetime nilai lifetime
     */
    public void setLifetime(int lifetime) {
        this.lifetime = lifetime;
    }

    /**
     * mengembalikkan nilai apakah kenyang atau tidak
     * @return mengembalikkan nilai apakah kenyang atau tidak
     */
    public int getStillFull() {
        return stillFull;
    }

    /**
     * memasang nilai stillFull
     * @param stillFull nilai stillFull
     */
    public void setStillFull(int stillFull) {
        this.stillFull = stillFull;
    }
    /**
     * mengembalikkan nilai waktu yang dibutuhkan untuk objek menjadi mati
     * @return mengembalikkan nilai waktu yang dibutuhkan untuk objek menjadi mati
     */
    public int getCountingDead() {
        return countingDead;
    }

    /**
     * memasang nilai countingDead
     * @param countingDead nilai countingDead
     */
    public void setCountingDead(int countingDead) {
        this.countingDead = countingDead;
    }
    /**
     * mengembalikkan nilai random dalam tipe coordinate
     * @return mengembalikkan nilai random dalam tipe coordinate
     */
    public Coordinate getRanda() {
        return randa;
    }

    /**
     * memasang nilai coordinate
     * @param randa nilai coordinate
     */
    public void setRanda(Coordinate randa) {
        this.randa = randa;
    }

    /**
     * Method ini dilakukan untuk mencari nilai random yang akan digunakan untuk mendapatkan randdom coodinate
     * Kemudian Coordinate tersebut digunakan untuk melakukan gerakan ke arah random saat objek yang bergerak
     * sedang tidak kelaparan
     */
    public void randomMove(){
        double aa,bb;
        Random r = new Random();
        aa = 0 + (620) * r.nextDouble();
        bb = 80 + (360 - 80) * r.nextDouble();

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

    /**
     * Method ini dugunakan untuk menentukan apakah seekor Fish sedang hungry atau tidak
     * @return mengembalikan nilai 1 jika lapar dan 0 jika tidak lapar
     */
    public boolean notHungry(){
        return stillFull != 0;
    }

}
