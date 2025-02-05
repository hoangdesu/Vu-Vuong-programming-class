import java.util.Arrays;

public class Jan20_SortingAlgos {
    public static void main(String[] args) {
        int[] nums = {5, 3, 7, 6, 9, 1, 8, 2, 3};

        int maxNum = findMax(nums); //9
        System.out.println(maxNum);


        int minNum = findMin(nums); //1
        System.out.println(minNum);


//        sort từ bé đến lớn: ascending
//        sort từ bé đến lớn: descending

        System.out.println("original array: " + Arrays.toString(nums));

        selectionSort(nums);

        System.out.println("after sorted: " + Arrays.toString(nums));


    }

    public static int findMax(int[] nums) {
        int max = nums[0];
        for (int num : nums) {
            if (num > max) max = num;
        }
        return max;
    }

    public static int findMin(int[] nums) {
        int min = nums[0];
        for (int num : nums) {
            if (num < min) min = num;
        }
        return min;
    }

    public static void selectionSort(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            int minIndex = i;
            for (int j = i+1; j < nums.length; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

//            swap values
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
    }
}
