package test;

import model.Coin;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static org.testng.AssertJUnit.assertEquals;

public class CoinTest {
    private Coin coin;
    @BeforeMethod
    public void setUp() {
        coin = new Coin(0,0,100);
    }

    @Test
    public void getValue() {
        assertEquals(100, coin.getValue());
    }

    @Test
    public void getImagePath() {
    }
}