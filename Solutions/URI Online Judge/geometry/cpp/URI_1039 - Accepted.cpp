#include <iostream>
#include <cmath>

using namespace std;
	
double distance(int x1, int x2, int y1, int y2);

int main(){

	int r1{0}, r2{0}, x1{0}, x2{0}, y1{0}, y2{0};

	while(cin >> r1 >> x1 >> y1 >> r2 >> x2 >> y2){

		double d = distance(x1,x2,y1,y2);
		if(d <= r1 - r2)
			cout << "RICO" << endl;
		else
			cout << "MORTO" << endl;
	}

	return 0;	
}
			
double distance(int x1, int x2, int y1, int y2){
	int a = pow(x1 - x2, 2);
	int b = pow(y1 - y2, 2);

	return sqrt(a + b);
}