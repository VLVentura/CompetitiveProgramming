#include <iostream>
#include <cmath>

using namespace std;

int main(){

	unsigned long int N;

	cin >> N;

	for(int i = 1; i <= N; i++){
		cout << "Ho";
		if(i == N)
			cout << "!";
		else
			cout << " ";
	}

	cout << endl;

	return 0;			
}