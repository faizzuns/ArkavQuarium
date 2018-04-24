package test;

import model.LinkedList;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static org.testng.AssertJUnit.assertEquals;

public class LinkedListTest {
    private LinkedList<Integer> listInteger;

    @BeforeMethod
    public void setUp() {
        listInteger = new LinkedList<>();
    }

    @Test
    public void isEmpty() {
        assertEquals(true, listInteger.isEmpty());
    }

    @Test
    public void size() {
        assertEquals(0, listInteger.size());
    }

    @Test
    public void add() {
        listInteger.add(2);
        Integer expected;
        expected = 2;
        assertEquals(expected, listInteger.get(0));
    }


    @Test
    public void get() {
        assertEquals(null, listInteger.get(0));
    }

}