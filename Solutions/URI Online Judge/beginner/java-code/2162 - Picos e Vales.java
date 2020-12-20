import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

// 2162
class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		int n = read.nextInt();

		int old = 0;
		char[] arr = new char[n - 1];
		boolean same = true;

		for(int i = 0; i < n && same; ++i) {
			int actual = read.nextInt();
			if(i != 0) {
				if(actual > old) {
					arr[i - 1] = 'P';
				}
				else if(actual < old) {
					arr[i - 1] = 'V';
				}
				else {
					arr[i - 1] = 'S';
				}

				if(i >= 2) {
					if(arr[i - 1] == arr[i - 2] || arr[i - 1] == 'S') {
						same = false;
					}
				}
				else {
					if(arr[i - 1] == 'S') {
						same = false;
					}
				}

			}
			old = actual;
		}

		System.out.println((same) ? "1" : "0");
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