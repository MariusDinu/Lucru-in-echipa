
public class Client {

	private int visita;
	private String numeClient;
	
	public Client() {
		
	}
	
	public Client(int visita, String numeClient) {
		
		this.visita = visita;
		this.numeClient = numeClient;
		
	}
	
	
	@Override
	public String toString() {
		return "Client [visita=" + visita + ", numeClient=" + numeClient + "]";
	}

	public int getVisita() {
		return visita;
	}

	public void setVisita(int visita) {
		this.visita = visita;
	}

	public String getNumeClient() {
		return numeClient;
	}

	public void setNumeClient(String numeClient) {
		this.numeClient = numeClient;
	}
}
