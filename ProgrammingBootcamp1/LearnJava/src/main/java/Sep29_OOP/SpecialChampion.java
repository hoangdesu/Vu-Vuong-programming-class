package Sep29_OOP;

//inheritance: tính kế thừa

//child class of parent class Champion
public class SpecialChampion extends Champion {
    public SpecialChampion(String name, String[] lanes) {
        super(name, lanes);
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