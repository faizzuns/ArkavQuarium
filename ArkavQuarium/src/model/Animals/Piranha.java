package model.Animals;

import model.Coin;
import model.LinkedList;

/**
 * kelas Piranha adalah kelas yang diturunkan dari kelas Fish dan meurunkan sifat sifat dari fish
 */
public class Piranha extends Fish {

    /**
     * Constructor ini akan digunakan untuk membangun objek dengan posisi x dan y
     * @param x adalah posisi objek pada sumbu horizontal
     * @param y adalah posisi objek pada sumbu vertical
     */
    public Piranha(double x, double y) {
        super(x, y, PIRANHA_SPEED);
    }

    /**
     * Method ini digunakan objek this untuk mencari makanan terdekat lalu mendekatinya kemudian memakannya
     * Setelah memakan guppy maka objek akan menghasilkan coin dan memasukkannya ke list coin
     * jika piranha sedang lapar namun tidak ada guppy di dalam aquarium maka piranha akan berjalan random
     * @param listGuppy list yang berisi guppy di dalam aquarium
     * @param listCoin yang berisi coin di dalam aquarium
     */
    public void eat(LinkedList<Guppy> listGuppy, LinkedList<Coin> listCoin) {
        if (!listGuppy.isEmpty()) {
            int guppyIdx = getNearestGuppy(listGuppy);
            Guppy guppyTemp = listGuppy.get(guppyIdx);

            if (beetweenX(guppyTemp.getX(),5)){
                if (beetweenY(guppyTemp.getY(),10)){
                    listCoin.add(makeCoin(listGuppy.get(guppyIdx).getPhase()));
                    listGuppy.remove(guppyIdx);
                    setStillFull(STATE_FULL);
                    setCountingDead(STATE_DEAD);
                }else moveGeneral(guppyTemp.getX(), guppyTemp.getY());
            }else{
                if (getX() < guppyTemp.getX()){
                    moveGeneral(guppyTemp.getX(), guppyTemp.getY());
                    setLookAt(LOOKING_RIGHT);
                }else if (getX() > guppyTemp.getX()){
                    moveGeneral(guppyTemp.getX(), guppyTemp.getY());
                    setLookAt(LOOKING_LEFT);
                } else randomMove();
            }
        } else randomMove();
    }

    /**
     * Method ini akan membuat objek this mengeluarkan coin dan menambahkannya di list koin
     * koin akan dibuat setiap kali objek memakan guppy,
     * nilai koin yang dihasilkan tergantung oleh phase guppy yang dimakan
     * @param phase adalah phase yang dimiliki oleh guppy yang dimakan
     * @return mengembalikan sebuah objek baru yang diletakan di list koin
     */
    public Coin makeCoin(int phase) {
        int x = GUPPY_PRICE * (phase + 1);
        return new Coin(getX(), getY(), x);
    }

    /**
     * Method ini berfungsi untuk mencari guppy yang posisinya paling dengan objek this
     * @param listGuppy berisi kumpulan guppy yang sedang berada di aquarium
     * @return mengembalikan nilai indeks guppy yang posisinya paling dekat dengan objek this
     */
    public int getNearestGuppy(LinkedList<Guppy> listGuppy) {
        if (!listGuppy.isEmpty()){
            int n = listGuppy.size();
            int guppyIdx;
            double distMin, distCurr;

            guppyIdx = 0;
            distMin = distance2Point(listGuppy.get(0).getX(), listGuppy.get(0).getY(), this.getX(), this.getY());

            for (int i = 1; i < n; i++){
                distCurr = distance2Point(listGuppy.get(i).getX(), listGuppy.get(i).getY(), this.getX(), this.getY());
                if (distCurr <= distMin) {
                    guppyIdx = i;
                    distMin = distCurr;
                }
            }
            return guppyIdx;
        }else return 0;
    }

    /**
     * Method ini digunakan untuk melakukan sinkronisasi setiap satuan waktu komputer
     * dimana setiap sinkronisasi maka waktu hungry akan disesuaikan.
     * Pada setiap waktu tertentu objek dapat berubah state dari full menjadi hungry
     * dan dari hungry menjadi dead
     * @return jika mengembalikan nilai 2 maka ikan berada pada posisi kenyang
     * jika 1 maka lapar
     * jika 0 maka mati dan ikan dihapus dari list
     */
    public int synchronize() {
        setLifetime((getLifetime() + 1) % 1000);
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
     * method ini digunakan untuk menentukan arah wajah piranha
     * jika piranha sedang mengarah ke kanan maka akan mengembalikan path gambar piranha ke kanan
     * jika piranha sedang mengarah ke kiri maka akan mengembalikan path gambar piranha ke kiri
     * @return mengembalikan string yang berisi path pada suatu gambar
     */
    public String getImagePath(){
        String s = PATH_DRAWABLE +  "Carnivore";

        s += LOOKING_RIGHT == getLookAt() ? "kanan" : "";

        s += ".png";

        return s;
    }

}
