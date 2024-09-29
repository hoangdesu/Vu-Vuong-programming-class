public class Sep29_Methods {
    public static void main(String[] args) {
//        System.out.println("Hi");
        hi();
        hi("Vương");
    }

    public static void hi() {
        System.out.println("Hiiiii!");
    }

//    method overloading
//    different method signature
    public static void hi(String name) {
        System.out.println("Hiii " + name);
    }
}
