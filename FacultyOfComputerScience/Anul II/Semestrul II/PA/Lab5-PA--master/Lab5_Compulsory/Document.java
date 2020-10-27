import java.io.Serializable;
import java.util.HashMap;
import java.util.Map; //clase importate pentru a asigura folosirea anumitor proprietati

public class Document implements Serializable {
    private String id;
    private String nume;
    private String locatie;

    private Map<String, Object> tags = new HashMap<>();

    public Document(String id, String nume, String locatie) {
        this.id = id;
        this.nume = nume;
        this.locatie = locatie;
    }

    public void addTag(String key, Object obj) {
        tags.put(key, obj);
    }
//aici am folosit getter and setter pentru a citi si face update la variabile
    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getNume() {
        return nume;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public String getLocatie() {
        return locatie;
    }

    public void setLocatie(String locatie) {
        this.locatie = locatie;
    }

    public Map<String, Object> getTags() {
        return tags;
    }

    public void setTags(Map<String, Object> tags) {
        this.tags = tags;
    }
}

