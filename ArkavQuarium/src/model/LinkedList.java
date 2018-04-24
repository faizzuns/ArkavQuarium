package model;

/**
 * Kelas LinkedList adalah kelas yang memiliki 1 atribut yaitu head.
 * head bertipe Node yang nantinya akan selalu menunjuk sampai akhir dari node
 *
 * @param <T> Generic type untuk LinkedList
 */
public class LinkedList<T> {
    private Node<T> head;

    /**
     * Default Constructor
     */
    public LinkedList() {
        head = null;
    }

    /**
     *
     * @return mengembalikan true jika node tidak ada isinya, head == null
     */
    public boolean isEmpty(){
        return head == null;
    }

    /**
     *
     * @return mengembalikan jumlah node yang ada di list
     */
    public int size(){
        int count = 0;
        Node<T> now = head;
        while (now != null) {
            count++;
            now = now.getNext();
        }
        return count;
    }

    /**
     *
     * @param element element yang akan ditambahkan kelist
     */
    public void add(T element){
        if (head == null){
            head = new Node<>(element);
        }
        else{
            Node<T> temp = head;
            while (temp.getNext() != null) temp = temp.getNext();
            temp.setNext(new Node<>(element));
        }
    }

    /**
     * Method ini akan menghapus elemen di dalam list
     *
     * @param idx index dari node yang ingin dihapus
     */
    public void remove(int idx){
        Node<T> prev = null;
        Node<T> now = head;

        int i = 0;
        while (i < idx){
            prev = now;
            now = now.getNext();
            i++;
        }

        if (now != null){
            if (prev != null){
                prev.setNext(now.getNext());
            }else{
                head = now.getNext();
            }
            now.setNext(null);
        }

    }

    /**
     * Method untuk menganbil element pada indeks sesuai parameter
     *
     * @param index index yang diinginkan
     * @return mengembalikan element
     */
    public T get(int index){
        if (index < size()){
            Node<T> now = head;
            int i = 0;
            while (i < index) {
                now = now.getNext();
                i++;
            }
            return now.getData();
        }else{
            return null;
        }
    }
}
