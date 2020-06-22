package gameProgresieLab7;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class PlayerProgresie implements Runnable {
    InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);
    BoardProgresie bPlayer; /* am creat o tabla comuna pentru jucatori din care vom extrage si elimina tokenuri */
    String name; /*numele jucatorului*/
    TokenProgresie copy; /*un obiect token pentru a copia in el tokenurile curente extrase*/
    int playerPoints; /* punctajul jucatorului*/
    static final List<Integer> nums1 = new ArrayList<Integer>(); /*aici vom retine lista de tokenuri din mana jucatorului 1*/
    static final List<Integer> nums2 = new ArrayList<Integer>(); /*aici vom retine lista de tokenuri din mana jucatorului 2*/
    static int countPlayer2; /*aici vom retine numarul de tokenuri din mana jucatorului 2*/
    static int countPlayer1; /*aici vom retine numarul de tokenuri din mana jucatorului 1*/
    int id; /*avem aici un id pentru a face diferenta intre player 1 si player 2 in timpul rundelor*/

    public PlayerProgresie() {
    }

/*avem aici construcotrul pentru clasa PlayerProgresie*/
    public PlayerProgresie(String name, BoardProgresie bPlayer, int id) {
        this.name = name;
        this.bPlayer = bPlayer;
        this.id = id;
    }


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }


   @Override
    public synchronized void run() {
        System.out.println("Alege cartea:");
        String commandTwo = null;
        try {
            commandTwo = br.readLine();
        } catch (IOException e) {
            e.printStackTrace();
        }
        int index = Integer.parseInt(commandTwo);

        if (this.id == 1) {
            copy = bPlayer.listToken.get(index);
            this.nums1.add(copy.getTokenProgresie());
            bPlayer.listToken.remove(index);
            countPlayer1++;
            System.out.println(this.name + " ai " + this.countPlayer1);
        } else {
            copy = bPlayer.listToken.get(index);
            this.nums2.add(copy.getTokenProgresie());
            bPlayer.listToken.remove(index);
            countPlayer2++;
            System.out.println(this.name + " ai " + this.countPlayer2);
        }

        System.out.println(this.name + " ai luat cartonasul cu " + copy.random);
        if (this.id == 1)
            System.out.println(this.name + " ai urmatoarele carti in mana:" + this.nums1.toString());
        else
            System.out.println(this.name + " ai urmatoarele carti in mana:" + this.nums2.toString());
    }


/*aici am incercat ceva cu threaduri, dar nu a iesit chiar bine de aceea nu stiu daca e ok sa o prezint*/

 /*@Override
    public void run(){
     boolean waitingPlayer1=true;
     boolean waitingPlayer2=false;
     boolean start=true;
     String command=null;
     int turn=1;
     while(start)

     {

            if((this.id==1)&&(turn==1)) {
                System.out.println(bPlayer.getListToken().toString());
                System.out.println("Este tura lui:" + turn + " " + this.name);
                System.out.println("Alege o carte:");
                try {
                    command = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                int index = Integer.parseInt(command);

                copy = bPlayer.listToken.get(index);
                this.nums1.add(copy.getTokenProgresie());
                bPlayer.listToken.remove(index);
                countPlayer1++;
                System.out.println(this.name + " ai " + this.countPlayer1);
                waitingPlayer1 = true;
                waitingPlayer2 = false;
                boolean cards=cards();
                ValidationGame(waitingPlayer1,waitingPlayer2,cards);
                turn = 2;

            }    else
            {
                     System.out.println(bPlayer.getListToken().toString());
                     System.out.println("Este tura lui:"+turn+" "+this.name);
                     System.out.println("Alege o carte:");
                     try {
                         command = br.readLine();
                     } catch (IOException e) {
                         e.printStackTrace();
                     }
                     int index2 = Integer.parseInt(command);
                 copy = bPlayer.listToken.get(index2);
                 this.nums2.add(copy.getTokenProgresie());
                 bPlayer.listToken.remove(index2);
                 countPlayer2++;
                 System.out.println(this.name + " ai " + this.countPlayer2);
                 turn = 1;
                     waitingPlayer2=true;
                     waitingPlayer1=false;
                boolean cards=cards();
                ValidationGame(waitingPlayer1,waitingPlayer2,cards);

         }
     }

 }
 public boolean cards(){
     String command=null;
     boolean valid=true;
     System.out.println("Nu mai exista carti pentru dumneavoastra."+ " 1.Da"+ "2.Nu");
     try {
         command = br.readLine();
     } catch (IOException e) {
         e.printStackTrace();
     }
     int index2 = Integer.parseInt(command);
     switch (index2){
     case 1: valid=true;
     case 2: valid=false;
     }
     return valid;
 }
 public void ValidationGame(boolean waiting1,boolean waiting2, boolean cards)
    {
     if((waiting1)&&(waiting2==false))
     {if(countPlayer1<=bPlayer.countTokens/2)
     { System.out.println("Playerul 1 a castigat!"); System.exit(0);}
     else {System.out.println("Playerul 2 a castigat!");System.exit(0);}}
     else{if(countPlayer2<=bPlayer.countTokens/2)
     { System.out.println("Playerul 1 a castigat!"); System.exit(0);}
     else {System.out.println("Playerul 2 a castigat!");System.exit(0);}}
 }*/

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name +
                +'\'' +
                '}';
    }
}














