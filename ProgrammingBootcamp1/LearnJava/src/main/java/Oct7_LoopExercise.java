import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Oct7_LoopExercise {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        System.out.print("How many words: ");
//        int totalWords = Integer.parseInt(sc.nextLine()); // tam thoi assume user nhap dung
        int totalWords = sc.nextInt();
        String[] wordList = new String[totalWords];

        for (int i = 0; i < totalWords; i++) {
            wordList[i] = sc.next();
        }

        System.out.println("wordList: " + Arrays.toString(wordList));

//        System.out.print("Enter find char: ");
//        char findChar = sc.nextLine().charAt(0);
        char findChar = sc.next().charAt(0);

//        ArrayList<String> outputWordList = new ArrayList<>();
        for (String word : wordList) {
            for (int i = 0; i < word.length(); i++) {
                if (word.charAt(i) == findChar) {
//                    outputWordList.add(word);
                    System.out.print(word + ",");
                    break;
                }
            }
        }

//        System.out.println(outputWordList);

    }
}
