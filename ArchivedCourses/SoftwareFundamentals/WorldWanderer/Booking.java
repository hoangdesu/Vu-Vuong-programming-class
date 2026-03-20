package worldwanderer.org;

public class Booking {
	
	private String bookingID;
	private String date;
	
	private Payment payment;
	private Confirmation confirmation;
	private ServiceOption serviceOption;
	
	public Booking(String bookingID,String date) {
		this.bookingID = bookingID;
		this.date = date;
	}
	
	public void confirmBooking() {
		//
	}

	public void cancelBooking() {
		//
	}
}
