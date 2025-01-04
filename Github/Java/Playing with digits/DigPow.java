public class DigPow {
    public static long digPow(int n, int p) {
        String digits = String.valueOf(n);
        long sum = 0;

        for (int i = 0; i < digits.length(); i++) {
            int digit = Character.getNumericValue(digits.charAt(i));
            sum += Math.pow(digit, p + i);
        }

        return sum % n == 0 ? sum / n : -1;
    }
}