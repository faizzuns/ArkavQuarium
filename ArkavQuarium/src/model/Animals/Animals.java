package model.Animals;

import model.Move;

/**
 * Kelas Animals merupakan representasi dari Binatang
 * memiliki atribut lookAt
 */
public class Animals extends Move {
    static final int LOOKING_LEFT = 0;
    static final int LOOKING_RIGHT = 1;

    private int lookAt;

    /**
     * Constructor Berparameter
     * Akan memanggil Constructor dari Move dengan
     * parameter x, y, speed
     * meng-set nilai lookAt menjadi LOOKING_LEFT
     *
     * @param x koordinat x
     * @param y koordinat y
     * @param speed speed entitas
     */
    Animals(double x, double y, double speed) {
        super(x, y, speed);
        lookAt = LOOKING_LEFT;
    }

    /**
     * Getter
     *
     * @return mengembalikan nilai lookAt
     */
    public int getLookAt() {
        return lookAt;
    }

    /**
     * Setter
     * akan mengassign parameter lookAt ke atribut kelas lookAt
     *
     * @param lookAt arah Animal melihat
     */
    public void setLookAt(int lookAt) {
        this.lookAt = lookAt;
    }
}
