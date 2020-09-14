package lab5;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.List; // la fel ca la document, am facut import de clase

public class Catalog implements Serializable {
    private String nm;
    private String path;
    private List<Document> documents = new ArrayList<>();

    public Catalog(String nm, String path) {
        this.nm = nm;
        this.path = path;
    }

    public void add(Document document) {
        documents.add(document);
    }
    public Document findById(String id) {
        for (Document doc : documents) {
            if (doc.getId().equals(id)) {

                return doc;
            }
        }
        return null;
    }

    public String getnm() {
        return nm;
    }

    public void setnm(String nm) {
        this.nm = nm;
    }

    public String getPath() {
        return path;
    }

    public void setPath(String path) {
        this.path = path;
    }

    public List<Document> getDocuments() {
        return documents;
    }

    public void setDocuments(List<Document> documents) {
        this.documents = documents;
    }
}
