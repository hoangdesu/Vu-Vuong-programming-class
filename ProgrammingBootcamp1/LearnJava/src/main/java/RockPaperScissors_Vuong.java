import java.util.Scanner;

public class RockPaperScissors_Vuong {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] moves = {"rock", "paper", "scissors"};
        int scores = 0;
        while (true) {
            // generate a random bot move
            int indexNum = (int) (Math.random() * moves.length);
            String moveBot = moves[indexNum];

            // getting player move
            System.out.print("Player: ");
            String movePlayer = sc.nextLine().toLowerCase();

            if (movePlayer.equals("rock")) {
                System.out.println("Bot: " + moves[indexNum]);
                if (moveBot.equals("rock")) {
                    System.out.println("Draw!");
                } else if (moveBot.equals("paper")) {
                    System.out.println("Bot win");
                    scores -= 1;
                } else if (moveBot.equals("scissors")) {
                    System.out.println("Player win");
                    scores += 1;
                }
            } else if (movePlayer.equals("paper")) {
                System.out.println("Bot: " + moves[indexNum]);
                if (moveBot.equals("rock")) {
                    System.out.println("Player win");
                    scores += 1;
                } else if (moveBot.equals("paper")) {
                    System.out.println("Draw!");
                } else if (moveBot.equals("scissors")) {
                    System.out.println("Bot win");
                    scores -= 1;
                }
            } else if (movePlayer.equals("scissors")) {
                System.out.println("Bot: " + moves[indexNum]);
                if (moveBot.equals("rock")) {
                    System.out.println("Bot win");
                    scores -= 1;
                } else if (moveBot.equals("paper")) {
                    System.out.println("Player win");
                    scores += 1;
                } else if (moveBot.equals("scissors")) {
                    System.out.println("Draw!");
                }
            } else if (movePlayer.equals("exit")) {
                System.out.println("Final Score: " + scores);
                break;
            } else  {
                System.out.println("Please type: rock, paper, scissors or exit" );
            }

            System.out.println("Score: " + scores);
        }
    }
}