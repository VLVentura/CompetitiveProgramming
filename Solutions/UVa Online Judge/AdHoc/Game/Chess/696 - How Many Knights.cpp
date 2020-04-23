#include <bits/stdc++.h>

using namespace std;

int max_knights(int &n, int &m){
	if(n == 0 || m == 0){
		return 0;
	}
	else if(n == 1 || m == 1){
		return max(n,m);
	}
	else if(n == 2 || m == 2){
		int num = ((max(m,n)) / 4) * 4;
		if(max(m,n) % 4 == 1)
			num += 2;
		else if(max(m,n) % 4 > 1) 
			num += 4;
		return num;
	}
	else{
		return (n * m) % 2 == 0 ? (m * n) / 2 : ((m * n) + 1) / 2;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int n = 0, m = 0;
	while(cin >> n >> m && (n || m)){
		cout << max_knights(n,m) << " knights may be placed on a " << n << " row " << m << " column board.\n";
	}

	return 0;
}