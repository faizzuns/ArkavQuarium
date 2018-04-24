package test;

import static model.Coin.BASE_COIN;
import static org.testng.AssertJUnit.assertEquals;
import static org.testng.AssertJUnit.assertTrue;

import model.Animals.Guppy;
import model.Coin;
import model.FishFood;
import model.LinkedList;
import org.testng.annotations.Test;

public class GuppyTest {

    @Test
    public void getPhase() {
        Guppy guppy = new Guppy(0,0);
        assertEquals(1, guppy.getPhase());
    }

    @Test
    public void setPhase() {
        Guppy guppy = new Guppy(0,0);
        guppy.setPhase(2);
        assertEquals(2, guppy.getPhase());
    }

    @Test
    public void getTotalEatenFood() {
        Guppy guppy = new Guppy(0,0);
        assertEquals(0, guppy.getTotalEatenFood());
    }

    @Test
    public void setTotalEatenFood() {
        Guppy guppy = new Guppy(0,0);
        guppy.setTotalEatenFood(1);
        assertEquals(1, guppy.getTotalEatenFood());
    }

    @Test
    public void getCoinValue() {
        Guppy guppy = new Guppy(0,0);
        assertEquals(Guppy.COIN_VALUE_PHASE_1, guppy.getCoinValue());
    }

    @Test
    public void setCoinValue() {
        Guppy guppy = new Guppy(0,0);
        guppy.setCoinValue(Guppy.COIN_VALUE_PHASE_2);
        assertEquals(Guppy.COIN_VALUE_PHASE_2, guppy.getCoinValue());
    }

    @Test
    public void eat() {
        Guppy guppy = new Guppy(0,0);
        LinkedList<FishFood> listFood = new LinkedList<FishFood>();
        FishFood fishFood = new FishFood(0, 0);
        listFood.add(fishFood);
        guppy.eat(listFood);
        assertEquals(1, guppy.getTotalEatenFood());
    }

    @Test
    public void makeCoin() {
        Guppy guppy = new Guppy(0,0);
        Coin coin = guppy.makeCoin(guppy.getPhase());
        assertTrue(coin.getX() == 0 && coin.getY() == 0 && coin.getValue() == guppy.getCoinValue() * BASE_COIN);
    }

    @Test
    public void nextPhase() {
        Guppy guppy = new Guppy(0,0);
        guppy.nextPhase();
        assertEquals(2, guppy.getPhase());
    }

    @Test
    public void getNearestFood() {
        Guppy guppy = new Guppy(0,0);
        LinkedList<FishFood> listFood = new LinkedList<FishFood>();
        FishFood fishFood1 = new FishFood(3, 3);
        FishFood fishFood2 = new FishFood(2, 2);
        listFood.add(fishFood1);
        listFood.add(fishFood2);
        int idxFood = guppy.getNearestFood(listFood);
        assertEquals(1, idxFood);
    }

    @Test
    public void synchronize() {
    }

    @Test
    public void getImagePath() {
    }
}