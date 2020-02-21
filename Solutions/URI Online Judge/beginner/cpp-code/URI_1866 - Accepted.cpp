#include <iostream>

using namespace std;

int main(){

	int n, m, c = 0;

	cin >> m;

	while(c < m){
		cin >> n;

		int s = 0;

		for(int i = 1; i <= n; i++){
			if(i % 2 != 0)
				s = s + 1;
			else
				s = s - 1;
		}
		cout << s << endl;
		c++;
	}

	return 0;			
}

