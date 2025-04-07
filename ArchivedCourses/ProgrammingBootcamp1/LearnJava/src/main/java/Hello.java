import java.util.ArrayList;
import java.util.Scanner;

public class Hello {
    public static void main(String[] args) {
//        System.out.println("Hello Java");

//        What's your name: Brian
//        Have a good day, Brian!

//        Scanner -> get user input
//        Scanner...


//      Variables: biến.
//                - container for a value
//                - value can be re-assigned

        String name = "Brian";
        name = "Vuong";
        name = "Justin"; // re-assign: gán lại value mới cho variable
        System.out.println(name);

//        format to define a new variable
//        Datatype variableName = value;


//        Data types: kiểu dữ liệu
//                Numbers: arithmetic
//                    - int: integers, số nguyên, 30, -5, 0
//                    - long: similar to int
//                    - float: floating-point number = decimal numbers, số thập phân, 3.14, -5.6, 30.0 (chứa ít số hơn double)
//                    - double: tương tự float (recommended) (chứa dc số lớn hơn float)
//
//                String: chuỗi kí tự
//                    - số, chữ, special characters
//                    - wrapped around a "double quote"
//                    - multi-line string: """3 double quote"""
//
//                Boolean: true/false
//                    - conditionals: if-else if-else
//                    - allows the computer to choose from a set of options, based on a given condition

        int x = 1;
        int y = 2;
        System.out.println(x + y);

        double a = 3;
        double b = 4.0;
        System.out.println(a + b); // type inference

        System.out.println(x + a); // int + double = double

        float c = 5.1f;
        float d = 6;
        System.out.println(c + d);

        System.out.println(x + a + c);

        long population = 8_000_000_000L;
        System.out.println("word populations is " + population + " people");
        // str + long + str = str
//        int + float + double + long + str = str


        // comment: take notes & turn on that line of code
//        shortcut to toggle a line comment: ctrl + /

        String country = "Việt Nam 🇻🇳 !!!";
        System.out.println(country);
        System.out.println(country.charAt(2));


//        String concatenation = combine strings together
//        string + string = string

        int birthYear = 1995;
        System.out.println("I am " + (2024 - birthYear) + " years old"); // prioritize string

//        type inference

//        boolean isRaining = false;
//        if (isRaining) {
//            System.out.println("Stay indoor");
//        } else {
//            System.out.println("Go touch grass");
//        }

//        Evaluate boolean expression
//        > < == >= <=

        double lamborghini = 500_000;
        double myMoney = 500_000;

        if (myMoney > lamborghini) {
            System.out.println("Enough to purchase a Lambo");
        } else {
            System.out.println("Not enough. Grind more");
        }


//        Variable naming conventions: quy ước đặt tên biến
//        thisisalongvariablename
//        camelCase: thisIsALongVariableName (variable, function names)
//        PascalCase: ThisIsALongVariableName (Class, Inteface)
//        snake_case: this_is_a_long_variable_name (Python)


//        Rules:
//        - no special chars
//        - cannot start with a number
//        - case-sensitive

//        String student1 = "a"; // OK
//        String 1student = "b"; // NOT ok

        String city = "Ho Chi Minh city";
        String City = "Ha Noi";

        System.out.println(City);
        System.out.println(city);

    }
}
