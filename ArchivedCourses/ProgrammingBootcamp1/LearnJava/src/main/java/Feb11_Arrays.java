import java.util.ArrayList;
import java.util.Arrays;

public class Feb11_Arrays {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        int[] evens = removeOdds(nums); // [2,4,6,8,10]
        System.out.println(Arrays.toString(evens));
        System.out.println("Using Dynamic Array : " + Arrays.toString(removeOddsDynamicArray(nums)));
        System.out.println("Using Stream: " + Arrays.toString(removeOddsUsingStream(nums)));

    }

    public static int[] removeOdds(int[] nums) {
        int count = 0;
        for (int num : nums) {
            if (num % 2 == 0) count++;
        }

        int[] evens = new int[count];
        int j = 0;
        for (int num : nums) {
            if (num % 2 == 0) {
                evens[j] = num;
                j++;
            }
        }

        return evens;
    }

    public static int[] removeOddsDynamicArray(int[] nums) {
        ArrayList<Integer> evensAL = new ArrayList<>();
        for (int num : nums) {
            if (num % 2 == 0) evensAL.add(num);
        }

        int[] evens = new int[evensAL.size()];
        for (int i = 0; i < evens.length; i++) {
            evens[i] = evensAL.get(i);
        }

        return evens;
    }

    public static int[] removeOddsUsingStream(int[] nums) {
//        lambda expression: anonymous function (function without a name)

//        return Arrays
//                .stream(nums)
////                .filter(num -> {
//////                    int satisfitedNum = num % 2 == 0 ? num;
////                    if (num % 2 == 0) {
////                        return true;
////                    }
////                    return false;
////                })
//                .toArray();

        return Arrays
                .stream(nums)
                .filter(num -> num % 2 == 0)
                .map(num -> num * 2)
                .toArray();
    }
}