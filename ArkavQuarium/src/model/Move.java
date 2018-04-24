package model;

import static java.lang.Math.atan2;
import static java.lang.Math.cos;
import static java.lang.StrictMath.sin;

/**
 * Kelas Move merupakan kelas yang mengontrol
 * speed dari sebuah entititas dan mengontrol gerak dari entitas.
 * memiliki atribut speed
 */
public class Move extends Coordinate{

    protected static double GUPPY_SPEED = 0.5;
    protected static double PIRANHA_SPEED = 0.7;
    protected static double SNAIL_SPEED = 0.35;
    static double COIN_SPEED = 0.25;
    static double FISH_FOOD_SPEED = 0.2;

    private double speed;

    /**
     * Constructor berparameter
     * dengan parameter,
     * speed yang akan mengassign ke atribut kelas speed,
     * x yang akan mengassign ke atribut kelas x,
     * y yang akan mengassign ke atribut kelas y.
     * akan memanggil Constructor Coordinate dengan parameter x dan y
     *
     * @param x koordinat x
     * @param y korrdinat y
     * @param speed speed entitas
     */
    public Move(double x, double y, double speed) {
        super(x, y);
        this.speed = speed;
    }

    /**
     * Getter
     *
     * @return nilai dari speed
     */
    public double getSpeed() {
        return speed;
    }

    /**
     * akan mengubah nilai atribut speed dengan parameter speed
     *
     * @param speed speed
     */
    public void setSpeed(double speed) {
        this.speed = speed;
    }

    /**
     * Method ini berfungsi untuk mengubah koordinat x entitas
     * akan bergerak sebesar speed ke kanan
     */
    public void moveRight(){
        setX(getX() + speed);
    }

    /**
     * Method ini berfungsi untuk mengubah doordinat y entitas
     * akan bergerak sebesar speed ke kiri
     */
    public void moveLeft(){
        setX(getX() - speed);
    }

    /**
     * Method ini berfungsi untuk menggerakan entitas ke arah tujuan
     *
     * @param x2 koordinat x Coordinate tujuan
     * @param y2 koordinat y Coordinate tujuan
     */
    public void moveGeneral(double x2, double y2){
        double a = atan2(y2-getY(), x2-getX());
        setX(getX() + (getSpeed() * cos(a)));
        setY(getY() + (getSpeed() * sin(a)));
    }

}
