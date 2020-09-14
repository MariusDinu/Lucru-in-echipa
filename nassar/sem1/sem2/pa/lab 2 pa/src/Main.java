
public class Main {

	public static void main(String[] args) {
		
 Client c1 = new Client(); 
 
 c1.setNumeClient("Client 1");
 
 c1.setVisita(1); 
 
 System.out.println(c1.getNumeClient());
 
Client c2 = new Client ( 1 , "client 2");

System.out.println(c2);
System.out.println( new Client(3,"Client 3") );   

Problem pb = new Problem(); 

Vehiclee v1 = new Vehiclee("car");
Vehiclee v2 = new Vehiclee("Track");

System.out.println(pb);

Vehiclee something = getAnyValue();
int intValue = something.accept(new IntValueVisitor(), null);

	}

	private static Vehiclee getAnyValue() {
		// TODO Auto-generated method stub
		return null;
	}

	

}
