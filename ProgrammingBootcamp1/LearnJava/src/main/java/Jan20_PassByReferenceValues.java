import java.util.Arrays;

public class Jan20_PassByReferenceValues {

    public static class MyNumbers {
        int x = 8;
        int y = 2;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 80 bytes

//        Time complexity: big-O notation
//        Linear search: O(n)
//        Binary search: O(log n)

//        Always consider the worst-case scenario

//        Swap values
        int a = 1;
        int b = 9;

//        int c = a;
//        a = b;
//        b = c;

        swapValues(a, b);

        System.out.println("Outside swap function");
        System.out.println(a); // 9
        System.out.println(b); // 1

//        2 ways to pass value(s) inside a function
//        1. Pass by value:
//          - passing a primitive value into a function
//          - the values are copied

//        2. Pass by reference:
//          - passing objects into a function
//          - values are directly referenced

//        Primitive vs Wrapper (reference) data types
//        - primitive: int, long, short, byte, boolean, char. double, float
//        - wrapper = primitive + methods: Integer, Long, Short, Scanner, String,

        MyNumbers myNumWrapperType = new MyNumbers();

        swapValues(myNumWrapperType);
        System.out.println("x=" + myNumWrapperType.x);
        System.out.println("y=" + myNumWrapperType.y);

        System.out.println(Arrays.toString(nums));
    }

    public static void swapValues(int a, int b) {
        int c = a;
        a = b;
        b = c;

        System.out.println("Inside swap function");
        System.out.println(a);
        System.out.println(b);
    }

    public static void swapValues(MyNumbers myNumbers) {
        int temp = myNumbers.x;
        myNumbers.x = myNumbers.y;
        myNumbers.y = temp;
    }


}
