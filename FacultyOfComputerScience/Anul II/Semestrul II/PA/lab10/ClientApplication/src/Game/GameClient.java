package Game;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class GameClient {


    public static void main(String[] args) throws IOException {
        try {
            Scanner scn = new Scanner(System.in);

            /*initializam ip-ul si portul serverului la care vrem sa ne conectam*/
            String ip = "localhost";
            int port = 3000;
            /*stabilim conexiunea la portul initializat si la adresa ip*/
            Socket s = new Socket(ip, port);

            // obtaining input and out streams
            DataInputStream dis = new DataInputStream(s.getInputStream());
            DataOutputStream dos = new DataOutputStream(s.getOutputStream());

            /*avem un loop care ne ajuta sa preluam mesajele de la server si comenzile de la client pana clientul inchide conexiunea*/
            loop:
            while (true) {
                System.out.println(dis.readUTF());  /*primim mesajul de la server unde se vor afisa toate comenzile */
                String toSend = scn.nextLine();  /*citim de la tastatura comanda*/
                dos.writeUTF(toSend);   /*o trimitem la server dar ramane salvata si in toSend*/

                /*verificam daca e Exit si atunci se va inchide clientul*/
                if (toSend.equals("Exit")) {
                    s.close();  /*inchidem conexiunea la server*/
                    System.out.println("Conexiune inchisa!");
                    System.out.println("Client inchis!");
                    break;  /*inchidem clientul desi consider ca System.exit(0) e mai util*/
                }


                String received;  /*primim raspunsul de la server */
                switch (toSend) {
                    case "Stop":  /*daca raspunsul e stop atunci serverul se va opri*/
                        received = dis.readUTF();
                        System.out.println(received);
                        break loop;
                    case "Create":
                        received = dis.readUTF();
                        System.out.println(received);
                        break;  /*verificam daca e create si vom crea o camera de joc */
                    case "Join":
                        String received2 = dis.readUTF();
                        System.out.println(received2);
                        break;  /*verificam daca e join si vom intra intr-o camera de joc*/
                    case "Move":
                        String[][] cde = new String[8][8];
                        /*copiem in cde ce am primit de la server*/
                        for (int i = 0; i < 8; i++) {
                            for (int j = 0; j < 8; j++) {
                                received = dis.readUTF();
                                cde[i][j] = received;
                            }
                        }

                        for (int i = 0; i < 8; i++) {
                            /*afisam ce am copiat in cde*/
                            for (int j = 0; j < 8; j++) {
                                if (j <= 6) {
                                    if (cde[i][j].equals("W") || cde[i][j].equals("B")) {
                                        System.out.print(' ' + cde[i][j] + ',');
                                    } else {
                                        if (Integer.valueOf(cde[i][j]) <= 9)
                                            System.out.print(' ' + cde[i][j] + ',');
                                        else
                                            System.out.print(cde[i][j] + ',');
                                    }
                                } else
                                    System.out.print(cde[i][j] + "\n");
                            }
                        }
                        received = dis.readUTF();
                        System.out.println(received);   /*primim mesajul legat de pozitia pe care o vom alege*/
                        String sendStringInt = scn.nextLine();
                        dos.writeUTF(sendStringInt);  /*trimitem pozitia catre server*/
                        break;
                    /*verificam daca e move si vom realiza o mutare*/

                    default:
                        System.out.println("Comanda invalida!");
                        break; /*afisam doar daca comanda nu se afla in cele de mai sus*/
                }


            }/*inchidem citirea si trimirea mesajelor catre server si citirea de la tastatura*/
            scn.close();
            dis.close();
            dos.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


