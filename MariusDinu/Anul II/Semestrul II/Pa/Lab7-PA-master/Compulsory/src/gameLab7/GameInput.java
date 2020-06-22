package gameLab7;

import gameLab7.Board;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GameInput {
    Player playerFirst;
    Player playerSecond;
    gameLab7.Board b;
    Thread object1;
    Thread object2;
    int k;
    int player1Count=0;
    int player2Count=0;
    public GameInput(){}
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);
    public GameInput(Player player1, Player player2, int k, Board board) throws IOException {    playerFirst=player1;
        playerSecond=player2;
        b=board;
        int turn =1;
        boolean start=true;
        int prog=k;
        int countCartonase = 0;
        object1 = new Thread(new Player(player1.name,b,1));
        object2 = new Thread(new Player(player2.name,b,2));


        while(start) {


            if (turn == 1) {


                if((player1.countPlayer1<prog)&&(countCartonase<= b.countTokens)) {
                    System.out.println("E randul lui : "+ player1.name+"\n");
                    player1Count=player1.countPlayer1;
                    int command = GameDetails();
                    switch (command) {
                        case 4:
                            System.exit(0);
                        case 3:
                        case 2:
                            System.out.println(player1.name+" ai acumulat "+player1Count+" puncte.");
                        case 1:
                            object1.run();
                            if (player1.countPlayer1 < prog) {


                                turn = 2;
                                countCartonase++;
                                System.out.println("Pana acum s-au extras " + countCartonase + " cartonase. " + "\n");
                            } else if (player1.countPlayer1 == prog) {
                                start = false;
                                System.out.println(player1.name + " a castigat!");
                                player1.playerPoints = b.countTokens;
                                break;
                            } else {
                                System.out.println(player2.name + " a castigat!");
                                player2.playerPoints = b.countTokens;
                                break;
                            }


                    }
                    } else{
                        System.out.println("S-au terminat cartonasele.Nu avem un castigator.");
                        break;
                    }

            } else  {
                if((player2.countPlayer2<prog)&&(countCartonase<= b.countTokens)) {
                    System.out.println("E randul lui : "+ player2.name + "\n");
                    player2Count = player2.countPlayer1;
                    int command = GameDetails();
                    switch (command) {
                        case 4:
                            System.exit(0);
                        case 3:
                        case 2:
                            System.out.println(player2Count);
                        case 1:
                            if (player2.countPlayer2 < prog) {
                                object2.run();
                                turn = 1;
                                countCartonase++;
                                System.out.println("Pana acum s-au extras " + countCartonase + " cartonase. " + "\n");
                            } else if (player2.countPlayer2 == k) {
                                start = false;
                                System.out.println(player2.name + " a castigat!");
                                player2.playerPoints = b.countTokens;
                            } else {
                                System.out.println(player1.name + " a castigat!");
                                player1.playerPoints = b.countTokens;
                            }
                    } }else{
                        System.out.println("S-au terminat cartonasele. Nu avem un castigator.");
                        break;
                    }

                }
            }

        }





    public int GameDetails() throws IOException {

        System.out.println("1.Alege random o carte.");
        System.out.println("2.Arata progresia acumulata.");
        System.out.println("3.Arata scorul.");
        System.out.println("4.Exit");
        System.out.println("Alege o comanda:");
        String command = br.readLine();
        int a=Integer.parseInt(command);
        return a;

    }
}
