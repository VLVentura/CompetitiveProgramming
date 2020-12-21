import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class Main {
	public static void main(String[] args) {
		FastReader read = new FastReader();

		Map<Character, Character> cypher = new HashMap<>();
		int size;
		int cases;

		while(true) {
			try {
				size = read.nextInt();
				cases = read.nextInt();
			}
			catch (NullPointerException e) {
				break;
			}

			char[] arrOne = read.nextLine().toCharArray();
			char[] arrTwo = read.nextLine().toCharArray();

			for(int i = 0; i < size; ++i) {
				cypher.put(arrOne[i], arrTwo[i]);
				cypher.put(arrTwo[i], arrOne[i]);
			}

			while(cases-- > 0) {
				char[] s = read.nextLine().toCharArray();
				char[] ans = new char[s.length];

				for(int i = 0; i < s.length; ++i) {
					if(cypher.containsKey(Character.toUpperCase(s[i]))) {
						if(Character.isUpperCase(s[i])) {
							ans[i] = cypher.get(s[i]);
						}
						else if(Character.isLowerCase(s[i])) {
							ans[i] = Character.toLowerCase(cypher.get(Character.toUpperCase(s[i])));
						}
						else {
							ans[i] = Character.toLowerCase(cypher.get(s[i]));
						}
					}
					else {
						ans[i] = s[i];
					}
				}
				System.out.println(ans);
			}
			System.out.println();
			cypher.clear();
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