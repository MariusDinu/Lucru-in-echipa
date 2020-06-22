package Lab5;

import java.io.IOException;
import java.net.URISyntaxException;
import java.nio.file.Paths;

import Exception.*;

import static java.util.Objects.requireNonNull;

public class Main {



    public static void main(String args[]) throws InvalidCatalogException, IOException, URISyntaxException, ClassNotFoundException, InvalidNameDocException, InvalidNotFoundDocException, InvalidUrlException {
            Main app = new Main();
            app.testCreateSave();
            app.testLoadView();

        }

        private void testCreateSave() throws InvalidNameDocException, IOException, IllegalArgumentException, ClassNotFoundException, URISyntaxException, InvalidUrlException {
//creez catalogul
            Catalog catalog =
                    new Catalog("Java", "d:/catalog_ser.ser");
//declaram si initializam documentele
                Document doc1 = new Document("1", "JavaCourse1",
                        "https://profs.info.uaic.ro/~acf/java/slides/en/intro_slide_en.pdf");
                Document doc2 = new Document("2", "JavaCourse1",
                        "https://profs.info.uaic.ro/~acf/java/slides/en/intro_slide_en.pdf");
                Document doc3 = new Document("2", "JavaCourse1",
                        "https://profs.info.uaic.ro/~acf/java/slides/en/intro_slide_en.pdf");
                Document doc4 = new Document("2", "JavaCourse1",
                        "https://profs.info.uaic.ro/~acf/java/slides/en/intro_slide_en.pdf");
                Document doc5 = new Document("3", "JavaCourse1",
                        "tps://profs.info.uaic.ro/~acf/java/slides/en/intro_slide_en.pdf");
//aici adaugam la 2 documente taguri
                doc1.addTag("type", "Slides");
                doc3.addTag("type","Slides");
            //doc si doc2 au id-uri diferite deci sunt fisiere diferite
            //doc3 si doc4 sunt diferite, fiindca doc 3 contine tags
            //doc4 si doc5 sunt la fel
//aici adaugam documentele in catalog
            catalog.add(doc1);
            catalog.add(doc2);
            catalog.add(doc3);
            catalog.add(doc5);
            //catalog.add(doc4); //daca se va scoate din comentariu comanda aceasta se va afisa un exception legat de faptul ca exista deja un doc cu datele acestea,doc2 si doc4 sunt la fel

//aici salvam catalogul in 2 extensii, SER si TXT , respectiv SALVARE SERIALIZABLE si SALVARE PLAIN TEXT
            CatalogUtil.save(catalog);//salvarea catalogului folosind object serialization
            CatalogUtil.savePlainText(catalog);//salvarea catalogului folosind plain text

//aici folosim clasele pentru comenzi

                SaveCommand save = new SaveCommand(); // creez obiectul save de tip Lab5.SaveCommand
                save.saveCatalog(catalog);  //salvam catalogul

                LoadCommand load = new LoadCommand(); //creez obiectul load de tip Lab5.LoadCommand
                String pathCatalogLoadCommand = "d:/catalog_class_command.ser"; //
                load.loadCatalog(pathCatalogLoadCommand); //incarcam si afisam catalogul

                ViewCommand view = new ViewCommand(); //creez obiectul view de tip Lab5.ViewCommand
                view.viewCatalog(doc2); //deschidem in browser linkul de pe doc2

                ListCommand list = new ListCommand(); //creez obiectul list de tip Lab5.ListCommand
                list.listCommandCatalog("d:/catalog_class_command.ser"); //afisam lista de documente din catalog
//Afiseaza medadatele
                 System.out.println("Info about your file:");
                 CatalogUtil.info(Paths.get("d:/catalog_class_command.ser"));

        }

        private void testLoadView() throws IOException, ClassNotFoundException, NullPointerException, URISyntaxException, InvalidNotFoundDocException, InvalidUrlException {
            Catalog catalog;

            catalog = CatalogUtil.load("d:/catalog_ser.ser"); //accesam documentul cu toate datele
            CatalogUtil.reportHtml("d:/catalog_ser.ser");
            //Lab5.CatalogUtil.loadPlainText("d:/catalog_plain_text.txt"); //incarca si afiseaza textul preluat din path

            Document doc2 = catalog.findById("1"); // se alege documentul cu id-ul specific
            Document doc5 = catalog.findById("3"); // se alege documentul doc5 pentru a demonstra ca linkul din acest document nu este accesibil
            //Lab5.Document doc4 = catalog.findById("5"); // se prinde InvalidNotFoundDocException care arata ca nu exista documentul in catalog

            CatalogUtil.view(doc2); // se vizualizeaza in browserul implicit al pc-ului
            CatalogUtil.view("https://profs.info.uaic.ro/~acf/java/slides/en/intro_slide_en.pdf"); // se vizualizeaza in browserul implicit un link
           // Lab5.CatalogUtil.view(doc5); //se prinde InvalidUrlExcception si apare eroare legata de faptul ca nu este un link corect

            CatalogUtil.list("d:/catalog_ser.ser"); //primeste un path si afiseaza detalii despre documentele din catalog



        }


    }