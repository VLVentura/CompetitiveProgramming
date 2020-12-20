import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 2140
class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		final int[] v = new int[] {2, 5, 10, 20, 50, 100};

		while(true) {
			int n = read.nextInt();
			int m = read.nextInt();
			if(n == 0 && m == 0) break;

			int cnt = 0;
			int num = m - n;
			int i = v.length - 1;

			while(i >= 0 && cnt < 2) {
				if(v[i] > num) {
					i--;
				}
				else {
					num -= v[i];
					cnt++;
				}
			}

			if(cnt == 2 && num == 0) {
				System.out.println("possible");
			}
			else {
				System.out.println("impossible");
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