package model;

/**
 * Kelas yang merepresentasikan makanan ikan
 * Inheritance ke Kelas Move
 */
public class FishFood extends Move {

    /**
     * Constructor berparameter
     * akan memanggil constructor Move dengan parameter
     * x,y, dan FISH_FOOD_SPEED
     *
     * @param x koordinat x makanan ikan
     * @param y koordinat y makanan ikan
     */
    public FishFood(double x, double y) {
        super(x, y, FISH_FOOD_SPEED);
    }

    /**
     * mengembalikan directory dimana file makanan ikan ada
     *
     * @return path image untuk digambarkan di jawa swing
     */
    public String getImagePath(){
        return PATH_DRAWABLE + "burger.png";
    }
}
