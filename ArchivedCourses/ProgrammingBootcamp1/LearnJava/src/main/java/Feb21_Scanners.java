import java.util.Scanner;

public class Feb21_Scanners {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("What's your name: ");
        String name = sc.nextLine();
        System.out.println("Hello " + name);

        int a = 1;
        String b = "2";

        System.out.println(a + b); // auto convert to string 1 -> "1"
    }
}
