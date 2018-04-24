package model;

/**
 * Kelas Coordinate adalah kelas yang merepresentasikan kordinat dalam kartesius.
 * memiliki atribut x dan y.
 */
public class Coordinate {
    private double x;
    private double y;

    protected final String PATH_DRAWABLE = "E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\";

    /**
     *Default Constructor
     * menginisiasi x dan y dengan nilai DEFAULT_VALUE
     */
    public Coordinate() {
        int DEFAULT_VALUE = 0;
        x = DEFAULT_VALUE;
        y = DEFAULT_VALUE;
    }

    /**
     * Constructor dengan paramter
     * akan mengassign atribut kelas x dengan nilai dari parameter x
     * akan mengassign atribut kelas y dengan nilai dari parameter y
     *
     * @param x koordinat x
     * @param y koordinat y
     */
    public Coordinate(double x, double y) {
        this.x = x;
        this.y = y;
    }

    /**
     * Getter Atribut x
     *
     * @return nilai dari x
     */
    public double getX() {
        return x;
    }

    /**
     * akan mengubah nilai atribut x dengan nilai dari parameter x
     *
     * @param x koordinat x
     */
    public void setX(double x) {
        this.x = x;
    }

    /**
     * Getter Atribut y
     *
     * @return nila dari y
     */
    public double getY() {
        return y;
    }

    /**
     * akan mengubah nilai atribut y dengan nilai dari parameter y
     *
     * @param y koordinat y
     */
    public void setY(double y) {
        this.y = y;
    }

    /**
     * method ini menerima 4 buah input yang merupakan
     * representasi dari 2 titik.
     *
     * @param x1 koordinat x dari titik 1
     * @param y1 koordinat y dari titik 1
     * @param x2 koordinat x dari titik 2
     * @param y2 koordinat y dari titik 2
     * @return panjang dari titik1 dan titik2
     */
    public double distance2Point(double x1, double y1, double x2, double y2){
        double distance;
        distance = Math.sqrt((Math.pow(x2-x1,2)) + (Math.pow(y2-y1,2)));
        return distance;
    }

    /**
     * method menerima 2 buah parameter, cX dan radius
     *
     * @param cX koordinat x yang akan dicek
     * @param radius radius pengecekan untuk area dari atribut x
     * @return menghasilkan true jika cX masih dalam radius atribut kelas x
     */
    public boolean beetweenX(double cX, double radius){
        return ((cX <= (x + radius)) && (cX >= (x - radius)));
    }

    /**
     *method menerima 2 buah parameter, cY dan radius
     *
     * @param cY koordina y yang akan dicek
     * @param radius radius pengecekan untuk area dari atribut y
     * @return menghasilkan true jika cY masih dalam radius kelas y
     */
    public boolean beetweenY(double  cY, int radius){
        return ((cY <= (y + radius)) && (cY >= (y - radius)));
    }

}
