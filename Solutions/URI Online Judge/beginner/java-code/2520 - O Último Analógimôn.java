import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		int rows;
		int cols;

		while(true) {
			try {
				rows = read.nextInt();
				cols = read.nextInt();
			}
			catch (NullPointerException e) {
				break;
			}

			Pos player = new Pos();
			Pos analog = new Pos();

			for(int i = 0; i < rows; ++i) {
				for(int j = 0; j < cols; ++j) {

					int n = read.nextInt();
					if(n == 1) {
						player.x = i;
						player.y = j;
					}
					else if(n == 2) {
						analog.x = i;
						analog.y = j;
					}
				}
			}
			int ans = Math.max(player.x, analog.x) - Math.min(player.x, analog.x) +
					Math.max(player.y, analog.y) - Math.min(player.y, analog.y);
			System.out.println(ans);
		}


	}
	static class Pos {
		Integer x, y;
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