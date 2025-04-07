package Sep29_OOP;

//inheritance: tính kế thừa

//child class of parent class Champion
public class SpecialChampion extends Champion {
    public SpecialChampion(String name, String[] lanes, int attack) {
        super(name, lanes, attack);
    }

//    method overriding
    @Override
    public void introduce() {
//        super.introduce();
        System.out.printf("%s goes %s\n", this.getName(), this.getLanes()[0]);
    }
}

//super: refer to parent class

//học() {
//    sách + vở
//}
//
//@Override
//học() {
//    laptop
//}