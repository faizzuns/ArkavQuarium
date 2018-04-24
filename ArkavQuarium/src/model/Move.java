package model;

import static java.lang.Math.atan2;
import static java.lang.Math.cos;
import static java.lang.StrictMath.sin;

public class Move extends Coordinate{

    protected static final double GUPPY_SPEED = 0.5;
    protected static final double PIRANHA_SPEED = 0.7;
    protected static final double SNAIL_SPEED = 0.35;
    static final double COIN_SPEED = 0.25;
    static final double FISH_FOOD_SPEED = 0.2;

    public static int MOVE_TOP = 0;
    public static int MOVE_BOTTOM = 1;
    public static int MOVE_RIGHT = 2;
    public static int MOVE_LEFT = 3;

    private double speed;

    protected Move() {
        speed = 0;
    }

    public Move(double x, double y) {
        super(x, y);
    }

    Move(double speed) {
        this.speed = speed;
    }

    public Move(double x, double y, double speed) {
        super(x, y);
        this.speed = speed;
    }

    public double getSpeed() {
        return speed;
    }

    public void setSpeed(double speed) {
        this.speed = speed;
    }

    public void moveTop(){
        setY(getY() - speed);
    }
    public void moveBottom(){
        setY(getY() + speed);
    }
    public void moveRight(){
        setX(getX() + speed);
    }
    public void moveLeft(){
        setX(getX() - speed);
    }

    public void moveGeneral(double x2, double y2){
        double a = atan2(y2-getY(), x2-getX());
        setX(getX() + (getSpeed() * cos(a) * 1));
        setY(getY() + (getSpeed() * sin(a) * 1));
    }

}
