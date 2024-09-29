package Sep29_OOP;

//blueprint / design
public class Champion {
    // encapsulation: tính đóng gói
    private String name;
    private String[] lanes;
    private String skin = "default";

    private int health = 100;


    private boolean alive = true;
    private int attack;


    // constructor (must be public)
    public Champion(String name, String[] lanes, int attack) {
        this.name = name;
        this.lanes = lanes;
        this.attack = attack;
    }

//    access private fields via a public method
    public void introduce() {
        System.out.printf("Champion name: %s | Most suitable lane: %s\n", this.name, this.lanes[0]);
    }

//    Getter / Setter
    public String getName() {
        return this.name;
    }

    public String[] getLanes() {
        return this.lanes;
    }

    public String getSkin() {
        return this.skin;
    }

//    setter: void
    public void setSkin(String newSkin) {
        this.skin = newSkin;
    }

    public int getHealth() {
        return health;
    }

    public void setHealth(int health) {
        this.health = health;
    }

    public boolean isAlive() {
        return alive;
    }

    public void setAlive(boolean alive) {
        this.alive = alive;
    }

    public void attack(Champion opponentChampion) {
        int newHealth = opponentChampion.getHealth() - this.attack;
        if (newHealth >= 0) {
            opponentChampion.setHealth(newHealth);
        } else {
            opponentChampion.setHealth(0);
            opponentChampion.setAlive(false);
        }
    }
//    get user.name;
//    user.setPassword();
//    user.getPassword();
}
