	import java.util.Arrays;
	import java.util.Objects;

	public class Depot {
		
	   String nameDepot;
	   private Vehiclee[] vehicles;


	    public Depot(){};

	    public String getNameDepot() {
	        return nameDepot;
	    }

	    public void setNameDepot(String nameDepot) {
	        this.nameDepot = nameDepot;
	    }
	    public void setVehicles( Vehiclee [] vehicles) {
	        this.vehicles= vehicles;
	        for(Vehiclee v : vehicles) {
	            v.setDepot(this);
	        }
	    }

	    public Vehiclee[] getVehicles() {
	        return vehicles;
	    }

	    @Override
	    public String toString() {
	        return "Depot{" +
	                "nameDepot='" + nameDepot + '\'' +
	                ", vehicles=" + Arrays.toString(vehicles) +
	                '}';
	    }

	    @Override
	    public boolean equals(Object o) {
	        if (this == o) return true;
	        if (!(o instanceof Depot)) return false;
	        Depot depot = (Depot) o;
	        return Objects.equals(nameDepot, depot.nameDepot) &&
	                Arrays.equals(vehicles, depot.vehicles);
	    }

	    @Override
	    public int hashCode() {
	        int result = Objects.hash(nameDepot);
	        result = 31 * result + Arrays.hashCode(vehicles);
	        return result;
	    }
	}
	
	
	

