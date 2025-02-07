import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;

public class Feb7_Strings {
    public static void main(String[] args) {
        String s1 = "C++ Programming Studio in the Studio 2";
//        System.out.println(s1.substring(0, 5));
//        System.out.println(s1.contains("Prog"));
//        String[] words = s1.split(" ");
//        System.out.println(Arrays.toString(words));

//        String query = "C+";
//        boolean found = false;
//        for (String word : words) {
//            if (word.equals(query)) {
//                System.out.println("Found the query");
//                found = true;
//            }
//        }
//
//        if (!found) {
//            System.out.println("Query not found!");
//        }

        System.out.println(replaceWord(s1, "Studio", "Bootcamp"));

        System.out.println(Arrays.toString(s1.toCharArray()));
        System.out.println(Arrays.toString(toCharStaticArray(s1)));
        System.out.println(toCharDynamicArray(s1));

        int[] nums = {1, 2, 3};
        System.out.println(nums);
        System.out.println(Arrays.toString(nums));

//        Integer a = 1;
//
//        for (int b : a) {
//
//        }

        for (int n : nums) {
            System.out.println(n);
        }

//        System.out.println(s1.getBytes().toString());

//        static (tĩnh): fixed length
//        dynamic (động): varied length
//        ArrayList: ?

        mixAndMatch("Java", "python language") -> "Jpayvtahon language"

//        https://leetcode.com/problems/longest-common-prefix/description/?envType=problem-list-v2&envId=string

    }

    public static String replaceWord(String str, String oldWord, String newWord) {
//        StringBuilder newStr = new StringBuilder();

        String[] splittedWords = str.split(" ");

        for (int i = 0; i < splittedWords.length; i++) {
            if (splittedWords[i].equals(oldWord)) {
                splittedWords[i] = newWord;
                break;
            }
        }

//        for (String word : splittedWords) {
//            newStr.append(word);
//            newStr.append(" ");
//        }

        return String.join(" ", splittedWords);
    }

    public static char[] toCharStaticArray(String s) {
        char[] arr = new char[s.length()]; // static array
        for (int i = 0; i < s.length(); i++) {
            arr[i] = s.charAt(i);
        }
        return arr;
    }

    public static ArrayList<Character> toCharDynamicArray(String s) {
        ArrayList<Character> arr = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            arr.add(s.charAt(i));
        }
        return arr;
    }

    String mixAndMatch(String s1, String s2) {

    }
}
