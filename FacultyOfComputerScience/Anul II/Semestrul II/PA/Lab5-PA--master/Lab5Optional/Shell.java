import java.io.*;
import java.net.URISyntaxException;
import Exception.*;
public class Shell {


    public static void main(String[] args) throws
            java.io.IOException, ClassNotFoundException, URISyntaxException, InvalidUrlException, InvalidCommandException {

        String commandLine;
        BufferedReader console = new BufferedReader
                (new InputStreamReader(System.in));

        String comanda;String pathComanda;
        while (true) {
          //citim linia
            System.out.print("shell>");
            commandLine = console.readLine();
            System.out.println("Lungimea comenzii:");
            System.out.println(commandLine.length());//afisam lungimea comenzii

           String words[]=commandLine.split(" ");
           comanda=words[0];  System.out.println("Comanda:");System.out.println(comanda);//afisam comanda
           pathComanda=words[1];  System.out.println("Path:");System.out.println(pathComanda);  // afisam localizarea fisierului sau url-ul


            switch(comanda) {
                case "load": Catalog catalog=null;
                    catalog = CatalogUtil.load(pathComanda); //accesam documentul cu toate datele
                    break;
                case"list":
                    CatalogUtil.list(pathComanda);//afiseaza lista de documente
                    break;
                case"view":
                    CatalogUtil.view(pathComanda); // se vizualizeaza in browserul implicit al pc-ului
                    break;
                case"reportHtml":
                    CatalogUtil.reportHtml(pathComanda);//se face un raport afisat pe un nou html
                    break;
                default:
                    throw new InvalidCommandException(); //se prinde acest Exception ca sa aratam ca comanda primita de la tastatura e gresita
                                                         // iar daca e gresit path-ul se primeste FileNotFoundException
            }
        }

    }
}