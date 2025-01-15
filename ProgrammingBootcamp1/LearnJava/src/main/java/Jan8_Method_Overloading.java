public class Jan8_Method_Overloading {
    public static void main(String[] args) {
        sayHello(); // hello word
        sayHello("Vuong"); // hello Vuong
    }

    public static void sayHello() {
        System.out.println("hello word");
    }

    public static void sayHello(String name) {
        System.out.println("hello " + name);
    }


}
