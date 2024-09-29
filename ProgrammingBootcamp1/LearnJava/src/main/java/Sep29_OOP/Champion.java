package Sep29_OOP;

//blueprint / design
public class Champion {
    // encapsulation: tính đóng gói
    private String name;
    private String[] lanes;
    private String skin = "default";

    // constructor (must be public)
    public Champion(String name, String[] lanes) {
        this.name = name;
        this.lanes = lanes;
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

//    get user.name;
//    user.setPassword();
//    user.getPassword();
}
