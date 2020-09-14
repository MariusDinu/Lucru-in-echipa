package lab3;

public class Food implements Item{

    private String name;
    private double weight; // → getWeight, getValue
public Food(){};
    public Food(String name) {
        this.name = name;
    }

    public Food(double weight) {
        this.weight = weight;
    }

    @Override
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    @Override
    public double getValue() {
        return weight;
    }

    @Override
    public String toString() {
        return "\nFood : " + this.getName()  + " , weight " + getWeight() + ", value " + getValue();
    }
}
