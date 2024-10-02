import java.util.Scanner;

public class Oct2_Loops {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String userName = "brian";
        String password = "secret";

        while (true) {
            System.out.print("Enter your username: ");
            String userNameInput = sc.nextLine();
            System.out.print("Enter your password: ");
            String passwordInput = sc.nextLine();

            if (userNameInput.equals(userName) && passwordInput.equals(password)) {
                System.out.println("Login successfully!");
                break;
            } else {
                System.out.println("Login failed. Please enter again.");
            }
        }
    }
}
