import java.util.HashMap;
import java.util.Hashtable;
import java.util.Map;
import java.util.Set;

public class Feb17_HashMap {
    public static void main(String[] args) {
//        country -> food

        HashMap<String, String> foodMap = new HashMap<>();
        foodMap.put("vietnam", "pho");
        foodMap.put("korea", "kimbap");
        foodMap.put("japan", "takoyaki");
        foodMap.put("australia", "fish and chips");

        foodMap.put("korea", "kimchi");

        System.out.println(foodMap.get("vietnam"));
        System.out.println(foodMap.get("china"));

//        Time complexity: O(n) or O(n^2)
//        Search:
//        - array O(n)
//        - hashmap O(1)

//        looping over keys
        for (String key : foodMap.keySet()) {
            System.out.printf("key=%s, value=%s\n", key, foodMap.get(key));
        }

//        looping over values
        for (String food : foodMap.values()) {
            System.out.println(food);
        }

//        looping over all pairs (entries)
        for (Map.Entry<String, String> entry : foodMap.entrySet()) {
            System.out.println(entry.getKey() + ":" + entry.getValue());
        }


//        Calculate the frequency of each char inside a string
//        "abcadaee" ->
//        {
//            a: 3,
//            b: 1,
//            c: 1,
//            d: 1,
//            e: 2
//        }

        System.out.println(calculateCharFrequency("abcadaee"));


        // legacy, dont use
        Hashtable<String, String> food = new Hashtable<>();
        food.put("murica", "burger");

//        foodMap.equals(map2);

//        HW:
//        isAnagram("heart", "earth"); // true
//        isAnagram("heart", "eartt"); // false
//        use for loop to compare the entries from 2 maps


//        Feb18_RomanToInt.romanToInt();
    }

    public static HashMap<Character, Integer> calculateCharFrequency(String s) {
        HashMap<Character, Integer> charFrequency = new HashMap<>();

//        for (int i = 0; i < s.length(); i++) {
//            char c = s.charAt(i);
//        }

        for (char c : s.toCharArray()) {
//            if not there, create a new entry
            if (charFrequency.get(c) == null) {
                charFrequency.put(c, 1);
            } else {
//                if key is already there, update the count value up by 1
                int currentCount = charFrequency.get(c);
                int newCount = currentCount + 1;
                charFrequency.put(c, newCount);
            }
        }

        return charFrequency;
    }


}
