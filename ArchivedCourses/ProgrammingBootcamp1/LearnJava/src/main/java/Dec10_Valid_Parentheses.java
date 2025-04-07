public class Dec10_Valid_Parentheses {
    public static void main(String[] args) {
//        if ((true)) {
//            System.out.println("True");
//        }


//        ([{  }]) -> balanced
//
//        ([)] -> unbalanced

        System.out.println(isParenthesesBalance("( :D [{}]:D )")); // true

//        System.out.println(isParenthesesBalance("{ hehe (  :D [h]o)h }o")); // true

    }

    public static boolean isParenthesesBalance(String code) {
//        return false;
        int headPointer = 0;
        int tailPointer = code.length() - 1;

        while (headPointer <= tailPointer) {
            char headChar = code.charAt(headPointer);
            char tailChar = code.charAt(tailPointer);

            if (headChar == '(' && tailChar != ')') {
                return false;
            } else if (headChar == '[' && tailChar != ']') {
                return false;
            } else if (headChar == '{' && tailChar != '}') {
                return false;
            }

            System.out.println("head char: " + headChar);
            System.out.println("tail char: " + tailChar);

            headPointer++;
            tailPointer--;

        }

        return true;


//        if char == '}'
//                if stack.pop() != '{'
//                    return false

    }
}
