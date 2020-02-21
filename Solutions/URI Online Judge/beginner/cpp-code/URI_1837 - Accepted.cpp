#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int a, b, q, r;
	
	cin >> a >> b;

	if(a < 0 && b > 0)
		q = floor(static_cast<float> (a) / b);
	else if(a > 0 && b < 0)
		q = ceil(static_cast<float> (a) / b);
	else if((a > 0) && (b > 0))
		q = floor(static_cast<float> (a) / b);
	else
		q = ceil(static_cast<float> (a) / b);
	
	r = a - (q * b);

	cout << q << " " << r << endl;

	return 0;			
}