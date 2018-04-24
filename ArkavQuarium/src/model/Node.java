package model;

/**
 * Kelas yang membantu LinkedList untuk menaruh
 * reference suatu obyek.
 * memiliki atribut data dan next.
 *
 * @param <T> Tipe Object dari kelas Node
 */
class Node<T> {
    private final T data;
    private Node<T> next;

    /**
     * Constructor dengan parameter data
     * akan mengassign atribut kelas data dengan parameter data
     *
     * @param data data
     */
    Node(T data) {
        this.data = data;
        this.next = null;
    }

    /**
     * Getter
     *
     * @return atribut kelas data
     */
    T getData() {
        return data;
    }

    /**
     * Getter
     *
     * @return Node yang ditunjuk oleh kelas ini
     */
    Node<T> getNext() {
        return next;
    }

    /**
     * parameter node yang akan di assign ke atirbut kelas node
     *
     * @param next data node
     */
    void setNext(Node<T> next) {
        this.next = next;
    }
}
