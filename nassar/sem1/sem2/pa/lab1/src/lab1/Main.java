package lab1;

public class Main {

	public static void main(String[] args) {
		
		Student student = new Student();
		
		Student student2 = new Student(20, "nassar", "sta decebal");
		
		System.out.print(student2.getNume());
		
		student2.setNume("Rasres");
		
		System.out.println(student2.getNume());
		
		System.out.println(student.getNume());

		System.out.println(student2.toString());

	}

}