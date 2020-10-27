package Lab5;

import java.awt.*;
import java.io.*;
import java.net.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.attribute.BasicFileAttributes;

import Exception.*;
public class CatalogUtil {
    private static final String USER_AGENT ="Chrome" ;

    public static void save(Catalog catalog) throws IOException {
        FileOutputStream fileOut = new FileOutputStream("d:/catalog_ser.ser");
        ObjectOutputStream out = new ObjectOutputStream(fileOut);
        out.writeObject(catalog);
        out.close(); //inchidem streamul
        fileOut.close();
        System.out.printf("Serialized data is saved in d:/catalog_ser.ser ! \n");

        }
    public static Catalog load(String path) throws IOException, ClassNotFoundException {
        Catalog catalog2=null;
            FileInputStream fis = new FileInputStream(path);
            ObjectInputStream in = new ObjectInputStream(fis);
            catalog2 = (Catalog) in.readObject(); // am facut cast la Lab5.Catalog pentru a putea copia datele
            in.close(); //inchidem streamul
            fis.close();
        System.out.printf("Serialized data from d:/catalog_ser.ser! \n");
        return catalog2; //returnam toate datele din catalogul importat
    }
    public static void view(Document doc) throws URISyntaxException, IOException, InvalidUrlException {
        URI url= new URI (doc.getLocatie()); //am importat java.net.uri pentru a crea url de tip URI
        if(CatalogUtil.validationUrl(doc.getLocatie()))
        {
            Desktop d2 = Desktop.getDesktop();
            d2.browse(url); //accesam acel url primit ca parametru
        }
        else{ throw new InvalidUrlException() ;}}
    public static void view(String str) throws URISyntaxException, IOException, InvalidUrlException {
        URI url= new URI (str); //am importat java.net.uri pentru a crea url de tip URI
        if(CatalogUtil.validationUrl(str))
        {
            Desktop d2 = Desktop.getDesktop();
            d2.browse(url); //accesam acel url primit ca parametru
        }
        else{ throw new InvalidUrlException();}
    }

    public static void list(String path) throws IOException, ClassNotFoundException {
        Catalog catalog2=null;
        FileInputStream fis = new FileInputStream(path);
        ObjectInputStream in = new ObjectInputStream(fis);
        catalog2 = (Catalog) in.readObject(); // am facut cast la Lab5.Catalog pentru a putea copia datele
        in.close(); //inchidem streamul
        fis.close();
        System.out.println("List ");
        System.out.println( catalog2.getDocuments());
    }

    public static void savePlainText(Catalog catalog) {
        try(Writer writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("d:/catalog_plain_text.txt"), "UTF-8")))
        {
            writer.write(catalog.toString());
        }
        catch(IOException ex)
        {
            ex.printStackTrace();
        }
        System.out.println("Saved in plain text!");
    }
    public static void loadPlainText (String path) {
        try(BufferedReader br = new BufferedReader(new FileReader(path)))
        {
            String line =null ;
            while ((line = br.readLine()) != null)
            {
                System.out.println(line);
            }
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static boolean validationUrl(String url){
     try {
         URL obj = new URL(url);
         obj.toURI();
         return true;
     } catch (MalformedURLException e) {
         return false;
     } catch (URISyntaxException e) {
         return false;
     }
 }

    public static void reportHtml(String path) throws IOException, ClassNotFoundException {
        System.out.println("Create html!");
        Catalog catalog;
        catalog=CatalogUtil.load("d:/catalog_ser.ser"); //incarc catalogul deja salvat si cu documentele adaugate
        String msg=catalog.getDocuments().toString();
        String words[]=msg.split("}, "); // separ documentele in string-uri diferite

        File html=new File("d:/report.html");
        try {
            BufferedWriter writer= new BufferedWriter(new FileWriter(html));
            for(String word:words) //pentru fiecare cuvant din lista separata de "},"
            { writer.write("<div>"+"<p>"+word+"</p>"+"</div>"); // am folosit div si p pentru un aspect mai placut
                writer.newLine();} //se face un new line in fisier (doar daca il deschid cu notepad), ca sa pot adauga un rand in html am folosit div si p
            writer.close();


        } catch (IOException e) {
            e.printStackTrace();
        }
     System.out.println("You have the html!");
    }

    public static void info(Path loc) throws IOException {
        Path file =loc; //adaugam calea primita ca parametru
        BasicFileAttributes attr = Files.readAttributes(file, BasicFileAttributes.class); //afiseaza atributele suportate de toate fisierele din sistem

        System.out.println("creationTime: " + attr.creationTime());
        System.out.println("lastAccessTime: " + attr.lastAccessTime());
        System.out.println("lastModifiedTime: " + attr.lastModifiedTime());
        System.out.println("isDirectory: " + attr.isDirectory());
        System.out.println("isOther: " + attr.isOther());
        System.out.println("isRegularFile: " + attr.isRegularFile());
        System.out.println("isSymbolicLink: " + attr.isSymbolicLink());
        System.out.println("size: " + attr.size());
     //afisam metadatele
    }
}
