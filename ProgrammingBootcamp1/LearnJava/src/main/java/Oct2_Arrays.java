import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Oct2_Arrays {
    public static void main(String[] args) {

//        StringBuilder result = new StringBuilder();
//        for (int i = 0; i < 10; i++) {
//            result.append("a"); // memory wasted
//        }
//
//        System.out.println(result.toString());
//
////        Static array: fixed length
////        String: static array of characters - "Vương"
//
//        String name = "Vương";
//        name += " Vũ";
//        name += " Nguyễn";
//
//        System.out.println(name);

//        2. Dynamic array (động): varied length

//        must use Wrapper type
        ArrayList<String> games = new ArrayList<>(); // 2nd  <> can be empty -> type will be inferred

        // add to the end of the array
        games.add("League of Legends");
        games.add("Valorant");

        games.addAll(List.of("Black Myth Wukong", "GTA 6"));

        System.out.println(games.get(1));

        System.out.println(games.size());

        System.out.println(games.contains("Valorant"));

        System.out.println(games.indexOf("GTA 6"));
        System.out.println(games.indexOf("Ori and the blind forest"));


        ArrayList<String> games2 = new ArrayList<>(List.of("League of Legends", "Valorant", "Black Myth Wukong", "GTA 6"));
        System.out.println("equals(): " + games.equals(games2)); // deep equal using elements
        System.out.println("== " + (games == games2)); // memory address

//        remove by value vs remove by index
//        mutable operations: work directly on the object
//        System.out.println("removing gta6: " + games.remove("GTA 6")); // value -> bool
//        System.out.println("removing index 1: " + games.remove(1)); // index -> removed value

//        System.out.println(games.remove("CSGO")); // false

//        games.set(3, "Ori and the blind forest");
        @SuppressWarnings("unchecked")
        ArrayList<String> games3 = (ArrayList<String>) games.clone();
        System.out.println("games3: " + games3);

        ArrayList<String> safeClonedGames = new ArrayList<>();
        for (String game : games) {
            safeClonedGames.add(game);
        }
        System.out.println("safeClonedGames: " + safeClonedGames);


//        System.out.println(games.remove(10));

//        avoid code from stopping
//        try {
//            System.out.println(games.remove(10)); // error -> must use a valid index
//        } catch (Exception e) {
//            System.out.println("Error removing index 10");
//        } finally {
//            System.out.println("Inside finally block");
//        }


//        ==:
//            primitive: evaluate their values
//            wrapper: evaluate their memory addresses

        String name = "Vuong";
//        String name2 = "Vuong";

//        System.out.print("Enter your name: ");
//        Scanner sc = new Scanner(System.in);
//        String name3 = sc.nextLine();

//        ex1:
//        System.out.println();

//        if (name == "Vuong") {
//            System.out.println("Hi Vuong");
//            System.out.println(name == "Vuong");
//        }

//        System.out.println(name == "Vuong");
//        System.out.println(name == name2);
//        System.out.println("name3 = " + name3 + ": " + (name == name3));
//        System.out.println("name3 = " + name3 + "equals(): " + (name.equals(name3)));


//        String characters are immutable
        String name4 = "Brian";
        name4 = "Bryan";
        name4 = name4.toUpperCase(); // immutable operations
        System.out.println(name4.charAt(2));
        System.out.println(name4.substring(1, 4));


        System.out.println(games);


    }
}

