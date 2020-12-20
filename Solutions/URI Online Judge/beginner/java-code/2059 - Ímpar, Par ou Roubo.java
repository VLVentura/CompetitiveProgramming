import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		int n = read.nextInt();
		while((n--) != 0) {
			String s = read.nextLine();
			int one = read.nextInt();
			int two = read.nextInt();

			String[] words = s.split(" ");
			if(((one + two) & 1) == 0 && words[1].compareTo("PAR") == 0) {
				System.out.println(words[0]);
			}
			else if(((one + two) & 1) != 0 && words[1].compareTo("PAR") == 0) {
				System.out.println(words[2]);
			}
			else if(((one + two) & 1) == 0 && words[1].compareTo("IMPAR") == 0) {
				System.out.println(words[2]);
			}
			else if(((one + two) & 1) != 0 && words[1].compareTo("IMPAR") == 0) {
				System.out.println(words[0]);
			}
		}
	}
	static class FastReader {
		private final BufferedReader br;
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