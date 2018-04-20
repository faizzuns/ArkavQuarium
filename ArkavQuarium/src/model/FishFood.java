package model;

public class FishFood extends Move {

    public FishFood() {
        super(FISH_FOOD_SPEED);
    }

    public FishFood(double x, double y) {
        super(x, y, FISH_FOOD_SPEED);
    }

    public String getImagePath(){
        return PATH_DRAWABLE + "burger.png";
    }
}
