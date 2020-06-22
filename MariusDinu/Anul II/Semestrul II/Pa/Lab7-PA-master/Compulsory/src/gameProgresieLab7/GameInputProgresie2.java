package gameProgresieLab7;

import gameProgresieLab7.BoardProgresie;

import java.io.BufferedReader;
import java.io.Console;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;

public class GameInputProgresie2 {
    gameProgresieLab7.BoardProgresie b;
    Thread object1;
    Thread object2;
    int k;
    int player1Count=0;
    int player2Count=0;
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);

    public GameInputProgresie2(){}

    public GameInputProgresie2(PlayerProgresie player1, PlayerProgresie player2, int k, BoardProgresie board) throws IOException {

        b = board;
        int turn = 1;
        boolean start = true;
        int prog = k;
        int countCartonase = 0;
        object1 = new Thread(new PlayerProgresie(player1.name, b, 1));
        object2 = new Thread(new PlayerProgresie(player2.name, b, 2));
        object1.start();
        object2.start();
    }
}
