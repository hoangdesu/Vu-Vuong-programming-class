import java.util.Arrays;

public class Jan10_CommandLineTools {
    public static void main(String[] args) {
//        Command-line tool
//        System.out.println("> Args: " + Arrays.toString(args));
//        int total = 0;
//        for (String arg : args) {
//            total += Integer.parseInt(arg);
//        }
//
//        System.out.println("Total = " + total);

        int length = Integer.parseInt(args[0]);
        System.out.println(RandomPassword.getRandomPassword(length));
    }
}
