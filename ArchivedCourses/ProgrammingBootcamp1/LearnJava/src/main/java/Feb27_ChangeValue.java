public class Feb27_ChangeValue {
    public static class MyNumber {
        public int b = 2;
    }


    public static void main(String[] args) {
//        passing a primitive type to a function -> value is copied
        int a = 1;
        changeValue(a);
        System.out.println("a outside = " + a);

//        passing a reference type (wrapper type) into a function -> value is preserved
        MyNumber num = new MyNumber();
        System.out.println("Before change value: " + num.b);
        changeRefValue(num);
        System.out.println("After change b value = " + num.b);

    }

    public static void changeValue(int a) {
        a = 100;
        System.out.println("a inside = " + a);
    }

    public static void changeRefValue(MyNumber num) {
        num.b = 200;
        System.out.println("b inside function = " + num.b);
    }
}
