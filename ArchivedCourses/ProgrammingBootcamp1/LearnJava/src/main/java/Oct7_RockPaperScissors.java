import java.util.Arrays;
import java.util.Scanner;

public class Oct7_RockPaperScissors {
    public static void main(String[] args) {
//        String[]
//        while / for
//        conditional

//        String[] moves = {"a", "b", "c"};
//        String[] moves = new String[]{"a", "b", "c"};

//        System.out.println(Arrays.toString(moves));
//        for (int i = 0; i < 10; i++) {
//            System.out.println(Math.random()); // 0.0 -> 0.99
//        }


        String[] moves = {"rock", "paper", "scissors"}; // r: 0, p: 1, s: 2

//        System.out.println(Math.floor(1.9));
//        System.out.println(Math.ceil(1.01));

        Scanner sc = new Scanner(System.in);

//        int randomIndex = (int) (Math.random() * moves.length); // 0 -> 2
//        System.out.println("Bot: " + moves[randomIndex]);

        while (true) {
            int randomIndex = (int) (Math.random() * moves.length);
            String botMove = moves[randomIndex];

            System.out.print("User: ");
            String userMove = sc.nextLine();

//            System.out.println(botMove);

//            if (userMove.equals("rock") && botMove.equals("rock")) {
//                System.out.println("Draw");
//            } else if (userMove.equals("rock") && botMove.equals("paper")) {
//                System.out.println("Bot wins");
//            }

            if (userMove.equals("rock")) {
                if (botMove.equals("rock")) {
                    System.out.println("Draw");
                } else if (botMove.equals("paper")) {
                    System.out.println("Bot wins");
                } else if (botMove.equals("scissors")) {
                    System.out.println("Player wins");
                }
            } else if (userMove.equals("paper")) {
                if (botMove.equals("rock"))  {

                }
            } else if (userMove.equals("scissors")) {

            }

        }





    }
}
