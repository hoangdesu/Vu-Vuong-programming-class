import java.util.Random;

public class RandomPassword {
    public static void main(String[] args) {
        System.out.println(getRandomPassword(15));
        System.out.println(getRandomPassword(8));
    }

    public static String getRandomPassword(int length) {
        StringBuilder newPass = new StringBuilder();
        Random number = new Random();
        for (int i = 0; i < length; i++) {
            int randType = number.nextInt(3);
//            System.out.println(i+":"+randType);
            if (randType == 0) {
                char RandomNum = (char) ('1' + number.nextInt(9));
                newPass.append(RandomNum);
            } else if (randType == 1) {
                char RandomUpperCaseChar = (char) ('A' + number.nextInt(26));
                newPass.append(RandomUpperCaseChar);
            } else if (randType == 2) {
                char RandomLowerCaseChar = (char) ('a' + number.nextInt(26));
                newPass.append(RandomLowerCaseChar);
            }
        }
        return newPass.toString();
    }
}
