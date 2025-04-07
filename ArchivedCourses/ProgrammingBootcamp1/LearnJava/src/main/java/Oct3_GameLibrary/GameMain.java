package Oct3_GameLibrary;

import java.util.Scanner;

public class GameMain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Command gameController = new Command();

        gameController.display1();
        System.out.print("Enter a command (1-5): ");
        String command = sc.nextLine();

        while (true) {
            if (command.equals("1")) {
                gameController.showAllGames();
            } else if (command.equals("2")) {
                System.out.print("Enter name of the games: ");
                String newGame = sc.nextLine();

                gameController.addNewGame(newGame);
                gameController.showAllGames();
            } else if (command.equals("3")) {
                System.out.print("Remove the name of the games: ");
                String removeGame = sc.nextLine();
                gameController.command3(removeGame);
                gameController.showAllGames();
            } else if (command.equals("4")) {
//                game.display4();
//                String numberStr = sc.nextLine();
//                int index = 0;
//                try {
//                    index = Integer.parseInt(numberStr);
//                } catch (Exception e) {
//                    System.out.println("Invalid game number");
//                    continue;
//                }
////                sc.nextLine();
//                if (index > 0 && index <= game.getGames().size()) {
//                    game.display4_1(index -1);
//                    String updateGame = sc.nextLine();
//                    game.command4(index -1 , updateGame);
//                    game.display4_2();
//                    game.showAllGames();
//                } else {
//                    System.out.println("Please try again!");
//                }

                System.out.print("Enter the game number to update: ");
                String gameNumberStr = sc.nextLine();
                int gameNumber = 0;

                try {
                    gameNumber = Integer.parseInt(gameNumberStr);
                } catch (Exception e) {
                    System.out.println("Invalid game number");
                    continue;
                }

                // TODO: Validate index before accessing, else error
                System.out.print("Enter new name for " + gameController.getGames().get(gameNumber - 1) + ": ");
                String newGame = sc.nextLine();

                boolean updatedOk = gameController.updateGame(gameNumber, newGame);

                if (updatedOk) {
                    gameController.showAllGames();
                    System.out.println("Updated name from " + gameController.beforeUpdate + " to " + gameController.afterUpdate);
                } else {
                    System.out.println("Updated failed");
                }

            } else if (command.equals("5")) {
                System.out.println("Exit");
                break;
            } else {
                System.out.print("Please input again: ");
            }
            command = sc.nextLine();
        }
    }
}