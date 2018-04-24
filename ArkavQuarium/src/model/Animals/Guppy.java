package model.Animals;

import model.Coin;
import model.FishFood;
import model.LinkedList;

import static model.Coin.BASE_COIN;
/**
 * kelas Guppy adalah kelas yang diturunkan dari kelas Fish dan meurunkan sifat sifat dari fish
 */
public class Guppy extends Fish {

    private static final int PHASE_2 = 5;
    private static final int PHASE_3 = 10;
    public static final int COIN_VALUE_PHASE_1 = 1;
    public static final int COIN_VALUE_PHASE_2 = 2;
    private static final int COIN_VALUE_PHASE_3 = 3;
    private static final int COIN_PERIODIC = 400;

    private int phase;
    private int totalEatenFood;
    private int coinValue;

    /**
     * Constructor ini akan digunakan untuk membangun objek dengan posisi x dan y
     * @param x adalah posisi objek pada sumbu horizontal
     * @param y adalah posisi objek pada sumbu vertical
     */
    public Guppy(double x, double y) {
        super(x, y, GUPPY_SPEED);
        setPhase(1);
        setTotalEatenFood(0);
        setCoinValue(COIN_VALUE_PHASE_1);
    }

    /**
     * mengembalikkan nilai phase
     * @return mengembalikkan nilai phase
     */
    public int getPhase() {
        return phase;
    }

    /**
     * memasang nilai phase yang dimiliki guppy
     * @param phase adalah nilai phase yang akan dipasang
     */
    public void setPhase(int phase) {
        this.phase = phase;
    }

    /**
     * mengembalikan jumlah makanan yang sudah dimakan
     * @return mengembalikan jumlah makanan yang sudah dimakan
     */
    public int getTotalEatenFood() {
        return totalEatenFood;
    }

    /**
     * memasang jumlah makanan yang sudah dimakan
     * @param totalEatenFood adalah total makan yang sudah dimakan
     */
    public void setTotalEatenFood(int totalEatenFood) {
        this.totalEatenFood = totalEatenFood;
    }

    /**
     * menerima nilai coin
     * @return mengembalikan nilai coin dari objek
     */
    public int getCoinValue() {
        return coinValue;
    }

    /**
     * Melakukan pemasangan nilai pada coin
     * @param coinValue nilai coin
     */
    public void setCoinValue(int coinValue) {
        this.coinValue = coinValue;
    }

    /**
     * Method ini digunakan objek this untuk mencari makanan terdekat lalu mendekatinya kemudian memakannya
     * Setelah memakan fishfood maka state objek akan berubah menjadi full
     * jika guppy sedang lapar namun tidak ada fishfood di dalam aquarium maka guppy akan berjalan random
     * @param listFood list yang berisi fishfood di dalam aquarium
     */
    public void eat(LinkedList<FishFood> listFood) {
        if (!listFood.isEmpty()) {
            int foodIdx = getNearestFood(listFood);
            //int foodIdx = 0;
            FishFood foodTemp = listFood.get(foodIdx);

            if (beetweenX(foodTemp.getX(),5)){
                if (beetweenY(foodTemp.getY(),10)){
                    listFood.remove(foodIdx);
                    totalEatenFood++;
                    setStillFull(STATE_FULL);
                    setCountingDead(STATE_DEAD);
                    if (totalEatenFood == PHASE_2 || totalEatenFood == PHASE_3) {
                        nextPhase();
                    }
                }else moveGeneral(foodTemp.getX(),foodTemp.getY());
            }else{
                if (getX() < foodTemp.getX()){
                    moveGeneral(foodTemp.getX(), foodTemp.getY());
                    setLookAt(LOOKING_RIGHT);
                }else if (getX() > foodTemp.getX()){
                    moveGeneral(foodTemp.getX(), foodTemp.getY());
                    setLookAt(LOOKING_LEFT);
                } else randomMove();
            }
        }else randomMove();
    }

    /**
     * Method ini akan mengembalikan coin baru dan memasukkannya ke dalam list coin
     * @return mengembalikan sebuah coin baru ke dalam list of coin
     */
    public Coin makeCoin() {
        return new Coin(getX(), getY(), getCoinValue() * BASE_COIN);
    }

    /**
     * Method ini akan meningkatkan phase yang dimiliki oleh guppy dan mengubah value coin yang sesuai dengan phasenya
     */
    public void nextPhase() {
        phase++;
        if(phase == 2) {
            setCoinValue(COIN_VALUE_PHASE_2);
        } else if(phase == 3) {
            setCoinValue(COIN_VALUE_PHASE_3);
        }
    }

    /**
     * Method ini berfungsi untuk mencari fishfood yang posisinya paling dengan objek this
     * @param listFood berisi kumpulan fishfood yang sedang berada di aquarium
     * @return mengembalikan nilai indeks fishfood yang posisinya paling dekat dengan objek this
     */
    public int getNearestFood(LinkedList<FishFood> listFood) {
        //return index of nearest Food
        if (!listFood.isEmpty()){
            int n = listFood.size();
            int foodIdx;
            double distMin, distCurr;

            foodIdx = 0;
            distMin = distance2Point(listFood.get(0).getX(), listFood.get(0).getY(), this.getX(), this.getY());

            for (int i = 1; i < n; i++){
                distCurr = distance2Point(listFood.get(i).getX(), listFood.get(i).getY(), this.getX(), this.getY());
                if (distCurr <= distMin) {
                    foodIdx = i;
                    distMin = distCurr;
                }
            }
            return foodIdx;
        }else return 0;
    }

    /**
     * Method ini digunakan untuk melakukan sinkronisasi setiap satuan waktu komputer
     * dimana setiap sinkronisasi maka waktu hungry akan disesuaikan.
     * Pada setiap waktu tertentu objek dapat berubah state dari full menjadi hungry
     * dan dari hungry menjadi dead
     * selain itu fungsi ini juga akan mengenerate coin dalam beberapa satuan waktu komputer
     * @return jika mengembalikan nilai 2 maka ikan berada pada posisi kenyang
     * jika 1 maka lapar
     * jika 0 maka mati dan ikan dihapus dari list
     */
    public int synchronize(LinkedList<Coin> listCoin) {
        setLifetime((getLifetime() + 1) % 1000);
        if (getLifetime() % COIN_PERIODIC == 0) {
            listCoin.add(makeCoin());
        }
        if (notHungry()) {
            setStillFull(getStillFull() - 1);
            return 2;
            //fish move randomly
        } else {
            setCountingDead(getCountingDead() - 1);
            if (getCountingDead() == 0) {
                return 0;
                //fish is dead
            } else {
                return 1;
                //fish is dying
            }
        }
    }

    /**
     * method ini digunakan untuk menentukan arah wajah guppy
     * jika guppy sedang mengarah ke kanan maka akan mengembalikan path gambar guppy ke kanan
     * jika guppy sedang mengarah ke kiri maka akan mengembalikan path gambar guppy ke kiri
     * @return mengembalikan string yang berisi path pada suatu gambar
     */
    public String getImagePath(){
        String s = PATH_DRAWABLE +  "guppy";

        s += String.valueOf(getPhase());
        s += LOOKING_RIGHT == getLookAt() ? "kanan" : "kiri";
        if (!notHungry()) s += "lapar";

        s += ".png";

        return s;
    }
}
