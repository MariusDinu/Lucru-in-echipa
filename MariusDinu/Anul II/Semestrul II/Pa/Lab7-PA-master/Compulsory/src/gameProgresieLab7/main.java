package gameProgresieLab7;

import gameProgresieLab7.GameInputProgresie;
import gameProgresieLab7.PlayerProgresie;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;

public class main {
    public static void main(String args[]) throws IOException {


        InputStreamReader isr = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);

        /*aici avem toate detaliile jocului introduse de la tastatura*/
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


        BoardProgresie board = new BoardProgresie(cartonase, valMax); /*am creat tabla de joc cu numarul de tokenuri si valoare lor maxim*/


        board.setListToken(); /*am creat lista cu tokenuri*/
        Collections.sort(board.listToken,new comparatorSort()); /*o sortam folosind comparatorul definit in clasa compartorSort dupa valoarea random*/
        PlayerProgresie player1 = new PlayerProgresie(numePlayer1, board, 1); /*am creat playerul 1*/
        PlayerProgresie player2 = new PlayerProgresie(numePlayer2, board, 2); /*am creat playerul 2*/
        /*Game game=new Game(player1,player2,valProg,board); */
        /*Aici am tot un joc, dar am gresit cerintele. In loc de progresie face suma. Cine ajunge primul mai aproape de suma respectiva castiga.*/
        /*jocul asta se gaseste in gameLab7 si ca sa nu incep de la zero am preferat sa copiez si sa redenumesc */

        GameInputProgresie game= new GameInputProgresie(player1,player2,valProg,board);  /*cream jocul*/



        /*GameInputProgresie2 game = new GameInputProgresie2(player1, player2, valProg, board);*/ /*Aici am incercat varianta cu threaduri*/
        /*am incercat ceva la threaduri,jocul merge,dar firele de executie imi merg simultan si nu ma lasa sa introduc datele,pentru primul player merge dar pentru al doilea imi da eroare  */
        /*GameInputProgresie2 e pentru threaduri */
        /* GameInputProgresie e pentru varianta de Runnable*/
        /* eu in jocul meu folosesc run care imi permite sa o rulez de cate ori vreau */
    }
}