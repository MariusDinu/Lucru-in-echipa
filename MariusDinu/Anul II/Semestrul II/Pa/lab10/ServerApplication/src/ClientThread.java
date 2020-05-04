import java.io.*;
import java.net.Socket;
import java.util.Date;

class ClientThread extends Thread {
    final DataInputStream dis;
    final DataOutputStream dos;

    int turn = 1;
    final Socket s;
    Game game = new Game();

    public ClientThread(Socket s, DataInputStream dis, DataOutputStream dos) throws IOException {
        this.s = s;
        this.dis = dis;
        this.dos = dos;

    }

    @Override
    public void run() {


        while (true) {
            try {
                this.dos.writeUTF("Comenzi[Exit/Stop/Create/Join/Move]..\n"); /* Se afiseaza dupa utilizarea fiecarei comenzi*/
                String received = this.dis.readUTF();  /**/
                String toreturn;

                if (received.equals(("Exit"))) {  /*Daca e egal cu Exit*/
                    System.out.println("S-a deconectat " + this.s);  /*Se afiseaza mesajul in consola serverului!*/
                    this.s.close();  /*se inchide conexiunea cu socketul*/

                    break;
                }
                if (received.equals("Stop")) {
                    System.out.println("Playerul " + this.s + " incearca sa opreasca conexiunea...\n");  /*Se afiseaza cateva mesaje informative despre inchiderea conexiunii*/
                    System.out.println("Se inchide conexiunea\n");
                    toreturn = "S-a oprit serverul!\n";
                    this.dos.writeUTF(toreturn);  /*Se returneaza mesajul catre client inainte de inchiderea socketului*/
                    this.s.close();  /*se inchide socketul*/
                    System.out.println("Conexiune inchisa!\n");  /*si se afiseaza un mesaj in consola serverului*/
                    System.exit(0);
                    break;

                }


                if (received.equals("Create")) {
                    Player player1 = new Player();  /*cream un player*/
                    player1.name = "player1";     /*ii setam numele, prin apelul constructorului de mai sus se initializeaza punctele si numarul de mutari cu 0*/

                    game.gameCreate(player1);  /*cream o camera pentru primul jucator*/
                    game.b.countplayers = 1;  /*numarul de playeri din camera*/
                    toreturn = "Create: S-a creat camera cu id 1!\n";
                    System.out.println("Create: S-a creat camera cu id 1!\n");
                    System.out.println(currentThread() + "Create: Esti in camera cu id 1!");
                    this.dos.writeUTF(toreturn);  /*returnam mesajul catre client*/
                    dos.flush();

                }
                if (received.equals("Join")) {
                    Player player2 = new Player();  /*cream al doilea player deoarece nu poate da join fara sa fie creata camera*/
                    player2.name = "player2";   /*ii setam numele*/
                    game.b.countplayers++;  /*incrementam numarul de playeri din camera*/
                    game.joinGame(player2);  /*il adaugam la camera */
                    System.out.println(" Join: Ai intrat in camera cu id 1! \n");
                    if (game.b.countplayers == game.b.players) {  /*Daca numarul de playeri e ok dam drumul la joc*/
                          /*  for (int i = 2; i < 10; i++) {
                                this.dos.writeUTF("Incepe jocul in " + (10 - i) + " secunde!");
                            } am incercat o afisare a unui cronometru pana la inceperea jocului  */
                        this.dos.writeUTF("Jocul a inceput");
                        dos.flush();  /*trimitem un mesaj cum ca jocul a inceput*/
                            /*
                            this.dos.writeUTF("a");*/

                    } else
                        System.out.println("Mai asteptam playeri");  /*sau afisam ca nu sunt destui playeri in camera*/
                }

                if (received.equals("Move")) {
                    String[][] abc = game.b.showBoardString();  /*copiem toate valorile de pe tabla de joc in abc*/

                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++)
                            this.dos.writeUTF(abc[i][j]);  /*si le trimitem ca mesaj catre client pentru a vedea o tabla si a vedea unde pune piesele*/
                    }

                    toreturn = "Move: Alege pozitia";
                    this.dos.writeUTF(toreturn);  /*returnam un mesaj catre client pentru a putea alege pozitia*/
                    String position = dis.readUTF();  /*primim pozitia */

                    turn = game.moveGame(position, turn);  /*modificam din numar intr-un simbol*/


                    System.out.println("Move: A facut o mutare!");  /*afisam un mesaj pe consola de la server*/


                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        try {
            this.dis.close();
            this.dos.close();
        } catch (IOException var6) {
            var6.printStackTrace();
        }

    }


}



