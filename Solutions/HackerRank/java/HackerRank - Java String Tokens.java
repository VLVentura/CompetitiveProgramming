import java.io.*;
import java.util.*;

public class Solution {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.nextLine().trim();
		// Write your code here.
		String[] arr = s.split("[!,?._'@\\s]+");
		if(s.length() > 0) {
			System.out.println(arr.length);
			Arrays.stream(arr).forEach(System.out::println);
		}
		else {
			System.out.println(0);
		}
		scan.close();
	}
}