import java.io.IOException;
import java.net.URISyntaxException;
import java.util.Objects;

import static java.util.Objects.requireNonNull;

public class Main {

        public static void main(String args[]) throws InvalidCatalogException, IOException, URISyntaxException, ClassNotFoundException {
            Main app = new Main();
            app.testCreateSave();
            app.testLoadView();
        }

        private void testCreateSave() throws IOException {
            Catalog catalog =
                    new Catalog("Java Resources", "d:/catalog4.ser");
            Document doc = new Document("123", "JavaCourse1",
                    "https://profs.info.uaic.ro/~acf/java/slides/en/intro_slide_en.pdf");
            doc.addTag("type", "Slides");
            catalog.add(doc);

            CatalogUtil.save(catalog);
            System.out.println();
        }

        private void testLoadView() throws IOException, ClassNotFoundException,NullPointerException, URISyntaxException {
            Catalog catalog;
            catalog = CatalogUtil.load("d:/catalog4.ser"); //accesam documentul cu toate datele

            Document doc2 = catalog.findById("123"); // se alege documentul cu id-ul specific

            CatalogUtil.view(doc2); // se vizualizeaza in browserul implicit al pc-ului
        }
    }