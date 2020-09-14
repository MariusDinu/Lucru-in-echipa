package lab3;

public class Book implements Item{
    private String name;
    private int pageNumber; // getWeight
    private double value;
public Book(){};
    public Book(String name) {
        this.name = name;
    }

    public Book(int pageNumber) {
        this.pageNumber = pageNumber;
    }

    public Book(double value) {
        this.value = value;
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getValue() {
        return getWeight();
    }

    @Override
    public double getWeight() {
        return pageNumber/100;
    }

    public void setValue() {
        this.value = getWeight();
    }

    public int getPageNumber() {
        return pageNumber;
    }

    public void setPageNumber(int pageNumber) {
        this.pageNumber = pageNumber;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "\nBook : " + this.getName()  + " , weight " + getWeight() + ", value " + getValue();
    }


}
