#include <bits/stdc++.h>

using namespace std;

#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
						stringstream _ss(_s);\
						istream_iterator<string> _it(_ss);\
						err(_it, args);}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << ": " << a << "] ";
	err(++it, args...);
}
#define debug(...) error(__VA_ARGS__); cout << "\n";

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	vector<pair<int,int>> coords = {{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};

	vector<string> field;
	string buffer;
	int rows, cols, cnt = 1;

	while((cin >> rows >> cols), rows || cols) {
		for(int i = 0; i < rows; ++i) {
			cin >> buffer;
			field.push_back(buffer);
		}

		if(cnt > 1) {
			cout << "\n";
		}

		cout << "Field #" << cnt++ << ":" << endl;
		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < cols; ++j) {
				if(field[i][j] != '*') {
					int mine = 0;
					for(auto coord: coords) {
						int r = i + coord.first;
						int c = j + coord.second;
						if((r >= 0 && r < rows) && (c >= 0 && c < cols) && (field[r][c] == '*')){
							mine++;
						}
					}
					field[i][j] = to_string(mine)[0];
				}
			}
			cout << field[i] << endl;
		}
		field.clear();
	}

	return 0;
}