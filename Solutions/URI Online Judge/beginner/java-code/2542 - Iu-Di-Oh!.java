import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		int nAtt, nMarcos, nLeonardo;

		while(true) {
			try {
				nAtt = read.nextInt();
				nMarcos = read.nextInt();
				nLeonardo = read.nextInt();
			}
			catch (NullPointerException e) {
				break;
			}

			List<List<Integer>> marcos = new ArrayList<>();
			List<List<Integer>> leonardo = new ArrayList<>();

			for(int i = 0; i < nMarcos; ++i) {
				List<Integer> att = new ArrayList<>();
				for(int j = 0; j < nAtt; ++j) {
					att.add(read.nextInt());
				}
				marcos.add(att);
			}

			for(int i = 0; i < nLeonardo; ++i) {
				List<Integer> att = new ArrayList<>();
				for(int j = 0; j < nAtt; ++j) {
					att.add(read.nextInt());
				}
				leonardo.add(att);
			}

			int mCard = read.nextInt() - 1;
			int lCard = read.nextInt() - 1;
			int att = read.nextInt() - 1;

			int res = marcos.get(mCard).get(att).compareTo(leonardo.get(lCard).get(att));
			if(res == 0) {
				System.out.println("Empate");
			}
			else if(res < 0) {
				System.out.println("Leonardo");
			}
			else {
				System.out.println("Marcos");
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