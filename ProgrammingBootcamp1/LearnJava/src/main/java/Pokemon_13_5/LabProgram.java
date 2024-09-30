package Pokemon_13_5;

public class LabProgram {
    public static void main(String[] args) {
        /**
         * Sample code has been provided as starting point to test your
         * implementation.
         *
         * IMPORTANT: This code will not compile until you write the classes being
         * instantiated here.
         * You may modify this code for faster testing purposes and exploration.
         * Adding undocumented public methods to your Pokemon, BasicPokemon & RarePokemon classes
         * may mean that the unit tests fail as our testing code will be unaware of your new
         * methods and therefore cannot call those methods.
         */

        // UNCOMMENT THE CODE BELOW ONCE YOU HAVE WRITTEN YOUR CODE TO TEST YOUR
        // IMPLEMENTATION

        System.out.println("Creating pokemons with valid values: fire, 2 and electric 1");
        BasicPokemon basicPokemon = new BasicPokemon("fire", 2);
        RarePokemon rarePokemon = new RarePokemon("electric", 1);
        System.out.println(basicPokemon.getIdentification()); // "fire 2"
        System.out.println(rarePokemon.getIdentification());

        // Should be converted to lower case row identifier
        System.out.println("\nCreating pokemons with valid values: Fire 2 and  ELECTRIC 1");
        basicPokemon = new BasicPokemon("Fire", 2);
        rarePokemon = new RarePokemon("ELECTRIC", 1);
        System.out.println(basicPokemon.getIdentification());
        System.out.println(rarePokemon.getIdentification());
//
//        // Should have number error
        System.out.println("\nShould have number error: fire 42 and electric 2000");
        basicPokemon = new BasicPokemon("fire", 42);
        rarePokemon = new RarePokemon("electric", 2000);
        System.out.println(basicPokemon.getIdentification());
        System.out.println(rarePokemon.getIdentification());
//
//        // Should not have trainer
        System.out.println("\nCheck status of pokemons without trainers");
        basicPokemon = new BasicPokemon("fire", 2);
        rarePokemon = new RarePokemon("electric", 1);
        System.out.println(basicPokemon.hasTrainer());
        System.out.println(rarePokemon.hasTrainer());
//
//        // Should return false as the pokemons have not yet been booked.
        System.out.println("\nCancel trainers should fail as pokemons do not have trainer yet");
        boolean regularCancelSuccessful = basicPokemon.removeTrainer();
        boolean premiumCancelSuccessful = rarePokemon.removeTrainer();
        System.out.println("Result: " + regularCancelSuccessful);
        System.out.println("Result: " + premiumCancelSuccessful);
//
        System.out.println("\nSetting trainers should succeed as pokemons do not have trainer yet");
//        // Status should change to booked.
        basicPokemon.setTrainer();
        rarePokemon.setTrainer();
        System.out.println(basicPokemon.hasTrainer());
        System.out.println(rarePokemon.hasTrainer());
//
        System.out.println("\nCancel trainers should succeed as pokemons have trainer");
//        // Status should change to unbooked.
        regularCancelSuccessful = basicPokemon.removeTrainer();
        premiumCancelSuccessful = rarePokemon.removeTrainer();
        rarePokemon.removeTrainer();
        System.out.println(regularCancelSuccessful);
        System.out.println(premiumCancelSuccessful);
        System.out.println(rarePokemon.removeTrainer());
//
        System.out.println("\nTesting toString");
        System.out.println(rarePokemon.toString());
        System.out.println(basicPokemon);

//        // Trainer should change to false.
        basicPokemon = new BasicPokemon("fire", 2);
        rarePokemon = new RarePokemon("electric", 1);
        System.out.println(basicPokemon);
        System.out.println(rarePokemon);
//
        System.out.println("\nTesting equals method");
//        System.out.println(basicPokemon == basicPokemon);
//        // Status should change to unbooked.
        basicPokemon = new BasicPokemon("fire", 2);
        BasicPokemon regularPokemon3 = new BasicPokemon("fire", 2);
        BasicPokemon regularPokemon2 = new BasicPokemon("Fire", 2);
        System.out.println("== " + (basicPokemon == regularPokemon3));
        System.out.println("equals(): " + basicPokemon.equals(regularPokemon3));
        rarePokemon = new RarePokemon("psychic", 1);
        System.out.println(basicPokemon.equals(basicPokemon));
        System.out.println(basicPokemon.equals(regularPokemon2));
        System.out.println(regularPokemon2.equals(regularPokemon3));

        BasicPokemon myPokemon = new BasicPokemon("fire", 43);
        System.out.println(myPokemon);
    }
}