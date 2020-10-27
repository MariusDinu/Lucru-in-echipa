import sun.awt.DesktopBrowse;

import java.awt.*;
import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.Date;

import static java.awt.Desktop.Action.BROWSE;

public class CatalogUtil {
    public static void save(Catalog catalog) throws IOException {
        FileOutputStream fileOut = new FileOutputStream("d:/catalog4.ser");
        ObjectOutputStream out = new ObjectOutputStream(fileOut);
        out.writeObject(catalog);
        out.close(); //inchidem streamul
        fileOut.close();
        System.out.printf("Serialized data is saved in /catalog4.ser");

        }
    public static Catalog load(String path) throws IOException, ClassNotFoundException {
        Catalog catalog2=null;
            FileInputStream fis = new FileInputStream(path);
            ObjectInputStream in = new ObjectInputStream(fis);
            catalog2 = (Catalog) in.readObject(); // am facut cast la Catalog pentru a putea copia datele
            in.close(); //inchidem streamul
            fis.close();
        System.out.printf("Serialized data from /catalog4.ser");
        return catalog2; //returnam toate datele din catalogul importat
    }


    public static void view(Document doc) throws URISyntaxException, IOException {
        URI url= new URI (doc.getLocatie()); //am importat java.net.uri pentru a crea url de tip URI
        Desktop d = Desktop.getDesktop();
        d.browse(url); //accesam acel url primit ca parametru
    }

}
