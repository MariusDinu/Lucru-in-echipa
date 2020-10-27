import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;

public class LoadCommand {

    public LoadCommand() {
    }

    public static Catalog loadCatalog(String path) throws IOException, ClassNotFoundException {
        Catalog catalog2=null;
        FileInputStream fis = new FileInputStream(path);
        ObjectInputStream in = new ObjectInputStream(fis);
        catalog2 = (Catalog) in.readObject(); // am facut cast la Catalog pentru a putea copia datele
        in.close(); //inchidem streamul
        fis.close();
        System.out.printf("Serialized data from d:/catalog_ser.ser! with Load Command \n");
        return catalog2; //returnam toate datele din catalogul importat
    }
}
