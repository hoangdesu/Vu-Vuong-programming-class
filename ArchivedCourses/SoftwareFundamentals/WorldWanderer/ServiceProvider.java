package worldwanderer.org;
import java.util.List;

public class ServiceProvider {

	private String providerID;
	private String name;
	
	private List<ServiceOption> serviceOptions;
	
	public ServiceProvider(String providerID, String name) {
		this.providerID = providerID;
		this.name = name;
	}
	public void updateListing() {
		//
	}
	public void respondToInquiry() {
		//
	}
}
