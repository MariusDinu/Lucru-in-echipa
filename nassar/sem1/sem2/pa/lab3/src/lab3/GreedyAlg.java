package lab3;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;




public class GreedyAlg {

    public Knapsack sack = new Knapsack();
    public List<Item> listOfItems = new ArrayList<Item>();

    public GreedyAlg(){}

    public GreedyAlg(Knapsack k, List<Item> list){
        sack=k;
        sack.setItems(list);
    }

    public GreedyAlg(Knapsack k1) {
        this.sack=k1;
    }

    public void solveProblem(){
        sack.items.sort(new SortbyProfitFactor());
        double totalValue =  0.00;
        double capacityLeft=sack.getCapacity();

        for(Item i: sack.items)
        {

            double itemWeight = i.getWeight();
            double itemValue = i.getValue();

            if (capacityLeft  >= itemWeight)
            {
                // this weight can be picked while
                capacityLeft -= itemWeight;
                 totalValue += itemValue;
                 sack.addItem(i);

            }



        }


}



}