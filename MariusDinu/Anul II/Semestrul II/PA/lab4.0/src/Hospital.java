public class Hospital {
    public String hospitalName;
    public int capacity;

    public Hospital(int capacity) {
        this.capacity = capacity;
    }

    public Hospital(String hospitalName) {
        this.hospitalName = hospitalName;
    }

    public Hospital() {

    }

    public String getHospitalName() {
        return hospitalName;
    }

    public void setHospitalName(String hospitalName) {
        this.hospitalName = hospitalName;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }
}
