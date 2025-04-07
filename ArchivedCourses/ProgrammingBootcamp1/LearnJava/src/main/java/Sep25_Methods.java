public class Sep25_Methods {

    //    no input, no output
    public static void sayHello() {
        System.out.println("Hello!!!");
    }

    public static void main(String[] args) {
//        - user-defined methods (functions)
//        - wrap around a block of code
//        - to perform a specific set of actions

//        when working with methods, 2 steps involved:
//            1. define a method
//            2. execute the method (invoke, run)

//        order of the method definitions doesn't matter.
//        must be defined outside of main,

//        String name = "Brian";
//        String country = "Vietnam";
//        int birthYear = 1995;
//        int age = 2024 - birthYear;
//
//        System.out.printf("Hi my name is %s, I came from %s and I am %d years old", name, country, age);

//        introduce("Brian", "Vietnam", 1995);
//        introduce("Justin", "Australia", 2005);

//        sayHello(); // execute the function

        int c = add(5, 10);
        System.out.println(c);
        System.out.println("double of c:" + (c * 2));

//        String name = sc.nextLine();

//        Exercise:
//        Enter radius of 1 circle:
//        How many circles are there: 3
//
//        double totalAreaOfCircles = calculateCircleArea(radius: double, circle: int);
//        System.out.println(Total area of 3 circles is ...);
//
//        HW: Mock Task 1

    }

//    user-defined methods

//    multiple inputs, no output
//    inputs = parameters = arguments: inputs for a function
    public static void introduce(String name, String country, int birthYear) {
        int age = 2024 - birthYear;
//        sayHello();
        System.out.printf("Hi my name is %s, I came from %s and I am %d years old\n", name, country, age);
    }

//    methods with return value (output)
//    only 1 value can be returned from a function
    public static int add(int a, int b) {
        int total = a + b;
//        System.out.println(total);
        return total;
    }

//    public static double


}
