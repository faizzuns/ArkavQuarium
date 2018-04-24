package test;

import model.Node;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import static org.testng.AssertJUnit.assertEquals;

public class NodeTest {
    private Node<Integer> node = new Node<>(0);
    @BeforeMethod
    public void setUp() {
        node = new Node<>(1);
    }

    @Test
    public void getData() {
        Integer expected;
        expected = 1;
        assertEquals(expected, node.getData());
    }

    @Test
    public void setData() {
        Integer expected;
        expected = 2;
        node.setData(2);
        assertEquals(expected, node.getData());
    }

    @Test
    public void getNext() {
        assertEquals(null, node.getNext());
    }

    @Test
    public void setNext() {
        Node<Integer> nodeNext = new Node<>(2);
        node.setNext(nodeNext);
        Integer expected;
        expected = 2;
        assertEquals(expected, node.getNext().getData());
    }
}