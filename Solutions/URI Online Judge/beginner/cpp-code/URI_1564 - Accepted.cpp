#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int N;

	while(cin >> N && N != EOF){
		
		cout << "vai ter ";

		if(N > 0)
			cout << "duas!" << endl;
		else
			cout << "copa!" << endl;
	}

	return 0;			
}