import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();

        while(n > 0) {
            Long l = in.nextLong();
            l = (((((l * 567) / 9) + 7492) * 235) / 47) - 498;
            if(l.toString().length() >= 2) {
                String s = l.toString();
                System.out.println(s.charAt(s.length() - 2));
            }
            else {
                System.out.println("0");
            }
            n--;
        }

        in.close();
    }
}