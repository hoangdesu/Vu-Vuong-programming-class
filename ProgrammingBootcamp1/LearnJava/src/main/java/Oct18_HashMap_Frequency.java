import java.util.Arrays;
import java.util.HashMap;

public class Oct18_HashMap_Frequency {
    public static void main(String[] args) {
        String msg = "hello hi ho hello hi ho ho ho ho hi hello";

//        {
//            hello: 2,
//            hi: 3,
//            ho: 1
//        }

        HashMap<String, Integer> wordFrequency = getWordFrequency(msg);
        System.out.println(wordFrequency);

    }

    public static HashMap<String, Integer> getWordFrequency(String text) {
        HashMap<String, Integer> wordFrequency = new HashMap<>();

        String[] words = text.split(" ");
//        System.out.println(Arrays.toString(words));

//        short-hand for loop
//        for (int i = 0; i < words.length; i++) -> access with words[i]

        for (String word : words) {
//            if hashmap does not have the key yet, create an entry with frequency = 1
            if (!wordFrequency.containsKey(word)) {
                wordFrequency.put(word, 1);
            }
            // if hashmap already contains the word, increase frequency by 1
            else {
                int currentFrequency = wordFrequency.get(word);
                wordFrequency.replace(word, currentFrequency+1);
            }
        }

        return wordFrequency;
    }


}
