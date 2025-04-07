import java.util.HashMap;

public class Feb18_RomanToInt {
    public static void main(String[] args) {
        System.out.println(romanToInt("MDCXCV")); // 1695
        System.out.println(romanToInt("III")); // 1695
//        1000
//        500
//        100
//        90
//        5

//        0123456
//        MDCXCV
//        ....-++
    }

    public static int romanToInt(String s) {
        HashMap<Character, Integer> romanNum = new HashMap<>();
        romanNum.put('I', 1);
        romanNum.put('V', 5);
        romanNum.put('X', 10);
        romanNum.put('L', 50);
        romanNum.put('C', 100);
        romanNum.put('D', 500);
        romanNum.put('M', 1000);

        int sum = 0;
//      MCMXCIV
//        ..-
//
//        i=0, curr=M, next=C => 1000
//        i=1, curr=C, next=M => 900
//        i=2, curr=M, next=X => 1000

        boolean overflowed = false;

//        for (int i = 0; i < s.length() - 1; i++) {
        int i = 0;
        while (i < s.length()) {
            char curr = s.charAt(i);
            char next = i < s.length() - 1 ? s.charAt(i + 1) : ' ';

//            System.out.printf("i=%d, curr=%c, next=%c, sum=%d\n", i, curr, next, sum);

            if ((curr == 'I' && next == 'V') || (curr == 'I' && next == 'X') || (curr == 'X' && next == 'L') || (curr == 'X' && next == 'C') || (curr == 'C' && next == 'D') || (curr == 'C' && next == 'M')) {
                int specialNum = romanNum.get(next) - romanNum.get(curr);
                sum = sum + specialNum;

                i += 2; // skip i for the special pairs

//                check if i overflow s len -> reaching the end of the string
//                if (i >= s.length() - 2) {
////                    sum += romanNum.get(s.charAt(s.length() - 1));
//                    overflowed = true;
//                }
            } else {
                sum = sum + romanNum.get(curr);
                i++;
            }
        }

//        if (overflowed) sum += romanNum.get(s.charAt(s.length() - 1));

        return sum;
    }
}