public class Sep28_OOP {
    public static void main(String[] args) {
//        String Double Float Boolean
//        creating Car objects from class Car
        Car mercedes = new Car("Mercedes", 50_000);
        Car mclaren = new Car("McLaren", 120_000);

//        Accessing fields in objects
        System.out.println(mercedes.whatType);
        System.out.println(mclaren.whatType);

        System.out.println(mercedes.brand);

        System.out.println(mclaren.brand);


        System.out.println(mercedes.wheels);
        System.out.println(mclaren.wheels);

        mercedes.brand = "Audi";
        mercedes.drive();
        mclaren.drive();
    }

    static class Car {
        //        fields / properties: variables inside a class
        public String brand;
        private double price;

        String whatType = "this is a car";
        int wheels = 4;

        //        constructor: build up an object
        public Car(String paramBrand, double carPrice) {
            this.brand = paramBrand;
            this.price = carPrice;
        }

//        methods
        public void drive() {
            System.out.println(this.brand + " vroom vroom");
        }
    }


}
//- OOP
//- Class vs Objects
//    Class: design chung (blueprint)
//    Object: created from a class (instance)

//Facebook 2.0
//
//User:
//    - id
//    - name
//    - birthday
//    - gender
//    - ...
//
//Post:
//    - id
//    - title
//    - image
//    - content
//    - likes: []
