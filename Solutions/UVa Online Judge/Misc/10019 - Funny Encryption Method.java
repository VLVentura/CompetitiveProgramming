import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();

        while(n > 0) {
            int m = in.nextInt();

            String mBinary = Integer.toBinaryString(m);
            String mHex = Integer.toBinaryString(Integer.parseInt(Integer.toString(m), 16));

            System.out.println(countOnes(mBinary) + " " + countOnes(mHex));

            n--;
        }

        in.close();
    }

    private static long countOnes(String s) {
        return s.chars()
                .filter(c -> {
                    if(Integer.compare(c, '1') == 0) return true;
                    return false;
                })
                .count();
    }
}