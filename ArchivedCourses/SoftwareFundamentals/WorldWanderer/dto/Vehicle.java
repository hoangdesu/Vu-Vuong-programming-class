package dto;

// DTO: data type object
public class Vehicle {
    
	private String vehicleType;
	private double price;
	
	public Vehicle(String ID, String vendor, String vehicleType, double price) {
		// super(ID,vendor);
		this.vehicleType = vehicleType;
		this.price = price;
	}
}
