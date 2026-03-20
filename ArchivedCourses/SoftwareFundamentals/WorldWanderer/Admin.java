package worldwanderer.org;

public class Admin extends Review{
	
	private String adminID;
	private String role;
	
	public Admin(String adminID, String role, String reviewID, int rating) {
		super(reviewID, rating);
		this.adminID = adminID;
		this.role = role;
	}
	
	public void updateServiceFee() {
		//
	}
	public void manageProducts() {
		//
	}
}
