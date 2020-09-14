

public class IntValueVisitor implements SomeClassVisitor<Integer, Void> {
     public Integer CAR(Void param){
         return 1;
     }

     public Integer TRUCK(Void param){
         return 2;
     }

     public Integer DRONE(Void param){
         return 3;
     }    
}