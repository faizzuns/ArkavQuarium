package test;

import model.Animals.Snail;
import model.Coin;
import model.LinkedList;
import org.testng.annotations.Test;

import static org.testng.AssertJUnit.assertEquals;

public class SnailTest {

    @Test
    public void eat() {
        Snail snail = new Snail(0,0);
        LinkedList<Coin> listCoin = new LinkedList<>();
        listCoin.add(new Coin(0,0, 25));
        assertEquals(25, snail.eat(listCoin));
    }

    @Test
    public void getNearestCoin() {
        Snail snail = new Snail(0,0);
        LinkedList<Coin> listCoin = new LinkedList<>();
        listCoin.add(new Coin(0,0, 25));
        assertEquals(0, snail.getNearestCoin(listCoin));
    }

}