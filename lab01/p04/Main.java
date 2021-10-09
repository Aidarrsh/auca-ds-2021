import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        while (inp.hasNextLine()) {
            String line = inp.nextLine();
            System.out.println(isPalidrome(line) ? "palidrome" : "not a palidrome");
        }
    }

    static boolean isPalidrome(String line) {
        StringBuilder builder = new StringBuilder();
        for (char c : line.toCharArray()) {
            if (Character.isLetter(c)) {
                builder.append(Character.toLowerCase(c));
            }
        }

        String tmp = builder.toString();
        builder.reverse();

        return builder.toString().equals(tmp);
    }
}