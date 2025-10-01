package worldwanderer.org;

public abstract class ServiceOption {
	protected String ID;
	protected String vendor;
	
	public ServiceOption(String ID, String vendor) {
		this.ID = ID;
		this.vendor = vendor;
	}
	
	public abstract String getDescription() {

	};
	public abstract double getPrice();
}


interface Species {

	void eat();
}

class Human implements Species {

	void eat() {

	}
}

class Dog implements Species {

	void eat() {
		
	}
}