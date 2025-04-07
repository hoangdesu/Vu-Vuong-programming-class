import java.util.Arrays;

public class Oct1_Arrays {
    public static void main(String[] args) {
        String[] food = {"phở", "cơm tấm", "bún đậu"};
////        System.out.println(food); // memory address
//
//        food[2] = "bún riêu";
//
//        // 1. built-in method from Arrays class
        System.out.println(Arrays.toString(food));
//
//        // access by index
//        System.out.println("I wanna eat " + food[1]);
//
//        // 2. loop over (iterate over items)
//        for (int i = 0; i < food.length; i++) {
//            System.out.println((i+1) + ". " + food[i]);
//        }

        int counter = 1;
        for (int i = food.length - 1; i >= 0; i--) {
            System.out.println((counter++) + ". " + food[i]);
//            counter++;
        }

        double[] scores = { 6.7, 9.8, 5.5, 7.1 };

        double total = 0;
        for (int i = 0; i < scores.length; i++) {
//            total = total + scores[i];
            total += scores[i];
        }

        System.out.println("Total = " + total);

        double avg = total / scores.length;
        System.out.printf("Average score = %.1f\n", avg);


//        prefix increment (++i) vs postfix increment (i++)

//        int num = 1;
//        ++num;
//        System.out.println(num++); // 1st: print 1 | 2nd: add 1 to num
//        System.out.println(num);

//        System.out.println(++num++);
//        System.out.println(num); //

    }
}


//chuỗi
//2 loai array:
//    1. Static array (tĩnh): fixed length
//            - DataType[]
//    2. Dynamic array (động): varied length

//a collection of similar items

//0913172602 -> 10 digits
//users database: dynamic array



