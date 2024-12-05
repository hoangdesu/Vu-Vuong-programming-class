import java.util.HashMap;
import java.util.Objects;

public class Dec5_Algo {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//        Big O
//        linear search:
//        worst-case scenario: O(n)

//        binary search: O(log(n))

//        Facebook user database
//        users = [1B]

//        username: password

        System.out.println(isAnagram("tea", "eat"));  // -> true
        System.out.println(isAnagram("tee", "eat")); // -> false

//        tea:
//        {
//            t: 1,
//            e: 1,
//            a: 1
//        }
//
//        eat:
//        {
//            e: 1,
//            a: 1,
//            t: 1
//        }

//        HashMap<String, Integer> map1 = new HashMap<>();
//        map1.put("t", 1);
//        map1.put("e", 3);
//
//        HashMap<String, Integer> map2 = new HashMap<>();
//        map2.put("e", 2);
//        map2.put("t", 1);

//        System.out.println(s1.equals(s2));
//
//        for (String map1Key : map1.keySet()) {
////            System.out.println(s1Key);
//            if (map2.containsKey(map1Key)) {
//                System.out.print(map1Key + map2.get(map1Key));
//                if (map1.get(map1Key) == map2.get(map1Key)) {
//                    System.out.println("Equals");
//                }
//            }
//        }


    }

    public static boolean isAnagram(String s1, String s2) {

        if (s1.length() != s2.length()) return false;

        HashMap<String, Integer> map1 = new HashMap<>();
        for (int i = 0; i < s1.length(); i++) {
            String key = String.valueOf(s1.charAt(i));
            if (!map1.containsKey(key)) {
                map1.put(key, 1);
            } else {
                int num = map1.get(key);
                map1.put(key, ++num);
            }
        }

        HashMap<String, Integer> map2 = new HashMap<>();
        for (int i = 0; i < s2.length(); i++) {
            String key = String.valueOf(s2.charAt(i));
            if (!map2.containsKey(key)) {
                map2.put(key, 1);
            } else {
                int num = map2.get(key);
                map2.put(key, ++num);
            }
        }

//        System.out.println(map1);
//        System.out.println(map2);

//        return map1.equals(map2);

        for (String map1Key : map1.keySet()) {
            if (!map2.containsKey(map1Key)) return false;
            if (!Objects.equals(map1.get(map1Key), map2.get(map1Key))) return false;
        }

        return true;
    }

}
