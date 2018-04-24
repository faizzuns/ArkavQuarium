package test;

import model.Animals.Fish;
import model.Coordinate;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static model.Animals.Fish.STATE_DEAD;
import static model.Animals.Fish.STATE_FULL;
import static org.testng.AssertJUnit.assertEquals;
import static org.testng.AssertJUnit.assertTrue;

public class FishTest {

    private Fish fish;

    @BeforeMethod
    public void setUp() {
        double speed = 20;
        fish = new Fish(0,0, speed);
    }

    @Test
    public void getLifetime() {
        assertEquals(0, fish.getLifetime());
    }

    @Test
    public void setLifetime() {
        fish.setLifetime(1);
        assertEquals(1, fish.getLifetime());
    }

    @Test
    public void getStillFull() {
        assertEquals(STATE_FULL, fish.getStillFull());
    }

    @Test
    public void setStillFull() {
        fish.setStillFull(700);
        assertEquals(700, fish.getStillFull());
    }

    @Test
    public void getCountingDead() {
        assertEquals(STATE_DEAD, fish.getCountingDead());
    }

    @Test
    public void setCountingDead() {
        fish.setCountingDead(1000);
        assertEquals(1000, fish.getCountingDead());
    }

    @Test
    public void getRanda() {
        assertTrue(fish.getRanda().getX() == 0 && fish.getRanda().getY() == 0);
    }

    @Test
    public void setRanda() {
        fish.setRanda(new Coordinate(0,0));
        assertTrue(fish.getRanda().getX() == 0 && fish.getRanda().getY() == 0);
    }

    @Test
    public void randomMove() {
        fish.randomMove();
        assertTrue(fish.getRanda().getX() == 320 && fish.getRanda().getY() == 240);
    }

    @Test
    public void notHungry() {
        assertTrue(fish.notHungry());
    }
}