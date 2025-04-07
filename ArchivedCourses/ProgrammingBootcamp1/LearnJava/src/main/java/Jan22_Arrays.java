import java.util.Arrays;

public class Jan22_Arrays {
    public static void main(String[] args) {
//        int[] nums = {5, 3, 7, 6, 9, 1, 8, 2, 3};
//        int[] sortedNums = immutableSelectionSort(nums);
//        System.out.println(Arrays.toString(sortedNums));

        int[] cards = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        shuffle(cards);
        System.out.println(Arrays.toString(cards));
    }

    public static int[] immutableSelectionSort(int[] nums) {
//        int[] newArray = new int[nums.length];
//        for (int i = 0; i < nums.length; i++) {
////            System.out.println(i);
////            newArray = new int[i];
////            newArray = new int[]{i};
//            newArray[i] = nums[i];
//        }
//        return newArray;

        int[] newArray = nums.clone();
        return newArray;
    }

    public static void shuffle(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int randomIndex = (int) (Math.random() * arr.length); // random index from 0 to 9 (array's length)

//            swap the 2 values
            int temp = arr[i];
            arr[i] = arr[randomIndex];
            arr[randomIndex] = temp;
        }
    }
}
