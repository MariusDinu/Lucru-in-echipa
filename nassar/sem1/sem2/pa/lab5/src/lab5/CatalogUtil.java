package lab5;
import java.awt.*;
import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.Date;

import static java.awt.Desktop.Action.BROWSE;

public class CatalogUtil {
	
	//aici am creat metoda save iar aici vreau sa mentin o com intre try/cath si throws 
	//The throw keyword will allow you to throw an exception (which will break the execution flow and can be caught in a catch block).
	//The try block will execute a sensitive code which can throw exceptions
	//The catch block will be used whenever an exception (of the type caught) is thrown in the try block
    public static void save(Catalog catalog)
            throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream(catalog.getPath()))) {
            oos.writeObject(catalog);
        }
    }
    //aici am creat metoda load
    public static Catalog load(String path) throws IOException, ClassNotFoundException {
        FileInputStream fis=new FileInputStream( path);
        ObjectInputStream in= new ObjectInputStream(fis);
        Catalog catalog = null;
         catalog=(Catalog)in.readObject();
        System.out.println(in);
        fis.close();
        return catalog;
    }
    
    

//aici am creat metoda view
    public static void view(Document doc) throws URISyntaxException, IOException {
        URI url= new URI ("https://profs.info.uaic.ro/~acf/java/slides/en/objects_classes_slide_en.pdf");
        Desktop desktop = Desktop.getDesktop();
        desktop.browse(url);
    }

}
