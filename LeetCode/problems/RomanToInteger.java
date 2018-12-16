import java.util.HashMap;
import java.util.Map;

public class RomanToInteger {
    public int romanToInt(String s) {
        int s_len = s.length();
        int sum = 0;
        Map<Character, Integer> ROMAN = new HashMap<Character, Integer>();
        ROMAN.put('I', 1);
        ROMAN.put('V', 5);
        ROMAN.put('X', 10);
        ROMAN.put('L', 50);
        ROMAN.put('C', 100);
        ROMAN.put('D', 500);
        ROMAN.put('M', 1000);

        for (int i = 0; i < s_len; i++) {
            if (i < s_len-1 && ROMAN.get(s.charAt(i)) < ROMAN.get(s.charAt(i+1))) {
                int diff = ROMAN.get(s.charAt(i+1)) - ROMAN.get(s.charAt(i));
                sum += diff;
                i++;
            } else {
                sum += ROMAN.get(s.charAt(i));
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        RomanToInteger test1 = new RomanToInteger();
        System.out.println(test1.romanToInt("MCMXCIV"));
    }

}

