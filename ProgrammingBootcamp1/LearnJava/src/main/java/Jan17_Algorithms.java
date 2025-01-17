import java.util.ArrayList;
import java.util.Arrays;

public class Jan17_Algorithms {
    public static void main(String[] args) {
//        static array vs dynamic array
        int[] nums = new int[100000];
//        System.out.println(nums);
//        System.out.println(Arrays.toString(nums));

//        ArrayList<Integer> nums = new ArrayList<>(2);
//        nums.add(1);
//        nums.add(2);
//        nums.add(3);
//        System.out.println(nums);

        for (int i = 0; i < nums.length; i++) {
            // lowerbound 1 - 100 upperbound
//            nums[i] = (int) (Math.random() * (100 - 1) + 1);
            nums[i] = i + 1;
        }

        System.out.println(Arrays.toString(nums));

        int foundIndex = linearSearch(nums, 99901); //
        System.out.println(foundIndex);

//        returnDemo();

        System.out.println(binarySearch(nums, 99901));

    }

    public static int linearSearch(int[] arr, int searchValue) {
        // if found, return the index of searchValue
        // if NOT found, return -1

        int searchCount = 0;
        for (int i = 0; i < arr.length; i++) {
            searchCount++;
            if (searchValue == arr[i]) {
                System.out.println("Search count using linear search: " + searchCount);
                return i;
            }
        }

        return -1;
    }

    public static int returnDemo() {
        for (int i = 0; i < 100; i++) {
            System.out.println("Current i = " + i);
            if (i == 5) {
                return i; // break
            }
        }
        return 0;
    }

    public static int binarySearch(int[] arr, int searchValue) {
        int leftPointer = 0;
        int rightPointer = arr.length - 1;

        int midPointer = (leftPointer + rightPointer) / 2;

        int searchCount = 0;

        while (leftPointer < rightPointer) {
            int midValue = arr[midPointer];
            if (searchValue < midValue) {
//                cat bo phan array ben phai, tim kiem o phan array ben trai
                rightPointer = midPointer;
            } else if (searchValue > midValue) {
                leftPointer = midPointer;
            } else {
                System.out.println("Search count using binary search: " + searchCount);
                return midPointer;
            }
            midPointer = (leftPointer + rightPointer) / 2;
            searchCount++;
        }

        return -1;
    }

//    big O notation
}
