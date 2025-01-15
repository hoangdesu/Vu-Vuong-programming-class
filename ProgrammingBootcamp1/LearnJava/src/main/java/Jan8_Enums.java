import java.util.Scanner;

public class Jan8_Enums {

//    enumerate: limit options
    enum TRAFFIC_LIGHTS {
        RED,
        GREEN,
        YELLOW
    }

    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        System.out.print("Enter traffic light: ");

//        String light = sc.nextLine();

//        if (light.equals("red")) {
//            System.out.println("stop");
//        } else if (light.equals("green")) {
//            System.out.println("go");
//        } else if (light.equals("yellow")) {
//            System.out.println("slow down");
//        }

        TRAFFIC_LIGHTS light = TRAFFIC_LIGHTS.GREEN;

        if (light.equals(TRAFFIC_LIGHTS.RED)) {
            System.out.println("stop");
        } else if (light.equals(TRAFFIC_LIGHTS.GREEN)) {
            System.out.println("go");
        } else if (light.equals(TRAFFIC_LIGHTS.YELLOW)) {
            System.out.println("slow down");
        }
    }
}
