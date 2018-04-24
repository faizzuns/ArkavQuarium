package model;

/**
 * Kelas yang merepresentasikan Coin yang dihasilkan Ikan
 * Inheritance ke Kelas Move
 *
 * memiliki atribut value
 */
public class Coin extends Move{
    public static int BASE_COIN = 10;

    private int value;

    public Coin(double x, double y, int value) {
        super(x, y, COIN_SPEED);
        this.value = value;
    }

    public int getValue() {
        return value;
    }

    public String getImagePath(){
        return PATH_DRAWABLE + "Diamond.png";
    }
}
