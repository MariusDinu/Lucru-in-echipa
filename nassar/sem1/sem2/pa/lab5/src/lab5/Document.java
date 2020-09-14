package lab5;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map; //clase importate pentru a asigura folosirea anumitor proprietati

public class Document implements Serializable {
    private String id;
    private String nm;
    private String locatie;
//aici am folosit map ca am nevoie de tag iar am mapul care nu permite dublicatele in schimb arraylist permite acest lucru
    private Map<String, Object> tags = new HashMap<>();

    public Document(String id, String nm, String locatie) {
        this.id = id;
        this.nm = nm;
        this.locatie = locatie;
    }

    public void addTag(String key, Object obj) {
        tags.put(key, obj);
    }
//aici am folosit getter and setter pentru a citi si a face update la variabile
    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getNume() {
        return nm;
    }

    public void setNume(String nm) {
        this.nm = nm;
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

