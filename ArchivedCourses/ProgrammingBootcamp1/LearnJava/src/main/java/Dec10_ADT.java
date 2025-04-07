import java.util.*;

public class Dec10_ADT {
    public static void main(String[] args) {
//        ADT: abstract data types

        Stack<String> stack = new Stack<>();
//
        stack.push("Marvel Rivals");
        stack.push("Screenbound");
        stack.push("Portal 2");

        System.out.println(stack);
        String removedGame = stack.pop();

        System.out.println(stack);
        System.out.println("Removed game: " + removedGame);


        ArrayList<String> games = new ArrayList<>();

        games.add("Marvel Rivals");
        games.add("Screenbound");
        games.add("Portal 2");

//        String removedGame = games.removeLast();
        String removedGame2 = games.remove(games.size() - 1);
        System.out.println(games);
        System.out.println("Removed game: " + removedGame2);



//        Queue<String> gamesToPlay = new LinkedList<>();
//
//        gamesToPlay.add("Screenbound");
//        gamesToPlay.add("Marvel Rivals");
//
//        System.out.println(gamesToPlay);
//
//        String finishedGame = gamesToPlay.remove();
//        System.out.println("Finished playing " + finishedGame);


//        ArrayList<String> gamesQueue = new ArrayList<>();
//
////        enqueue
//        gamesQueue.add("Screenbound");
//        gamesQueue.add("Marvel Rivals");
//
//
//        System.out.println(gamesQueue);
//
////        dequeue
//        String removed = gamesQueue.remove(0);
//        System.out.println("Finished playing " + removed);





    }
}
