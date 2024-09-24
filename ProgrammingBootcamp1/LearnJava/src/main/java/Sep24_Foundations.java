public class Sep24_Foundations {
    public static void main(String[] args) {
//        String name = "Brian";
//        boolean hasAPet = false;
//        int birthYear = 1995;

//        System.out.println("Hi my name is " + name + ", I " + (hasAPet ? "have" : "don't have") + " a pet and I am " + (2024 - birthYear) + " years old.");
//        System.out.printf("Hi my name is %s, I %s a pet and I am %d years old.\n", name, (hasAPet ? "have" : "don't have"), (2024 - birthYear));

//        "FROM TABLE {a} SELECT VALUES {b} WHEN CONDTION {c is something}";

//        Ternary operator: short-hand if-else

//        String output = "";
//        if (hasAPet) {
//            output = "have";
//        } else {
//            output = "don't have";
//        }

//        condition ? true value : false value
//        String output = hasAPet ? "have" : "don't have";
//        System.out.println(output);

//        Arithmetic
//        %: modulus -> remainder operator
//        /: division

        System.out.println(10 / 2);
        System.out.println(10 % 2); // mod

//        type inference: data type of the output value will be resulted from its parents
        System.out.println(10.0 / 3);
        System.out.println(10 % 3);

//        Exercise:
//        t = s / v

//        Enter the distance (km): 120
//        Enter the speed (km/h): 60
//
//        It would take 2 hours to travel 120 km.
//
//
//        ---
//        Enter the distance (km): 165
//        Enter the speed (km/h): 51
//
//        It would take 3.23 hours to travel 120 km.
//        > It would take 3 hours and 14 minutes to travel 120 km.

//        3.5 hours
//        It would take 3 hours and 30 minutes to travel 120 km.

//        3.5 hrs
//        3 hrs + 0.5 hrs
//        3 hrs + 0.5 hrs * 60 minutes
//        3 hours and 30 minutes

        System.out.println((int) 3.5); // 3 -> cast double to integer
        System.out.println(3.5 % 1); // 0.5 -> mod itself or 1

//        System.out.println(165/51);

        double minute = 2;
        String minuteUnit = minute > 1 ? "minutes" : "minute";
    }
}
