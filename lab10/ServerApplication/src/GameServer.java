import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class GameServer {
    public GameServer() {
    }

    public static void main(String[] args) throws IOException {
        ServerSocket ss = new ServerSocket(3000);
        System.out.println("Serverul s-a pornit!");
        System.out.println("Serverul asteapta sa se conecteze utilizatorii...");
        while(true) {
            Socket s = null;

            try {
                s = ss.accept();
                System.out.println("S-a conectat jucatorul " + s);
                DataInputStream dis = new DataInputStream(s.getInputStream());
                DataOutputStream dos = new DataOutputStream(s.getOutputStream());

                Thread t = new ClientThread(s, dis, dos);
                t.start();

            } catch (Exception e) {
                s.close();
                e.printStackTrace();
            }
        }
    }
}

