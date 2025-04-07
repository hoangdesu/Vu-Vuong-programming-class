import java.util.HashMap;

public class Dec6_Hashmap {
    public static void main(String[] args) {
//        System.out.println(hasDuplicate(new int[]{1,2,3}));
//        System.out.println(hasDuplicate(new int[]{1,1,3}));

//        portfolio: {
//            "stock": 123,
//            "bond": 345,
//            "real estate": 999,
//            "cars": 1000,
//            "cash": 5
//        }
//
//        calculateTotal(portfolio);


    }

    public static boolean hasDuplicate(int[] nums) {
        HashMap<Integer, Integer> seen = new HashMap<Integer, Integer>();

        for (int num : nums) {
            if (seen.containsKey(num)) return true;
            seen.put(num, 1);
        }

        return false;
    }

//    public static double calculateTotal(HashMap<String, Double> portfolio) {
//
//    }
}
