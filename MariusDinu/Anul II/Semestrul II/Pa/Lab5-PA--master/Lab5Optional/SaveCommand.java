import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class SaveCommand {

    private  Catalog catalog;

    public SaveCommand( ) {
    }
    public void saveCatalog(Catalog catalog) throws IOException {
        FileOutputStream fileOut = new FileOutputStream("d:/catalog_class_command.ser");
        ObjectOutputStream out = new ObjectOutputStream(fileOut);
        out.writeObject(catalog);
        out.close(); //inchidem streamul
        fileOut.close();
        System.out.printf("Serialized data is saved in d:/catalog_class_command.ser with Save Command ! \n");
    }
}
