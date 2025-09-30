package worldwanderer.org;

public abstract class ServiceOption {
	protected String ID;
	protected String vendor;
	
	public ServiceOption(String ID, String vendor) {
		this.ID = ID;
		this.vendor = vendor;
	}
	
	public abstract String getDescription();
	public abstract double getPrice();
}
