import enume.VehicleType;



public class Vehiclee {

    public VehicleType VehicleeType;
    public Depot depot;
    String nameCar;

    public Vehiclee(){};

    public Vehiclee(String nameCar) {
        this.nameCar = nameCar;
    }

    public Depot getDepot() {
        return depot;
    }

    public void setDepot(Depot depot) {
        this.depot = depot;
    }

    public String getNameCar() {
        return nameCar;
    }

    public void setNameCar(String nameCar) {
        this.nameCar = nameCar;
    }

    @Override
    public String toString() {
        return "Vehiclee{" +
                "VehicleeType=" + VehicleeType +
                ", depot=" + depot +
                ", nameCar='" + nameCar + '\'' +
                '}';
    }
    @Override
    public boolean equals(Object obj) {
        if (obj == null || !(obj instanceof Vehiclee)) {
            return false;
        }
        Client other = (Client) obj;
        return nameCar.equals(other);
    }

	public int accept(IntValueVisitor intValueVisitor, Object CAR) {
		// TODO Auto-generated method stub
		return 0;
	}

}
