package Sep29_OOP;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // logic
//        Scanner

        Champion yasuo = new Champion("Yasuo", new String[]{"mid", "top", "jungle", "ad", "support"});
        yasuo.introduce();

//        System.out.println(System.out.printf("haha"));
        Champion zed = new Champion("Zed", new String[]{"mid", "jungle"});
        zed.introduce();

//        zed.name
        System.out.println("My main is " + zed.getName());

//        support Yasuo

        System.out.println(yasuo.getLanes()[4] + " " + yasuo.getName());
//        zed.name = "Ahri"; // NOT ALLOWED TO RE-ASSIGN

        System.out.println("Zed skin: " + zed.getSkin());

        zed.setSkin("Debonair Zed");

        System.out.println("New Zed skin: " + zed.getSkin());

        SpecialChampion aphelios = new SpecialChampion("Aphelios", new String[]{"ad", "mid"});
        aphelios.introduce();

        aphelios.setSkin("HEARTSTEEL Aphelios");
        System.out.println(aphelios.getSkin());
    }
}
