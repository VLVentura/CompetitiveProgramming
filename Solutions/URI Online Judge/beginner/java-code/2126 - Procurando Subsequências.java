import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		int ncases = 1;
		String s, n;
		while(true) {
			try{
				s = read.next();
				n = read.next();
			}
			catch (NullPointerException e) {
				break;
			}

			int cnt = 0;
			int lastPos = 0;
			for(int i = 0; i < n.length(); i++) {
				int finalIndex = i + s.length();
				if(finalIndex <= n.length()){
					if(n.subSequence(i, finalIndex).toString().compareTo(s) == 0) {
						cnt++;
						lastPos = i;
					}
				}
				else {
					break;
				}
			}

			System.out.println((ncases == 1 ? "Caso #" : "Caso #") + ncases + ":");
			if(cnt != 0) {
				System.out.println("Qtd.Subsequencias: " + cnt);
				System.out.println("Pos: " + ++lastPos + "\n");
			}
			else {
				System.out.println("Nao existe subsequencia\n");
			}
			ncases++;
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