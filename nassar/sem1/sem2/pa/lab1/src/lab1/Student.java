package lab1;

public class Student {

	private int varsta;
	private String nume;
	private String adresa;
	
	
	
	public Student() {
	}
	
	public Student(int varsta, String nume, String adresa) {
		this.varsta = varsta;
		this.nume = nume;
		this.adresa = adresa;
	}
	public int getVarsta() {
		return varsta;
	}
	public void setVarsta(int varsta) {
		this.varsta = varsta;
	}
	public String getNume() {
		return nume;
	}
	public void setNume(String nume) {
		this.nume = nume;
	}
	public String getAdresa() {
		return adresa;
	}
	public void setAdresa(String adresa) {
		this.adresa = adresa;
	}

	@Override
	public String toString() {
		return "Student [varsta=" + varsta + ", nume=" + nume + ", adresa=" + adresa + "]";
	}
	
	
}
