#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int N, v;

	while(cin >> N && N != EOF){

		int vm = 1;
		
		for(int i = 0; i < N; i++){
			cin >> v;

			if(v > vm)
				vm = v;
		}

		if(vm < 10)
			cout << "1" << endl;
		else if(vm >= 10 && vm < 20)
			cout << "2" << endl;
		else if(vm >= 20)
			cout << "3" << endl;
	}	

	return 0;			
}