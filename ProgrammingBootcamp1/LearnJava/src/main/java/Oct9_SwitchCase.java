import java.util.Scanner;

public class Oct9_SwitchCase {
    public static void main(String[] args) {
        // TODO: guess the number game OK
        // switch-case

//        switch (condition) {
//            case 1:
//                action
//                break;
//            case 2:
//                action
//                break;
//            default
//                action
//                break;
//        }

//        String dayOfTheWeek = getDayOfTheWeek(11);
//        System.out.println(dayOfTheWeek);

//        Toll Free phone number
//        1800-APPLE => 1800-27753

//        getPhoneWord("apple"); -> "1-800-27753"

        Scanner sc = new Scanner(System.in);

//        generate a random interger from a to b (inclusive)
//                e.g. start: 12 - end: 35

        while (true) {
//            System.out.println(Math.random()); 0.0 -> 0.99
//            System.out.println(12 + Math.random()); 12.0 -> 12.99
//            System.out.println(Math.random() * 35); // 0.0 -> 35.99
//            System.out.println(12 + Math.random() * 35); // 12.0 -> 47.99
            System.out.println((int) (12 + Math.random() * (35 + 1 - 12))); // 12 -> 35

            sc.nextLine();
        }
    }



    public static String getDayOfTheWeek(int day) {
//        if 2 : thu 2
//        if 3: thu 3

        String dayStr = "";
//        traditional syntax
//        equal evaluatiion
        switch (day) {
            case 2:
                dayStr = "Thu 2";
                break;
            case 3:
                dayStr = "Thu 3";
                break;
            case 4:
                dayStr = "Thu 4";
                break;
            case 5:
                dayStr = "Thu 5";
                break;
            case 6:
                dayStr = "Thu 6";
                break;
            case 7:
                dayStr = "Thu 7";
                break;
//            case 1, 8, 9, 10:
//            case 11, 0, 12: -> combining multiple cases
            case 1, 8:
                dayStr = "Chu Nhat";
                break;
            default:
                dayStr = "N/A";
                break;
        }


//        Enhanced switch
//        String dayStr = switch (day) {
//            case 2 -> "Thu 2";
//            case 3 -> "Thu 3";
//            case 4 -> "Thu 4";
//            case 5 -> "Thu 5";
//            case 6 -> "Thu 6";
//            case 7 -> "Thu 7";
//            case 8 -> "Chu Nhat";
//            default -> "N/A";
//        };

//        Mapping


        return dayStr;
    }
}
