import java.util.*;

public class Dec11_ValidParentheses {
    public static void main(String[] args) {
        String code = "abc ([ { xyz }  ]) { :D }";
//        System.out.println(isParenthesesBalance(code)); // true
        System.out.println(isValidParentheses(code)); // true
    }

    public static boolean isParenthesesBalance(String code) {
//        Stack: Last in, First out (LIFO)
//        ADT: abstract data type
//        ArrayList => Stack
//        .push() & .pop()
//        => .add() & .removeLast()

        ArrayList<Character> parenStack = new ArrayList<>();

//        big O: O(n) - linear
        for (int i = 0; i < code.length(); i++) {
//            System.out.println(code.charAt(i));
            char c = code.charAt(i);
//
            if (c == '(' || c == '{' || c == '[') {
//                Last In
                parenStack.add(c);
                System.out.println("> added " + String.valueOf(c) + " to the stack");

            } else if (c == ')' || c == '}' || c == ']') {
                // First out
                char removedChar = parenStack.removeLast();
                if (c == ')' && removedChar != '(') return false;
                else if (c == '}' && removedChar != '{') return false;
                else if (c == ']' && removedChar != '[') return false;
                System.out.println("Current char: " + c);
                System.out.println("Removed: " + removedChar);
            }

            System.out.println("Stack in the loop: " + parenStack);

        }

        System.out.println("Stack after the loop: " + parenStack);


        return true;
    }

    public static boolean isValidParentheses(String code) {
        Map<String, String> pairs = Map.of(
                "}", "{",
                ")", "(",
                "]", "["
        );

//        System.out.println(pairs);
//        System.out.println(pairs.get(")"));

        Stack<String> stack = new Stack<>();

        Set<String> openBraces = Set.of("{", "(", "[");
        Set<String> closeBraces = Set.of("}", ")", "]");

        for (int i = 0; i < code.length(); i++) {
            String c = String.valueOf(code.charAt(i));

            if (openBraces.contains(c)) {
               stack.push(c);
            } else if (closeBraces.contains(c)) {
                String poppedOpenBrace = stack.pop();
                String equivalentOpenBrace = pairs.get(c);
//                System.out.printf("equivalentOpenBrace: %s - openBrace: %s\n", equivalentOpenBrace, openBrace);
                if (!poppedOpenBrace.equals(equivalentOpenBrace)) return false;
            }

            System.out.println("current stack: " + stack);
        }

        return true;
    }
}

