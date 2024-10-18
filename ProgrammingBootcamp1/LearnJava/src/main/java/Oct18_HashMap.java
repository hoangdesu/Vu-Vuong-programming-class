import java.util.ArrayList;
import java.util.HashMap;

public class Oct18_HashMap {
    public static void main(String[] args) {
//               <key, value>
        HashMap<String, String> capitals = new HashMap<>();

        capitals.put("vietnam", "hanoi");
        capitals.put("japan", "kyoto");
        capitals.put("usa", "washington dc");

        System.out.printf("%s is the capital of %s\n", capitals.get("vietnam"), "vietnam");
        System.out.println("Korea capital: " + capitals.get("korea"));

//        capitals.remove("japan");
//        capitals.replace("japan", "tokyo");
        capitals.put("japan", "tokyo");
        System.out.println(capitals.get("japan"));

        System.out.println(capitals);

        System.out.println("keys: " + capitals.keySet());
        System.out.println("values: " + capitals.values());

        System.out.println(capitals.entrySet());

//        convert hashmap to set, then convert set to array for iteration
        ArrayList<String> keys = new ArrayList<>(capitals.keySet());
        for (int i = 0; i < keys.size(); i++) {
            String country = keys.get(i);
            System.out.printf("%d. %s is the capital of %s\n", i+1, capitals.get(country), country);
        }

        System.out.println(capitals.containsKey("italy"));

        System.out.println(capitals.size());


    }
//    "MCMXCV" = 1995
}
