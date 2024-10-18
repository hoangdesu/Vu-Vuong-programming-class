import java.util.ArrayList;

public class Oct14_ASCII {
    public static void main(String[] args) {
        System.out.println((int) 'A');

        int num = 122;
        System.out.println(num); // 122
        System.out.println((char) num); // z

        // Escape characters \ (backward slash)
        System.out.println("a\nb");

        // \^o^/
        System.out.println("\\^o^/");

        System.out.println("haha\thehe"); // tab = 4 spaces


        String name = null;
        System.out.println(name);

        String plainText = "xyz";

        // encrypt: plaintext -> key -> encrypt -> cipher
        // decrypt: cipher -> key -> plaintext

//        symmetric encryption: caesar cipher

        int key = 16; // shift every char 3 places to the right

//        -> cipher = "cde";

        String cipher = simpleEncrypt(plainText, key);
        System.out.println("Cipher = " + cipher);

        String decryptedplainText = simpleDecrypt(cipher, key);

//        if overflow from the defined range, we loop back
//        accepted range: 65 - 90
//
//        XYZ -> 88, 89, 90
//        key = +3
//
//        91, 92, 93 -> overflown
//        65, 66, 67
//
//        find the difference: 91 - 91 (accepted upperbound) = 0 (starting point start from 1)
//        lowerbound: 65 + difference = 65 -> A
//
//        92 - 91 = 1
//        65 + 1 = 66 -> B

        System.out.println(92 % 91);

        System.out.println('A'); // A
        System.out.println('A' + 3); // int

//        ASKDKAS(7&^*ASD) -> decrypt

        String cipher2 = encrypt("hi! how u doing?", 1);
        System.out.println(cipher2);

        System.out.println(encrypt("xYz", 3));

        String msg = encrypt("COnGratulations! You just wasted 5s reading this Meaningless message ehehe", 7);
        System.out.println(msg);

    }

    public static String simpleEncrypt(String plainText, int key) {
        StringBuilder cipher = new StringBuilder();

        for (int i = 0; i < plainText.length(); i++) {
            char plainChar = plainText.charAt(i);
            int plainAscii = (int) plainChar;
            int encryptedAscii = plainAscii + key;
            char encryptedChar = (char) encryptedAscii;
            cipher.append(encryptedChar);
        }

        return cipher.toString();
    }

    public static String simpleDecrypt(String cipher, int key) {
        return "";
    }

//    public static ArrayList<String> bruteForceDecrypt(String cipher) {
//        "abc"
//
//        key 1: zab
//        key 2: yza
//        key 3: xyz
//
//
//        return "";
//    }

//    encrypt:
//    - Uppercase: 65-90
//    - Lowercase: 97-122
//
//    hi! how u doing?
//    key = 1
//    ij! ipx v epjoh?

    public static String encrypt(String plainText, int key) {
        StringBuilder cipher = new StringBuilder();

        for (int i = 0; i < plainText.length(); i++) {
            char plainChar = plainText.charAt(i);
            int plainAscii = (int) plainChar;

            boolean isLowerCase = plainAscii >= 97 && plainAscii <= 122;
            boolean isUpperCase = plainAscii >= 65 && plainAscii <= 90 ;

            int lowerCaseUpperBound = 123;
            int upperCaseUpperBound = 91;

//            starting positions
            int lowerCaseLowerBound = 97;
            int upperCaseLowerBound = 65;

//            only encrypt alphabet chars
            int encryptedAscii = plainAscii;
            if (isLowerCase) {
                encryptedAscii = (plainAscii + key) % lowerCaseUpperBound;
                if (encryptedAscii < lowerCaseLowerBound) encryptedAscii += lowerCaseLowerBound;
            }

            if (isUpperCase) {
                encryptedAscii = (plainAscii + key) % upperCaseUpperBound;
                if (encryptedAscii < upperCaseLowerBound) encryptedAscii += upperCaseLowerBound;
            }



            char encryptedChar = (char) encryptedAscii;
            System.out.printf("Char: %c | Plain ascii: %d | Encrypted ascii: %d | Encrypted char: %c\n", plainChar, plainAscii, encryptedAscii, encryptedChar);
            cipher.append(encryptedChar);
        }

        return cipher.toString();
    }




}
