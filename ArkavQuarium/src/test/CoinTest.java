package test;

import model.Coin;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static model.Coin.BASE_COIN;
import static org.testng.AssertJUnit.assertEquals;

public class CoinTest {
    Coin coin;
    @BeforeMethod
    public void setUp() {
        coin = new Coin(0,0,100);
    }

    @Test
    public void getBaseCoin() {
        assertEquals(BASE_COIN, coin.getBaseCoin());
    }

    @Test
    public void setBaseCoin() {
        coin.setBaseCoin(11);
        assertEquals(11, coin.getBaseCoin());
    }

    @Test
    public void getValue() {
        assertEquals(100, coin.getValue());
    }

    @Test
    public void setValue() {
        coin.setValue(200);
        assertEquals(200, coin.getValue());
    }

    @Test
    public void getImagePath() {
    }
}