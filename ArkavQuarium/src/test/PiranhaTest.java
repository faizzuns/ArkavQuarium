package test;

import model.Animals.Guppy;
import model.Animals.Piranha;
import model.Coin;
import model.LinkedList;
import org.testng.annotations.Test;

import static model.Animals.Fish.GUPPY_PRICE;
import static org.testng.AssertJUnit.assertEquals;
import static org.testng.AssertJUnit.assertTrue;

public class PiranhaTest {

    @Test
    public void eat() {
        Piranha piranha = new Piranha(0,0);
        Guppy guppy = new Guppy(0,0);

        LinkedList<Coin> listCoin = new LinkedList<>();
        LinkedList<Guppy> listGuppy = new LinkedList<>();

        listGuppy.add(guppy);
        piranha.eat(listGuppy, listCoin);
        Coin coin = listCoin.get(0);

        assertTrue(listGuppy.isEmpty());
        assertTrue(coin.getX() == 0 && coin.getY() == 0 && coin.getValue() == 2 * GUPPY_PRICE);
    }

    @Test
    public void makeCoin() {
        Piranha piranha = new Piranha(0.0,0.0);
        Coin coin = piranha.makeCoin(1);

        assertTrue(coin.getX() == 0.0 && coin.getY() == 0.0 && coin.getValue() == 2 * GUPPY_PRICE);
    }
    @Test
    public void getNearestGuppy() {
        Piranha piranha = new Piranha(0,0);
        LinkedList<Guppy> listGuppy = new LinkedList<>();

        listGuppy.add(new Guppy(0,0));
        int idxGuppy = piranha.getNearestGuppy(listGuppy);
        assertEquals(0, idxGuppy);
    }
}