package model;

/**
 * Kelas yang membantu LinkedList untuk menaruh
 * reference suatu obyek.
 * memiliki atribut data dan next.
 *
 * @param <T> Tipe Object dari kelas Node
 */
public class Node<T> {
    private T data;
    private Node<T> next;

    /**
     * Constructor dengan parameter data
     * akan mengassign atribut kelas data dengan parameter data
     *
     * @param data data
     */
    public Node(T data) {
        this.data = data;
        this.next = null;
    }

    /**
     * Getter
     *
     * @return atribut kelas data
     */
    public T getData() {
        return data;
    }

    /**
     * Getter
     *
     * @return Node yang ditunjuk oleh kelas ini
     */
    public Node<T> getNext() {
        return next;
    }

    /**
     * parameter node yang akan di assign ke atirbut kelas node
     *
     * @param next data node
     */
    public void setNext(Node<T> next) {
        this.next = next;
    }
}
