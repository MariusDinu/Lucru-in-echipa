import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;

public class ListCommand {
    public ListCommand() {
    }

    public static void listCommandCatalog(String path) throws IOException, ClassNotFoundException {
        Catalog catalog2;
        FileInputStream fis = new FileInputStream(path);
        ObjectInputStream in = new ObjectInputStream(fis);
        catalog2 = (Catalog) in.readObject(); // am facut cast la Catalog pentru a putea copia datele
        in.close(); //inchidem streamul
        fis.close();
        System.out.println("List with List Command!");
        System.out.println( catalog2.getDocuments());
    }
}
