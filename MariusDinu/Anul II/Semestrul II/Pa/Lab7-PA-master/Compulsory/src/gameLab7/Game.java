package gameLab7;

import gameLab7.Board;

public class Game {
    Player playerFirst;
    Player playerSecond;
    gameLab7.Board b;
    Thread object1;
    Thread object2;
    int k;
    int player1Count=0;
    int player2Count=0;
    public Game(){}

    public Game(Player player1, Player player2, int k, Board board)
    {    playerFirst=player1;
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


                if((player1.countPlayer1<prog)&&(countCartonase<= b.countTokens))
                {
                    object1.run();
                    if(player1.countPlayer1<prog) {
                        turn=2;
                         countCartonase++; System.out.println("Pana acum s-au extras "+countCartonase+" cartonase. "+"\n");
                    }
                    else if(player1.countPlayer1==prog){
                            start=false;
                        System.out.println(player1.name+ " a castigat!");
                        player1.playerPoints=b.countTokens;
                    break;}
                    else {
                        System.out.println(player2.name+" a castigat!");
                      player2.playerPoints=b.countTokens;
                    break;}
                } else {System.out.println("S-au terminat cartonasele.Nu avem un castigator.");break;}

            } else  {
                if((player2.countPlayer2<prog)&&(countCartonase<= b.countTokens))
                {
                    if(player2.countPlayer2<prog) {object2.run();
                        turn=1;
                     countCartonase++;System.out.println("Pana acum s-au extras "+countCartonase+" cartonase. "+"\n");
                         } else if(player2.countPlayer2==k){
                        start=false;
                        System.out.println(player2.name+ " a castigat!");
                        player2.playerPoints=b.countTokens;}
                    else {System.out.println(player1.name+" a castigat!");
                    player1.playerPoints=b.countTokens;}}else {System.out.println("S-au terminat cartonasele. Nu avem un castigator.");break;}

            }

        }


    }

}
