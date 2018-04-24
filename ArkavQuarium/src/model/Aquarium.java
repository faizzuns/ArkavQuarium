package model;


import model.Animals.Guppy;
import model.Animals.Piranha;
import model.Animals.Snail;

import javax.imageio.ImageIO;
import javax.swing.*;

import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;

import static model.Animals.Fish.GUPPY_PRICE;
import static model.Animals.Fish.PIRANHA_PRICE;

public class Aquarium extends JPanel {
    private static final int BASE_EGG_PRICE = 30;
    public static int SCREEN_WIDTH = 640;
    public static int SCREEN_HEIGHT = 480;
    public static int LOSE = 0;
    public static int WIN = 1;
    public static int LOAD = 0;
    public static int NEW = 1;
    public static int HOME = 0;
    public static int PLAY = 1;
    public static int FINISH = 2;

    private final String CURRENT_IMAGE = "E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\guppy0kiri.png";
    private final String BACKGROUND_IMAGE = "E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\background.jpg";
    private final String BAR_IMAGE = "E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\bar.png";

    private LinkedList<Guppy> listGuppy;
    private LinkedList<Piranha> listPiranha;
    private LinkedList<FishFood> listFishFood;
    private LinkedList<Coin> listCoin;
    private Snail snail;
    private int telur;
    private int duit;


    private BufferedImage defaultImage;
    private Map<String, BufferedImage> images;
    private int status;
    private String res;
    private int playCategory = -1;

    private long fps;

    private JFrame jFrame;

    public Aquarium(String defaultObjectImagePath) throws IOException {
        this.defaultImage = ImageIO.read(new File(defaultObjectImagePath));
        this.images = new HashMap<>();

        this.fps = 1000000000L / 128L;

        listGuppy = new LinkedList<Guppy>();
        listPiranha = new LinkedList<Piranha>();
        listFishFood = new LinkedList<FishFood>();
        listCoin = new LinkedList<Coin>();
        snail = new Snail(SCREEN_WIDTH / 2, 400);
        playCategory = -1;
    }

    private BufferedImage readImage(String path) {
        BufferedImage newImage = this.images.get(path);
        if (newImage == null) {
            try {
                newImage = ImageIO.read(new File(path));
            } catch (IOException e) {
                newImage = defaultImage;
            }
            this.images.put(path, newImage);
        }
        return newImage;
    }

    public void startAquarium(){
        status = HOME;

        while (playCategory == -1){
            System.out.println(playCategory);
        }
        playAquarium();
    }

    public void playAquarium(){
        status = PLAY;
        long lastFrameStart = System.nanoTime();
        long now;

        if (playCategory == LOAD) readFile();
        else initDefault();

        while (true) {
            now = System.nanoTime();

            if ((now - lastFrameStart) >= fps) {
                syncAll();

                if (telur == 3){
                    setResult(WIN);
                    break;
                }else{
                    if (listCoin.size() == 0 && listGuppy.size() == 0 && listPiranha.size() == 0 && duit < GUPPY_PRICE){
                        setResult(LOSE);
                        break;
                    }
                }

                jFrame.invalidate();
                jFrame.validate();
                jFrame.repaint();
                lastFrameStart = now;
            }
        }
    }

    public void setResult(int result){
        status = FINISH;
        res = WIN == result ? "WIN" : "LOSE";
        jFrame.invalidate();
        jFrame.validate();
        jFrame.repaint();
    }

    public void syncAll(){
        int i = 0;
        while (i < listFishFood.size()){
            listFishFood.get(i).moveGeneral(listFishFood.get(i).getX(), 400);

            if (listFishFood.get(i).getY() > 400){
                listFishFood.remove(i);
            }else i++;
        }

        i = 0;
        while (i < listCoin.size()){
            if (!listCoin.get(i).beetweenY(400, 2)){
                listCoin.get(i).moveGeneral(listCoin.get(i).getX(), 400);
            }
            i++;
        }

        i = 0;
        while (i < listGuppy.size()){
            int j = listGuppy.get(i).synchronize(listCoin);
            if (j == 0){
                listGuppy.remove(i);
            }else {
                if (j == 1){
                    //lapar
                    listGuppy.get(i).eat(listFishFood);
                }else {
                    // ga lapar
                    listGuppy.get(i).randomMove();
                }
                i++;
            }
        }

        i = 0;
        while (i < listPiranha.size()){
            int j = listPiranha.get(i).synchronize(listCoin);
            if (j == 0){
                listPiranha.remove(i);
            }else{
                if (j == 1){
                    //laper
                    listPiranha.get(i).eat(listGuppy, listCoin);
                }else{
                    //ga laper
                    listPiranha.get(i).randomMove();
                }
                i++;
            }
        }

        int dapat = snail.eat(listCoin);
        duit += dapat;
    }

