package Sep30_OOP;

public class Main {
    public static void main(String[] args) {
//        Vehicle v = new Vehicle(); // error
        Car c = new Car(); // OK
        System.out.println(c);
        c.drive();

        Plane p = new Plane();
        p.drive();
    }
}

//make a class abstract
//create an interface
//    - chi co the co khai niem, ko co implementation

// TODO: abstract