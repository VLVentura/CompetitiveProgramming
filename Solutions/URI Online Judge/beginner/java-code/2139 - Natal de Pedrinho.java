import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.Instant;
import java.util.Date;
import java.util.StringTokenizer;

class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		Date christmas = Date.from(Instant.parse("2016-12-25T00:00:00Z"));
		String format;
		int m, d;

		while(true) {
			try {
				m = read.nextInt();
				d = read.nextInt();
			}
			catch (NullPointerException e) {
				break;
			}

			Date date = Date.from(Instant.parse(getFormat(m, d)));
			long days = (christmas.getTime() - date.getTime()) / (1000 * 60 * 60 * 24);

			if(days == 0) {
				System.out.println("E natal!");
			}
			else if(days == 1) {
				System.out.println("E vespera de natal!");
			}
			else if(days > 0) {
				System.out.printf("Faltam %d dias para o natal!\n", days);
			}
			else {
				System.out.println("Ja passou!");
			}
		}
	}
	static String getFormat(int m, int d) {
		if(m < 10 && d < 10) {
			return String.format("2016-0%d-0%dT00:00:00Z", m, d);
		}
		else if(m < 10 && d >= 10) {
			return String.format("2016-0%d-%dT00:00:00Z", m, d);
		}
		else if(m >= 10 && d < 10) {
			return String.format("2016-%d-0%dT00:00:00Z", m, d);
		}

		return String.format("2016-%d-%dT00:00:00Z", m, d);
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