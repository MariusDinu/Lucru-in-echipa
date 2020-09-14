package lab3;

import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;
import java.io.*; 
import java.util.*; 
public class Main {
    public Main(){}
    public static void main(String args[])
    {
Weapon wepon1= new Weapon();
wepon1.setType(WeaponType.SWORD);
wepon1.setWeight(2);
wepon1.setValue();
System.out.println(wepon1.toString());

Weapon w2=new Weapon(WeaponType.LAPTOP);
System.out.println("Weapon 1 : profit factor = " + wepon1.profitFactor());

Book b1=new Book();
b1.setName("Carte");
b1.setPageNumber(300);
System.out.println(b1.toString());




Food f1=new Food();
f1.setName("Cabanos");
f1.setWeight(2);
System.out.println(f1.toString());



Knapsack k1=new Knapsack();
List<Item> myList = new ArrayList<Item>();

myList.add(wepon1);
myList.add(b1);
k1.setCapacity(10);
k1.addItem(f1);
k1.setItems(myList);
Collections.sort(k1.items, new Sortbyname());
System.out.println(k1.getItems());
GreedyAlg g1 = new GreedyAlg(k1);
g1.solveProblem();
System.out.println("Greedy Solution \n" + g1.sack.toString());

    }
}

