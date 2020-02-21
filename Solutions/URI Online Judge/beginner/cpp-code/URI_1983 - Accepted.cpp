#include <iostream>

using namespace std;

int main(){

	int n, flag = 0, pos = 0;

	cin >> n;

	unsigned long long int v[n];
	float m[n], mai = 0.0;

	for(int i = 0; i < n; i++){
		cin >> v[i] >> m[i];

		if(m[i] < 8.0)
			flag++;
		else{
			if(m[i] > mai){
				mai = m[i];
				pos = i;
			}
		}
	}

	if(flag == n)
		cout << "Minimum note not reached" << endl;
	else
		cout << v[pos] << endl;


	return 0;		
}