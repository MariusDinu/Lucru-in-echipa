package gameLab7;
import gameLab7.Board;

public class Player implements Runnable{

    gameLab7.Board bPlayer;
    String name;
    int playerPoints;
    static int countPlayer1;
    static int countPlayer2;
    int cartonasPlayer;
    int id;
  public Player(){}



    public Player(String name, Board bPlayer, int id) {
        this.name = name;
        this.bPlayer=bPlayer;
        this.id=id;
    }

    @Override
    public String toString() {
        return "Player{" +
                "name='" + name +
                 +'\'' +
                '}';
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }



    @Override
    public synchronized void run() {
int a;
        cartonasPlayer= bPlayer.getTokenFromBoard();


        if(this.id==1)
        {
            countPlayer1= countPlayer1+cartonasPlayer;
        a= countPlayer1;}
        else
        {
            countPlayer2= countPlayer2+cartonasPlayer;
        a= countPlayer2;}
        System.out.println(this.name+" ai luat cartonasul cu "+ cartonasPlayer);
        System.out.println(this.name+"  suma cartilor este:"+ a);
    }

}
