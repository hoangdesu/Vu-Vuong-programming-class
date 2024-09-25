import java.util.Arrays;

public class Sep24_Foundations {
    public static void main(String[] args) {
//        String name = "Brian";
//        boolean hasAPet = false;
//        int birthYear = 1995;

//        System.out.println("Hi my name is " + name + ", I " + (hasAPet ? "have" : "don't have") + " a pet and I am " + (2024 - birthYear) + " years old.");
//        System.out.printf("Hi my name is %s, I %s a pet and I am %d years old.\n", name, (hasAPet ? "have" : "don't have"), (2024 - birthYear));

//        "FROM TABLE {a} SELECT VALUES {b} WHEN CONDITION {c is something}";

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

//        System.out.println(10 / 2);
//        System.out.println(10 % 2); // mod
//
////        type inference: data type of the output value will be resulted from its parents
//        System.out.println(10.0 / 3);
//        System.out.println(10 % 3);

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

//        System.out.println((int) 3.5); // 3 -> cast double to integer
//        System.out.println(3.5 % 1); // 0.5 -> mod itself or 1

//        System.out.println(165/51);

//        double minute = 2;
//        String minuteUnit = minute > 1 ? "minutes" : "minute";

//        Primitive vs Wrapper types
        String food = "ramen";

        int a = 1;
        Integer b = 2;

        System.out.println(a + b);

        double c = 3.0;
        Double d = 4.0;

        System.out.println(c + d);

//        - primitive: original types
//        - wrapper: bao bọc primitive type, ngoài data ở dạng primitive, còn có thêm các methods

//        System.out.println(d.hashCode());
////        System.out.println(c.); // no methods available
//
//        String: array of characters: chuỗi ký tự
////            V-ư-ơ-n-g
////            1-2-3-4-5
//
//        primitive của string là char

//        1 single character
        char c1 = 'V'; // must use single-quote
        char c2 = 'ư';
        char c3 = 'ơ';
        char c4 = 'n';
        char c5 = 'g';

        String name = "" + c1 + c2 + c3 + c4 + c5;

        System.out.println(name);

//        String methods
        System.out.println(name.toUpperCase()); // copy values in name into a different place
        System.out.println(name.toLowerCase());
        System.out.println(name.length());
        System.out.println("Character at index 2: " + name.charAt(2));
        System.out.println(name.equals("Vương"));
        System.out.println(name.substring(1, 4)); // ươn
        System.out.println(Arrays.toString(name.getBytes()));

        System.out.println("Original name: " + name);


//        OOP
//        Car mclaren = new Car();
//        mclaren.vroom();

    }
}

//TODO:
//- ASCII
//- equals() vs ==
//- memory address, pointer