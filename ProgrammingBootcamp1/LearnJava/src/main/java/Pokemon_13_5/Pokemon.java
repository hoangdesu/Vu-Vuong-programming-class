package Pokemon_13_5;

public abstract class Pokemon {
    private String type;
    private int id = 0;

//    optional
    public Pokemon() {}

//    constructor overloading
//    this constructor only exists in Base class
    public Pokemon(String type, int id) {
        this.type = type;
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
}
