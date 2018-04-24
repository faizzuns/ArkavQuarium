import model.Aquarium;

import java.io.IOException;

class Main {

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
