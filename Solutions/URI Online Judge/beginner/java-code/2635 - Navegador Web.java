import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		int n;
		while(true) {
			try {
				n = read.nextInt();
			}
			catch (NullPointerException e) {
				break;
			}
			List<String> words = new ArrayList<>();
			while(n-- > 0) {
				words.add(read.next());
			}
			n = read.nextInt();
			while(n-- > 0) {
				String t = read.next();
				int nWords = 0;
				int size = 0;
				for(var s: words) {
					if(s.startsWith(t)){
						nWords++;
						size = Math.max(size, s.length());
					}
				}
				if(nWords != 0) {
					System.out.printf("%d %d\n", nWords, size);
				}
				else{
					System.out.println("-1");
				}
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