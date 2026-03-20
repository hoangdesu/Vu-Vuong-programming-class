package worldwanderer.org;

public class Flight extends ServiceOption{

	private String flightNo;
	private double price;
	
	public Flight(String ID, String vendor, String flightNo, double price) {
		super(ID,vendor);
		this.flightNo = flightNo;
		this.price = price;
	}
	
	public String getDetails() {
		return flightNo;
	}
	public boolean checkAvailability() {
		return false;
	}
	
	@Override
	public String getDescription() {
		return flightNo;
	}
	@Override
	public double getPrice() {
		return price;
	}
}
