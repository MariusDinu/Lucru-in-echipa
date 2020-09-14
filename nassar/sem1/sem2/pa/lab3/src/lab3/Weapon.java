package lab3;

public class Weapon implements Item  {
        private WeaponType type;
        private double weight;
        private double value;
     public Weapon(){};
     public Weapon(WeaponType type) {
         this.type = type;
     }

     public Weapon(double weight) {
         this.weight = weight;
     }

     public void setValue() {
         this.value = weight;
     }

     public void setWeight(double weight) {
         this.weight = weight;
     }

     public WeaponType getType() {
         return type;
     }

     public void setType(WeaponType type) {
         this.type = type;
     }


        @Override
        public double getWeight() {
            return weight;
        }

        @Override
        public String getName() {
            return type.name();
        }

     @Override
     public double getValue() {
         return weight;
     }

    @Override
    public String toString() {
        return "\nWeapon : " + this.getName()  + " , weight " + getWeight() + ", value " + getValue();
    }
 }


