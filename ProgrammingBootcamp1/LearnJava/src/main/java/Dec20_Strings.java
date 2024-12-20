public class Dec20_Strings {
    public static void main(String[] args) {
        System.out.println(slugify("Atehea - Disposable and Waterproof Hygienic Pillow Cases"));
        System.out.println(slugify2("Atehea - Disposable and Waterproof Hygienic Pillow Cases"));
    }


//    Regular expression
    public static String slugify(String s) {
        return s.toLowerCase().replaceAll("[^a-zA-Z\\s]", "").replaceAll("\\s+", "-");
    }

    public static String slugify2(String ogStr) {
        StringBuilder sb = new StringBuilder();

        final int distanceBetweenUpperToLower = 32;

        boolean hasHyphen = false;

        for (int i = 0; i < ogStr.length(); i++) {
            char c = ogStr.charAt(i);
            boolean isUpperCase = c >= 65 && c <= 90;

            if (isUpperCase) c += distanceBetweenUpperToLower;

//            c += (char) (isUpperCase ? distanceBetweenUpperToLower : 0);

            boolean isValidChar = c >= 97 && c <= 122;
            if (isValidChar) {
                sb.append((char) c);
                hasHyphen = false;
            } else if (!isValidChar && !hasHyphen) {
                sb.append("-");
                hasHyphen = true;
            }
        }

        return sb.toString();
    }
}

//JSON
//Web scraping
//Files
