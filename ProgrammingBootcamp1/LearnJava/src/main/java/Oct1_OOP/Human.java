package Oct1_OOP;

public class Human implements SpeciesInterface, HumanInterface, ISapien {
    public void sleep() {
        System.out.println("zzz");
    }
    @Override
    public void eat() {
        System.out.println("human eat cooked food");
    }

    @Override
    public void playGame() {
        System.out.println("human play game");
    }

    @Override
    public void hunt() {
        System.out.println("san bat hai luom");
    }
}
