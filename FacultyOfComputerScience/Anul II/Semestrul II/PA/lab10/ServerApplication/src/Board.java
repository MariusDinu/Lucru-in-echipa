public class Board {

    public static String white = "W";
    public static String black = "B";
    public static final int players = 2;
    public int countplayers;
    public String[][] matrix = new String[8][8];
    public String position;
    public String idRoom;

    public Board() {  /*constructorul realizeaza o tabla de joc de 8x8 in care se vor pune numerele de la 1 la 64 pentru a alege usor pozitia*/
        int k = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                matrix[i][j] = String.valueOf(k);
                k++;
            }

        }

    }

    public void setPositionWhite(String position) {
        this.position = position;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                if (matrix[i][j].equals(position))
                    matrix[i][j] = white;
            /*va modifica pozitia laeasa cu o piesa alba*/
        }

    }

    public void setPositionBlack(String position) {
        this.position = position;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++)
                if (matrix[i][j].equals(position))
                    matrix[i][j] = black;

        }
        /*va modifica pozitia aleasa cu o piesa neagra*/
    }

    public void verify() {


        /*va verifica daca avem 5 piese pe diagonala,orizontal sau vertical*/
    }

    public void showBoard() {
        for (int i = 0; i < 8; i++) {
            /*va face o afisare a tablei de joc*/
            for (int j = 0; j < 8; j++) {
                if (j <= 6) {
                    if (Integer.valueOf(matrix[i][j]) <= 9)
                        System.out.print(' ' + matrix[i][j] + ',');
                    else
                        System.out.print(matrix[i][j] + ',');
                } else
                    System.out.print(matrix[i][j] + "\n");
            }


        }
    }

    public String[][] showBoardString() {
        return matrix;  /*returneaza matricea pentru a o trimite la client*/
    }
}
