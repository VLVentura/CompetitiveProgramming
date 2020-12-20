import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		int t;
		while(true) {
			try {
				t = read.nextInt();
			}
			catch (NullPointerException e) {
				break;
			}

			int cases = 2 * t;
			List<String[]> exp = new ArrayList<>();
			List<String> people = new ArrayList<>();
			while((cases--) > 0) {
				if(cases < t) {
					String[] s = read.nextLine().split(" ");
					if(!isCorrect(exp.get(Integer.parseInt(s[1]) - 1), s[2])) {
						people.add(s[0]);
					}
				}
				else {
					exp.add(read.nextLine().replace("=", " ").split(" "));
				}
			}

			if(people.size() == 0){
				System.out.println("You Shall All Pass!");
			}
			else if(people.size() == t) {
				System.out.println("None Shall Pass!");
			}
			else {
				Collections.sort(people);
				for(int i = 0; i < people.size(); ++i) {
					System.out.print(people.get(i));
					if(i != people.size() - 1) {
						System.out.print(" ");
					}
				}
				System.out.println();
			}
		}


	}
	static boolean isCorrect(String[] exp, String op) {
		int a = Integer.parseInt(exp[0]);
		int b = Integer.parseInt(exp[1]);
		int c = Integer.parseInt(exp[2]);

		if(op.compareTo("+") == 0) {
			return a + b == c;
		}
		else if(op.compareTo("-") == 0) {
			return a - b == c;
		}
		else if(op.compareTo("*") == 0) {
			return a * b == c;
		}
		else {
			return !((a + b == c) || (a - b == c) || (a * b == c));
		}
	}
	static class FastReader {
		BufferedReader br;
		private StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				}
				catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			}
			catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}
}