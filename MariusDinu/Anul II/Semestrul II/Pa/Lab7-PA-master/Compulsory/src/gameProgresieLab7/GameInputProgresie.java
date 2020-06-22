package gameProgresieLab7;

import gameProgresieLab7.BoardProgresie;

import java.io.BufferedReader;
import java.io.Console;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;

public class GameInputProgresie {
    gameProgresieLab7.BoardProgresie b; /*am creat o tabla in care vom avea o copie a tablei originale*/
    Thread object1;
    Thread object2;
    int player1Count=0; /*va tine scorul jucatorului 1*/
    int player2Count=0; /*va tine scorul jucatorlui 2*/
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);

    public GameInputProgresie(){}

    public GameInputProgresie(PlayerProgresie player1, PlayerProgresie player2, int k, BoardProgresie board) throws IOException {

        b=board; /*cppiem in b ce aveam in tabla originala*/
        int turn =1; /*tura este inceputa de primul jucator*/
        boolean start=true; /*reprezinta inceperea si oprirea jocului*/
        int prog=k; /*progresia ceruta de sistem, adica daca progresia e 5 jucatorii vor avea nevoie de 5 tokenuri ca sa castige*/
        int countCartonase = 0; /*va tine un count alt cartonaselor extrase in tot meciul*/
        object1 = new Thread(new PlayerProgresie(player1.name,b,1));
        object2 = new Thread(new PlayerProgresie(player2.name,b,2));


        while(start) {

            if (turn == 1) { /* daca este randul primului jucator exetucam acest bloc*/

                if(countCartonase< b.countTokens/2) {   /*daca nu s-au terminat cartonasele executam acest bloc*/

                    System.out.println(board.getListToken().toString()); /*afisam lista cu tokenurile disponibile*/
                    System.out.println("E randul lui : "+ player1.name+"\n"); /*afisam randul cui trebuie sa aleaga */
                    player1Count=player1.countPlayer1;
                    int command = GameDetails();   /*afisam comenzile dispobinile*/
                    switch (command) {  /*folosim un case pentru comenzile de mai sus */
                        case 4:
                            System.exit(0);  /*iesim */
                        case 3:
                            if(player1Count<player2Count)  /*daca playerul vede ca nu mai are carti disponibile pentru el se va stabili castigatoul dar nu se va pune ca si cum s-ar da batut */
                            {
                            System.out.println(player2.name+" a castigat!");
                            Final(player1,player2);
                            break;}
                            else if(player1Count==player2Count)
                            {   System.out.println("Remiza");
                                player1.playerPoints=player1Count;
                                player2.playerPoints=player2Count;
                                Final(player1,player2);
                            break;}
                            else {
                            System.out.println(player1.name+" a castigat!");
                            Final(player1,player2);
                            break;}
                        case 2:
                            System.out.println(player1.name+" ai acumulat "+player1Count+" puncte."); /*afisam numarul de tokenuri acumulate*/
                        case 1:
                            /* apelam run ca sa extragem carti*/
                            object1.run();
                            if (player1.countPlayer1 < prog) {
                                turn = 2;
                                countCartonase++;
                                System.out.println("Progresia este: "+prog);
                                System.out.println("Pana acum s-au extras " + countCartonase + " cartonase. " + "\n");
                                waitForEnter(); /*incheiem in siguranta extragerea */

                            } else if (player1.countPlayer1 == prog) {  /* daca avem deja progresia ceruta inseamna ca avem un castigator*/
                                start = false;
                                System.out.println(player1.name + " a castigat!");
                                player1.playerPoints = b.countTokens;
                                Final(player1,player2);
                                break;
                            } else {   /*daca are mai multe carti decat cele cerute a pierdut*/
                                System.out.println(player2.name + " a castigat!");
                                player2.playerPoints = b.countTokens;
                                Final(player1,player2);
                                break;
                            }


                    }
                } else /*executam acest bloc daca tokenurile s-au terminat si afisam scoreboardul si reglam punctele*/
                    {
                    System.out.println("S-au terminat cartonasele.");
                    if(player1Count<player2Count)
                    { System.out.println(player2.name+" a castigat!");}
                    else if(player1Count==player2Count)
                    { System.out.println("Remiza");
                    player1.playerPoints=player1Count;
                    player2.playerPoints=player2Count;}
                    else {System.out.println(player1.name+" a castigat!");}
                    break;
                }

            } else  /*executam acest bloc daca este randul celui de-al doilea jucator*/ {
                if(countCartonase<= b.countTokens/2) {

                    System.out.println(board.getListToken().toString());  /*afisam lista cu tokenuri */
                    System.out.println("E randul lui : "+ player2.name + "\n"); /*afisam a cu ieste randul*/
                    player2Count = player2.countPlayer2;
                    int command = GameDetails();
                    switch (command) {
                        case 4:
                            System.exit(0); /*iesire */
                        case 3:   /*daca playerul vede ca nu mai are cu ce sa continue se stabileste castigatorul dintre jucatori */
                            if(player1Count<player2Count)
                            {
                                System.out.println(player2.name+" a castigat!");
                                Final(player1,player2);
                                break;}
                            else if(player1Count==player2Count)
                            {
                                System.out.println("Remiza");
                                player1.playerPoints=player1Count;
                                player2.playerPoints=player2Count;
                                Final(player1,player2);
                                break;}
                            else {
                                System.out.println(player1.name+" a castigat!");
                                break;}
                        case 2:
                            System.out.println(player2Count); /*afisam cate carti are*/
                        case 1:
                            if (player2.countPlayer2 < prog) {
                                object2.run();
                                turn = 1;
                                countCartonase++;
                                System.out.println("Pana acum s-au extras " + countCartonase + " cartonase. " + "\n");
                                waitForEnter(); /*inchidem in siguranta tura*/
                            } else if (player2.countPlayer2 == prog) { /*daca player 2 a ajuns la numarul exact de carti cerute de progresie a castigat*/
                                start = false;
                                System.out.println(player2.name + " a castigat!");
                                player2.playerPoints = b.countTokens;
                                Final(player1,player2);
                                break;
                            } else {
                                System.out.println(player1.name + " a castigat!");
                                player1.playerPoints = b.countTokens;
                                Final(player1,player2);
                                break;
                            }
                    } }else{
                    System.out.println("S-au terminat cartonasele.");
                    if(player1Count<player2Count)
                    {
                        System.out.println(player2.name+" a castigat!");
                        Final(player1,player2);
                        break;
                    }
                    else if(player1Count==player2Count)
                    {
                        System.out.println("Remiza");
                        player1.playerPoints=player1Count;
                        player2.playerPoints=player2Count;
                        Final(player1,player2);
                          break;}
                    else {
                        System.out.println(player1.name+" a castigat!");
                        Final(player1,player2);
                        break;}

                }

            }
        }

    }




    /*aici avem optiunile din timpul jocului*/
    public int GameDetails() throws IOException {

        System.out.println("1.Alege o carte.");
        System.out.println("2.Arata progresia acumulata.");
        System.out.println("3.Nu mai exista carti pentru mine.");
        System.out.println("4.Exit");
        System.out.println("Alege o comanda:");
        String command = br.readLine();
        int a=Integer.parseInt(command);
        return a;

    }
    /*aici avem un scoreboard final*/
    public void Final(PlayerProgresie player1,PlayerProgresie player2){
        System.out.println("Scoreboard:");

        if(player1.playerPoints<=player2.playerPoints)
        { System.out.println("Player 1 :" +player1.name+" "+player1.playerPoints);
        System.out.println("Player 2 :"+player2.name+" "+player2.playerPoints);}
        else
        { System.out.println("Player 2 :" +player2.name+" "+ player2.playerPoints);
            System.out.println("Player 1 :"+player1.name+" "+ player1.playerPoints);}
    }
    /*iar aici avem o metoda de asteptare prin care stim ca playeri isi asteapta randul*/
    public static void waitForEnter() {
        System.out.println("Apasa Enter ca sa inchei tura!");
        try{System.in.read();}
        catch(Exception e){}
        }
    }



