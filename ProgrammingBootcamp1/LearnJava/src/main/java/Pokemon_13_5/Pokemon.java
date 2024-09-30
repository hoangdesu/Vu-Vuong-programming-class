package Pokemon_13_5;

import java.util.Objects;

public abstract class Pokemon {
    private String type = "n/a";
    private int id = 0;
    private boolean hasTrainer = false;

    private String[] validTypes = {"psychic", "water", "fire", "electric"};

//    optional
    public Pokemon() {}

//    constructor overloading
//    this constructor only exists in Base class
    public Pokemon(String type, int id) {

//        validate type before assignment

//        if (!type.equals("psychic") || !...) -> too long
        for (String validType : validTypes) {
            if (type.equals(validType)) {
                this.type = type;
                break;
            }
        }


//        this.type = type;
//        this.id = id; -> cannot directly assign like this

//        validate data before assignment
//        if ((id >= 1 && id <= 1000) && (id % 42 != 0 || id % 73 != 0))
//        else {...}

//        System.out.println("id mod 42:" + (id % 42));
        if (id >= 1 && id <= 1000) {
//            not gonna cover all the cases e.g. 84
            if (id < 73) {
                if (id % 42 != 0) this.id = id;
            } else {
                if (id % 73 != 0) this.id = id;
            }
//            else {
//                this.id = 0;
//            } -> violate DRY principle
//
        }
//        else {
//            this.id = 0;
//        } -> violate DRY principle
    }

    public String getIdentification() {
//        System.out.printf("type: %s | id: %s");
        return String.format("%s %d", type, id);
//        return -> "string"
    }

    public boolean hasTrainer() {
        return this.hasTrainer;
    }

    public boolean removeTrainer() {
        if (this.hasTrainer) {
            this.hasTrainer = false;
            return true;
        }

        return false;
    }

    public boolean setTrainer() {
        if (!this.hasTrainer) {
            this.hasTrainer = true;
            return true;
        }
        return false;
    }

    @Override
//    special method
    public String toString() {
        return "Pokemon{" +
                "type='" + type + '\'' +
                ", id=" + id +
                ", hasTrainer=" + hasTrainer +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pokemon pokemon = (Pokemon) o;
        return id == pokemon.id && hasTrainer == pokemon.hasTrainer && Objects.equals(type, pokemon.type);
    }

}
