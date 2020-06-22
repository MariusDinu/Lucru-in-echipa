package Lab5;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List; // la fel ca la document, am facut import de clase
import Exception.*;


public class Catalog implements Serializable {
    private String name;
    private String path;
    private List<Document> documents = new ArrayList<>();

    public Catalog(String name, String path) {
        this.name = name;
        this.path = path;
    }



    public void add(Document doc) throws InvalidNameDocException {
        if(documents.contains(doc)){throw new InvalidNameDocException(); //verifica daca documentul exista in catalog,daca exista returneaza exceptia, daca nu exista il adauga in documents
        }
        else
        { documents.add(doc);}
    }
    public Document findById(String id) throws InvalidNotFoundDocException  {
        for (Document doc : documents) {
            if (doc.getId().equals(id)) {

                return doc;
            }
            else {


            } //daca nu se gaseste id-ul returneaza exceptia, daca il gaseste returneaza doc-ul
        }
        throw new InvalidNotFoundDocException();

    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
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

    @Override
    public String toString() {
        return "Lab5.Catalog{" +
                "name='" + name + '\'' +
                ", path='" + path + '\'' +
                ", documents=" + documents +
                '}';
    }
}