    public void buildFrame() {
        jFrame = new JFrame();
        jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        jFrame.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
        jFrame.setVisible(true);
    }

    public void setContent(){
        jFrame.setContentPane(this);
        jFrame.getContentPane().addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                super.mouseClicked(e);
                System.out.println(e.getLocationOnScreen().getX() + ", " + e.getLocationOnScreen().getY());
                double mouseX = e.getLocationOnScreen().getX();
                double mouseY = e.getLocationOnScreen().getY();

                if (status == PLAY){
                    mouseY -= 35;
                    int i = 0;
                    while(i < listCoin.size()){
                        if (listCoin.get(i).beetweenX(mouseX, 20) && listCoin.get(i).beetweenY(mouseY, 20)){
                            break;
                        }
                        i++;
                    }

                    if (i != listCoin.size()){
                        duit += listCoin.get(i).getValue();
                        listCoin.remove(i);
                    }else if (mouseX > 54 - 30 && mouseX < 54 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
                        saveFile();
                    }else if (mouseX > 482 - 30 && mouseX < 482 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
                        if (duit >= GUPPY_PRICE){
                            duit -= GUPPY_PRICE;
                            double aa,bb;
                            Random r = new Random();
                            aa = 100 + (300 - 100) * r.nextDouble();
                            bb = 100 + (200 - 100) * r.nextDouble();
                            if (aa < 20 && bb < 20){
                                aa = SCREEN_WIDTH / 2;
                                bb = SCREEN_HEIGHT / 2;
                            }
                            Guppy g = new Guppy(aa, bb);
                            listGuppy.add(g);
                        }
                    }else if (mouseX > 395 - 30 && mouseX < 395 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
                        if (duit >= PIRANHA_PRICE){
                            duit -= PIRANHA_PRICE;
                            double aa,bb;
                            Random r = new Random();
                            aa = 100 + (300 - 100) * r.nextDouble();
                            bb = 100 + (200 - 100) * r.nextDouble();
                            if (aa < 20 && bb < 20){
                                aa = SCREEN_WIDTH / 2;
                                bb = SCREEN_HEIGHT / 2;
                            }
                            Piranha p = new Piranha(aa, bb);
                            listPiranha.add(p);
                        }
                    }else if (mouseX > 575 - 30 && mouseX < 575 + 30 && mouseY > 32 - 30 && mouseY < 32 + 30){
                        if (duit >= BASE_EGG_PRICE * (telur + 1)){
                            telur++;
                            duit -= BASE_EGG_PRICE * telur;
                        }
                    }else if (mouseY > 80 && mouseY < 400){
                        if (duit - 2 >= 0){
                            duit -= 2;
                            FishFood ff = new FishFood(mouseX, mouseY);
                            listFishFood.add(ff);
                        }
                    }
                }else if (status == HOME){
                    if (mouseX > 330 - 45 && mouseX < 330 + 45 && mouseY > 240 - 20 && mouseY < 240 + 20){
                        playCategory = NEW;
                    }else if (mouseX > 330 - 45 && mouseX < 330 + 45 && mouseY > 340 - 20 && mouseY < 340 + 20){
                        playCategory = LOAD;
                    }
                }

            }
        });
    }

    public void saveFile(){
        String fileName;

        //duit
        fileName = "duit.txt";
        try {
            // Assume default encoding.
            FileWriter fileWriter =
                    new FileWriter(fileName);
            // Always wrap FileWriter in BufferedWriter.
            BufferedWriter bufferedWriter =
                    new BufferedWriter(fileWriter);

            bufferedWriter.write(duit + "");

            // Always close files.
            bufferedWriter.close();
        }
        catch(IOException ex) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

        //telur
        fileName = "telur.txt";
        try {
            // Assume default encoding.
            FileWriter fileWriter =
                    new FileWriter(fileName);
            // Always wrap FileWriter in BufferedWriter.
            BufferedWriter bufferedWriter =
                    new BufferedWriter(fileWriter);

            bufferedWriter.write(telur + "");

            // Always close files.
            bufferedWriter.close();
        }
        catch(IOException ex) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

        //guppy
        fileName = "guppy.txt";
        try {
            // Assume default encoding.
            FileWriter fileWriter =
                    new FileWriter(fileName);
            // Always wrap FileWriter in BufferedWriter.
            BufferedWriter bufferedWriter =
                    new BufferedWriter(fileWriter);

            for (int i = 0; i < listGuppy.size(); i++){
                Guppy g = listGuppy.get(i);
                bufferedWriter.write(g.getX() + " " + g.getY() + " " + g.getSpeed() + " " + g.getLookAt() + " " + g.getLifetime() + " " + g.getStillFull() + " " + g.getCountingDead() + " " + g.getRanda().getX() + " " + g.getRanda().getY() + " " + g.getPhase() + " " + g.getTotalEatenFood() + " " + g.getCoinValue());
                bufferedWriter.newLine();
            }

            // Always close files.
            bufferedWriter.close();
        }
        catch(IOException ex) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

        //piranha
        fileName = "piranha.txt";
        try {
            // Assume default encoding.
            FileWriter fileWriter =
                    new FileWriter(fileName);
            // Always wrap FileWriter in BufferedWriter.
            BufferedWriter bufferedWriter =
                    new BufferedWriter(fileWriter);

            for (int i = 0; i < listPiranha.size(); i++){
                Piranha g = listPiranha.get(i);
                bufferedWriter.write(g.getX() + " " + g.getY() + " " + g.getSpeed() + " " + g.getLookAt() + " " + g.getLifetime() + " " + g.getStillFull() + " " + g.getCountingDead() + " " + g.getRanda().getX() + " " + g.getRanda().getY());
                bufferedWriter.newLine();
            }

            // Always close files.
            bufferedWriter.close();
        }
        catch(IOException ex) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

        //snail
        fileName = "snail.txt";
        try {
            // Assume default encoding.
            FileWriter fileWriter =
                    new FileWriter(fileName);
            // Always wrap FileWriter in BufferedWriter.
            BufferedWriter bufferedWriter =
                    new BufferedWriter(fileWriter);

            Snail g = snail;
            bufferedWriter.write(g.getX() + " " + g.getY() + " " + g.getSpeed() + " " + g.getLookAt());

            // Always close files.
            bufferedWriter.close();
        }
        catch(IOException ex) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

        //fishfood
        fileName = "fishfood.txt";
        try {
            // Assume default encoding.
            FileWriter fileWriter =
                    new FileWriter(fileName);
            // Always wrap FileWriter in BufferedWriter.
            BufferedWriter bufferedWriter =
                    new BufferedWriter(fileWriter);

            for (int i = 0; i < listFishFood.size(); i++){
                FishFood g = listFishFood.get(i);
                bufferedWriter.write(g.getX() + " " + g.getY() + " " + g.getSpeed());
                bufferedWriter.newLine();
            }

            // Always close files.
            bufferedWriter.close();
        }
        catch(IOException ex) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

        //coin
        fileName = "coin.txt";
        try {
            // Assume default encoding.
            FileWriter fileWriter =
                    new FileWriter(fileName);
            // Always wrap FileWriter in BufferedWriter.
            BufferedWriter bufferedWriter =
                    new BufferedWriter(fileWriter);

            for (int i = 0; i < listCoin.size(); i++){
                Coin g = listCoin.get(i);
                bufferedWriter.write(g.getX() + " " + g.getY() + " " + g.getSpeed() + " " + g.getValue());
                bufferedWriter.newLine();
            }

            // Always close files.
            bufferedWriter.close();
        }
        catch(IOException ex) {
            System.out.println("Error writing to file '" + fileName + "'");
        }

    }

    public void readFile(){
        String fileName, line;

        //duit
        fileName = "duit.txt";
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                duit = Integer.parseInt(line);
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }

        //telur
        fileName = "telur.txt";
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                telur = Integer.parseInt(line);
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }

        //guppy
        fileName = "guppy.txt";
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                String[] data = line.split(" ");
                Guppy g = new Guppy(Double.parseDouble(data[0]), Double.parseDouble(data[1]));
                g.setSpeed(Double.parseDouble(data[2]));
                g.setLookAt(Integer.parseInt(data[3]));
                g.setLifetime(Integer.parseInt(data[4]));
                g.setStillFull(Integer.parseInt(data[5]));
                g.setCountingDead(Integer.parseInt(data[6]));
                g.setRanda(new Coordinate(Double.parseDouble(data[7]), Double.parseDouble(data[8])));
                g.setPhase(Integer.parseInt(data[9]));
                g.setTotalEatenFood(Integer.parseInt(data[10]));
                g.setCoinValue(Integer.parseInt(data[11]));
                listGuppy.add(g);
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }

        //piranha
        fileName = "piranha.txt";
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                String[] data = line.split(" ");
                Piranha g = new Piranha(Double.parseDouble(data[0]), Double.parseDouble(data[1]));
                g.setSpeed(Double.parseDouble(data[2]));
                g.setLookAt(Integer.parseInt(data[3]));
                g.setLifetime(Integer.parseInt(data[4]));
                g.setStillFull(Integer.parseInt(data[5]));
                g.setCountingDead(Integer.parseInt(data[6]));
                g.setRanda(new Coordinate(Double.parseDouble(data[7]), Double.parseDouble(data[8])));
                listPiranha.add(g);
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }

        //fishfood
        fileName = "fishfood.txt";
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                String[] data = line.split(" ");
                FishFood g = new FishFood(Double.parseDouble(data[0]), Double.parseDouble(data[1]));
                g.setSpeed(Double.parseDouble(data[2]));
                listFishFood.add(g);
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }

        //coin
        fileName = "coin.txt";
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                String[] data = line.split(" ");
                Coin g = new Coin(Double.parseDouble(data[0]), Double.parseDouble(data[1]), Integer.parseInt(data[3]));
                g.setSpeed(Double.parseDouble(data[2]));
                listCoin.add(g);
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }

        //snail
        fileName = "snail.txt";
        try {
            // FileReader reads text files in the default encoding.
            FileReader fileReader =
                    new FileReader(fileName);

            // Always wrap FileReader in BufferedReader.
            BufferedReader bufferedReader =
                    new BufferedReader(fileReader);

            while((line = bufferedReader.readLine()) != null) {
                String[] data = line.split(" ");
                Snail g = new Snail(Double.parseDouble(data[0]), Double.parseDouble(data[1]));
                g.setSpeed(Double.parseDouble(data[2]));
                g.setLookAt(Integer.parseInt(data[3]));
                snail = g;
            }

            // Always close files.
            bufferedReader.close();
        }
        catch(FileNotFoundException ex) {
            System.out.println(
                    "Unable to open file '" +
                            fileName + "'");
        }
        catch(IOException ex) {
            System.out.println(
                    "Error reading file '"
                            + fileName + "'");
        }
    }

    public void initDefault(){
        duit = 10;
        telur = 0;
        listGuppy.add(new Guppy(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
    }

    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        setBackground(Color.WHITE);
        g.setColor(Color.WHITE);
        g.drawImage(readImage(BACKGROUND_IMAGE), 0, 0, null);

        if (status == HOME){
            g.drawImage(readImage("E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\button_start.png"), SCREEN_WIDTH / 2 - 45, SCREEN_HEIGHT / 2 - 50, null);
            g.drawImage(readImage("E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\button_load.png"), SCREEN_WIDTH / 2 - 45, SCREEN_HEIGHT / 2 + 50, null);
            return;
        }

        if (status == FINISH){
            g.drawString(res, SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 - 30);
        }
        
        g.drawImage(readImage(BAR_IMAGE), 0, 0, null);

        //save
        g.drawString("SAVE", 40, 35);

        //beli telor
        String telorImg = "E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\State";
        telorImg += String.valueOf(telur + 1) + ".png";
        g.drawImage(readImage(telorImg), 550, 8, null);
        String hargaTelor = "Rp. " + BASE_EGG_PRICE * (telur + 1);
        g.drawString(hargaTelor, 556, 70);

        //beli guppy
        g.drawImage(readImage("E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\guppy0kiri.png"), 460, 10, null);
        g.drawString("Rp. 5", 465, 70);

        //beli piranha
        g.drawImage(readImage("E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\Carnivorekanankecill.png"), 370, 10, null);
        g.drawString("Rp. 20", 370, 70);

        //uang
        g.drawImage(readImage("E:\\KULIAH\\SEMESTER 4\\IF2210 - Pemrograman Berorientasi Objek\\ArkavQuarium\\CPP\\draw\\Diamond.png"), 285, 15, null);
        String uang = "Rp. " + duit;
        g.drawString(uang, 280, 70);

        //guppy
        for (int i = 0; i < listGuppy.size(); i++){
            g.drawImage(readImage(listGuppy.get(i).getImagePath()),(int) Math.floor(listGuppy.get(i).getX() - 20),(int) Math.floor(listGuppy.get(i).getY()), null);
        }

        //pirana
        for (int i = 0; i < listPiranha.size(); i++){
            g.drawImage(readImage(listPiranha.get(i).getImagePath()),(int) Math.floor(listPiranha.get(i).getX() - 20),(int) Math.floor(listPiranha.get(i).getY()), null);
        }

        //coin
        for (int i = 0; i < listCoin.size(); i++){
            g.drawImage(readImage(listCoin.get(i).getImagePath()),(int) Math.floor(listCoin.get(i).getX() - 20),(int) Math.floor(listCoin.get(i).getY()), null);
        }

        //fish food
        for (int i = 0; i < listFishFood.size(); i++){
            g.drawImage(readImage(listFishFood.get(i).getImagePath()),(int) Math.floor(listFishFood.get(i).getX() - 20),(int) Math.floor(listFishFood.get(i).getY()), null);
        }

        //snail
        g.drawImage(readImage(snail.getImagePath()), (int) Math.floor(snail.getX()), (int) Math.floor(snail.getY()) - 30, null);

    }

}
