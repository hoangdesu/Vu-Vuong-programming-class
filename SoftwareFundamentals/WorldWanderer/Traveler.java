package worldwanderer.org;
import java.util.List;


public class Traveler {

	private String travelerID;
	private String preferences;
	
	public List<Booking> bookings;
	public List<Review> reviews;
	
	public Traveler(String travelerID, String preferences) {
		this.travelerID = travelerID;
		this.preferences = preferences;
	}
	public void searchFlights() {
		//
	}
	public void searchAccommodation() {
		//
	}
}
