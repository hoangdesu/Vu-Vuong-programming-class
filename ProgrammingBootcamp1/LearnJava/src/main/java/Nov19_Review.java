import java.util.HashMap;

public class Nov19_Review {

    static class Country {
        String country;
        String capital;

        public Country(String country, String capital) {
            this.country = country;
            this.capital = capital;
        }
    }


    public static void main(String[] args) {
//        Data structures

//        HashMap vs Class

//        HashMap<String, String> capitals = new HashMap<>();
//
//        capitals.put("vietnam", "Ha Noi");
//        capitals.put("japan", "Tokyo");
//
//        System.out.println(capitals.get("korea"));
//
//        capitals.keySet();

//        Country vn = new Country("vietnam", "ha noi");
//        Country jp = new Country("japan", "tokyo");
//
//        System.out.println(vn.capital + jp.country);


//        R: 256
//        G: 256
//        B: 256

//        getCharacterFrequency(String) -> HashMap<String, Integer>
//        getCharacterFrequency("haha abc")
//
//        => {
//            h: 2,
//            a: 3,
//            b: 1,
//            c: 1
//        }

        HashMap<String, Integer> data = getCharacterFrequency("haha hehe hoho");
        System.out.println(data);


        HW1:
//        getWordFrequency(String) -> {haha: 1, hehe: 1, hoho: 1};
        String a = "haha hehe hoho";
        String[] words = a.split(" ");


//        HW2
//        getRandomRGBColor() -> String "rgb(200, 20, 50)"
//        r: 0-255
//        g: 0-255
//        b: 0-255


    }

    public static HashMap<String, Integer> getCharacterFrequency(String s) {
        HashMap<String, Integer> data = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            // only count the alphabet characters
            if (c >= 97 && c <= 122) {
//                check if hashmap already has the entry
                String key = String.valueOf(c);

                if (data.get(key) == null) {
                    data.put(key, 1);
                } else {
                    int curFreq = data.get(key);
                    data.put(key, curFreq + 1);
                }
            }
        }

        return data;
    }




}
