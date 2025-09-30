package worldwanderer.org;

public class Accommodation extends ServiceOption{

	private String hotelName;
	private double price;
	
	public Accommodation(String ID, String vendor, String hotelName, double price) {
		super(ID,vendor);
		this.hotelName = hotelName;
		this.price = price;
	}
	public String getDetails() {
		return hotelName;
	}
	public boolean checkAvailability() {
		return false;
	}
	@Override
	public String getDescription() {
		return hotelName;
	}
	@Override
	public double getPrice() {
		return price;
	}
}
