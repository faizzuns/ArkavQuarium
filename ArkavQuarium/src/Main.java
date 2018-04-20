import model.Aquarium;

import javax.swing.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;

import static model.Aquarium.NEW;
import static model.Aquarium.SCREEN_HEIGHT;
import static model.Aquarium.SCREEN_WIDTH;

public class Main {

    public static void main(String[] args) {
	// write your code here

        try {
            Aquarium aquarium = new Aquarium("D:\\Semester4\\IF2210-PemrogramanBerorientasiObjek\\ArkavQuarium\\CPP\\draw\\guppy0kiri.png");
            aquarium.buildFrame();

            aquarium.setContent();
            aquarium.startAquarium();

        } catch (IOException e) {
            e.printStackTrace();
        }


    }
}
