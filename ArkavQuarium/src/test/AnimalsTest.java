package test;

import model.Animals.Animals;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static model.Animals.Animals.LOOKING_LEFT;
import static model.Animals.Animals.LOOKING_RIGHT;
import static org.testng.AssertJUnit.assertEquals;

public class AnimalsTest {
    private Animals animals;
    @BeforeMethod
    public void setUp() {
        animals = new Animals(0,0,0.3);
    }

    @Test
    public void getLookAt() {
        assertEquals(LOOKING_LEFT, animals.getLookAt());
    }

    @Test
    public void setLookAt() {
        animals.setLookAt(LOOKING_RIGHT);
        assertEquals(LOOKING_RIGHT, animals.getLookAt());
    }
}