/*package gameLab7;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class main {

   public static void main(String args[]) throws IOException {


        InputStreamReader isr = new InputStreamReader(System.in);
       BufferedReader br = new BufferedReader(isr);


       System.out.println("Alege un nume player 1:");
       String numePlayer1 = br.readLine();
       System.out.println("Alege un nume player 2:");
       String numePlayer2 = br.readLine();
       System.out.println("Alege un numar de cartonase:");
       String s1 = br.readLine();
       int cartonase = Integer.parseInt(s1);
       System.out.println("Alege valoarea maxima a cartonaselor:");
       String s2 = br.readLine();
       int valMax = Integer.parseInt(s2);
       System.out.println("Alege valoarea progresiei:");
       String s3 = br.readLine();
       int valProg = Integer.parseInt(s3);



      gameProgresieLab7.Board board=new Board(cartonase,valMax);
      board.setListToken();
      System.out.println(board.getListToken().toString().);
      Player player1=new Player(numePlayer1,board,1);
      Player player2=new Player(numePlayer2,board,2);
      //Game game=new Game(player1,player2,valProg,board);
       GameInput game= new GameInput(player1,player2,valProg,board);




   }
    }*/
