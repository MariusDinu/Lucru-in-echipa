package lab3;

import java.util.List;
import java.util.ArrayList;
public class Knapsack {
    private double capacity;
    public List<Item> items = new ArrayList<>();
   
public Knapsack(){};
    public Knapsack(double capacity) {
        this.capacity = capacity;
    }
    
  

    public Knapsack(List<Item> items) {
        this.items = items;
    }

    public double getCapacity() {
        return capacity;
    }

    public void setCapacity(double capacity) {
        this.capacity = capacity;
    }

    public List<Item> getItems() {
        return items;
    }

    public void setItems(List<Item> items) {
        this.items = items;
    }

    public void addItem(Item item) {
        items.add(item);
    }

    @Override
    public String toString() {
        return "Knapsack{" +
                "capacity=" + capacity +
                ", items=" + items +
                '}';
    }
}
