package model.Animals;

import model.Move;

public class Animals extends Move {
    static final int LOOKING_LEFT = 0;
    static final int LOOKING_RIGHT = 1;

    private int lookAt;

    Animals(double x, double y, double speed) {
        super(x, y, speed);
        lookAt = LOOKING_LEFT;
    }

    public int getLookAt() {
        return lookAt;
    }

    public void setLookAt(int lookAt) {
        this.lookAt = lookAt;
    }
}
