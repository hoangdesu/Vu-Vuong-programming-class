package worldwanderer.org;

public class Vehicle extends ServiceOption{

	// DTO: data type object
	private String vehicleType;
	private double price;
	
	public Vehicle(String ID, String vendor, String vehicleType, double price) {
		super(ID,vendor);
		this.vehicleType = vehicleType;
		this.price = price;
	}
	
	// DAO: data access object
	public String getDetails() {
		return "";
	}
	public boolean checkAvailability() {
		return false;
	}
	@Override
	public String getDescription() {
		return vehicleType;
	}
	
	@Override
	public double getPrice() {
		return price;
	}

	public String getVehicleType() {
		return vehicleType;
	}
}
