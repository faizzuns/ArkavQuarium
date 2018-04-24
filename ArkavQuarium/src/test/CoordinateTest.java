package test;

import model.Coordinate;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static org.testng.AssertJUnit.assertEquals;
import static org.testng.AssertJUnit.assertTrue;

public class CoordinateTest {
    Coordinate coordinate;

    @BeforeMethod
    public void setUp() {
        coordinate = new Coordinate(0,0);
    }

    @Test
    public void getX() {
        assertEquals(0.0, coordinate.getX());
    }

    @Test
    public void setX() {
        coordinate.setX(1);
        assertEquals(1.0, coordinate.getX());
    }

    @Test
    public void getY() {
        assertEquals(0.0, coordinate.getY());
    }

    @Test
    public void setY() {
        coordinate.setY(1);
        assertEquals(1.0, coordinate.getY());
    }

    @Test
    public void distance2Point() {
        double distance = coordinate.distance2Point(0,0,1,0);
        assertEquals(1.0, distance);
    }

    @Test
    public void beetweenX() {
        assertTrue(coordinate.beetweenX(1,1));
    }

    @Test
    public void beetweenY() {
        assertTrue(coordinate.beetweenY(1,1));
    }
}