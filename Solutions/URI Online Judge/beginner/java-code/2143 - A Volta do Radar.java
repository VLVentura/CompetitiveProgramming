import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 2162
class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		while(true) {
			int c = read.nextInt();
			if(c == 0) break;

			while(c > 0) {
				int n = read.nextInt();

				if((n & 1) != 0) {
					System.out.println((n - 1) * 2 + 1);
				}
				else {
					System.out.println((n - 2) * 2 + 2);
				}

				c--;
			}

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