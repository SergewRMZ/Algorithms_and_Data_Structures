package helpers;
import java.util.Random;

public class RandomStrings {
    public static int generateNumber (int n) {
        Random rand = new Random();
        return rand.nextInt(n) + 1;
    }
    
    public static String randomBinaryString() {
        StringBuilder string = new StringBuilder();

        int value = generateNumber(6);
        for (int i = 0; i < value; i++) {
            string.append('0');
        }

        int value_2 = generateNumber(6);
        for (int i = value; i < value_2; i++) {
            string.append('1');
        }
        
        return string.toString();
    } 
}