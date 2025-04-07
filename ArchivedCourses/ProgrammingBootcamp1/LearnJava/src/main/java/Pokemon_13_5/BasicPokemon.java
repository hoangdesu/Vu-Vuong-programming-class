package Pokemon_13_5;

public class BasicPokemon extends Pokemon {
    private String attack = "kick";
    public BasicPokemon() {
    }

    public BasicPokemon(String type, int id) {
        super(type, id);
    }

    public String toString() {
        return String.format("%s:%s:%b", this.getIdentification(), this.attack, this.hasTrainer());
    }
}
