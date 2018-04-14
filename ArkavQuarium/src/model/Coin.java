package model;

public class Coin extends Move{

    public static int BASE_COIN = 10;

    private int value;

    public Coin(double x, double y, int value) {
        super(x, y, COIN_SPEED);
        this.value = value;
    }

    public static int getBaseCoin() {
        return BASE_COIN;
    }

    public static void setBaseCoin(int baseCoin) {
        BASE_COIN = baseCoin;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}
