#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int A, B, C;

	while(1){
		
		cin >> A;

		if(A != 0){
			cin >> B;
			if(B != 0){
				cin >> C;
				if(C == 0)
				 break;
			} else
				break;
		} else
			break;

		int area = (A * B) / (C / 100.00);

		cout << static_cast<int> (sqrt(area)) << endl;
	}

	return 0;			
}