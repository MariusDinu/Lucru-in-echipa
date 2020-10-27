import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.HashMap;

public class Game {
    public Board b = new Board();
    Player firstPlayer = new Player();
    Player secondPlayer = new Player();
    Socket s;
    DataOutputStream dos;
    HashMap<String, String> gameRoom = new HashMap<String, String>();
    int turn = 1;
    String gamePosition;

    public Game() throws IOException {


    }

    public void gameCreate(Player p) {
        this.firstPlayer = p;
        b.idRoom = "1";
        gameRoom.put(p.name, b.idRoom);
        /*creaza un game(room)*/
    }

    public void joinGame(Player p) {
        this.secondPlayer = p;
        b.idRoom = "1";
        gameRoom.put(p.name, b.idRoom);
        /*adauga jucatorul in game(room)*/
    }

    public int moveGame(String position, int turn) {
        this.gamePosition = position;
        if (turn == 1) {
            /*in functie de tura va modifica piesele de pe pozitiile alese de jucatori*/
            b.setPositionBlack(gamePosition);
            firstPlayer.countMoves++;
            turn = 2;
        } else {
            b.setPositionWhite(gamePosition);
            secondPlayer.countMoves++;
            turn = 1;
        }
        return turn;
    }
}
