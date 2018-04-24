package test;

import model.Move;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static java.lang.Math.atan2;
import static java.lang.Math.cos;
import static java.lang.Math.sin;
import static org.testng.AssertJUnit.assertEquals;

public class MoveTest {
    private Move move;

    @BeforeMethod
    public void setUp() {
        double speed = 0.2;
        move = new Move(0,0,speed);
    }

    @Test
    public void getSpeed() {
        assertEquals(0.2, move.getSpeed());
    }

    @Test
    public void setSpeed() {
        move.setSpeed(0.3);
        assertEquals(0.3, move.getSpeed());
    }

    @Test
    public void moveRight() {
        move.moveRight();
        assertEquals(0 + 0.2, move.getX());
    }

    @Test
    public void moveLeft() {
        move.moveLeft();
        assertEquals(0 - 0.2, move.getX());
    }

    @Test
    public void moveGeneral() {
        move.moveGeneral(10,10);
        double a = atan2(10 - move.getY(), 10 - move.getX());
        assertEquals(move.getSpeed() * cos(a), move.getX());
        assertEquals(move.getSpeed() * sin(a), move.getY());
    }
}