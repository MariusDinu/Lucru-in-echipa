package lab5;
import java.io.IOException;
import java.net.URISyntaxException;

public class Main {

        public static void main(String args[]) throws InvalidCatalogException, IOException, URISyntaxException, ClassNotFoundException {
            Main app = new Main();
            app.testCreateSave();
            app.testLoadView();
        }

      
//aici testez metodele load view
        private void testLoadView() throws InvalidCatalogException, IOException, ClassNotFoundException, URISyntaxException {
            Catalog catalog = CatalogUtil.load("d:/programe/cat2.ser");
            Document document = catalog.findById("2000");
            CatalogUtil.view(document);
        }
        
        //aici testez metodele seve
        private void testCreateSave() throws IOException {
            Catalog catalog =
                    new Catalog("Java Resources", "d:/programe/cat2.ser");
            Document document = new Document("2000", "JavaCurs1",
                    "https://profs.info.uaic.ro/~acf/java/slides/en/objects_classes_slide_en.pdf");
            document.addTag("type", "Slidur");
            catalog.add(document);

            CatalogUtil.save(catalog);
        }
    }