import java.util.Scanner;

public class Feb25_Strings {


    public static void main(String[] args) {
//        String car1 = "ferrari";
////        String car2 = "ferrari";
//        String car2;
//        car2 = "ferrari";
//
//        Scanner sc = new Scanner(System.in);
//        System.out.print("Enter your favorite car: ");
//        String favCar = sc.nextLine(); // ferrari
//
//        System.out.println(car1 == car2); // true
//        System.out.println("== " + (favCar == car1)); // false?
//        System.out.println(".equals() " + favCar.equals(car1));

        String name = "Vuong";
        hi(name);
    }

//    JVM: method hoisting
    public static void hi(String name) {
        System.out.println("Hi " + name);
    }
}
