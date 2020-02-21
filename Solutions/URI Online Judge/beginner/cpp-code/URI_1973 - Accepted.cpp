#include <iostream>

using namespace std;

int main(){

	unsigned long long int n, x = 0, aux;
	int flag = 0, stars = 0, count = 0;

	cin >> n;

	unsigned long long int v[n];

	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	while((count >= 0) && (count < n)){

		if(v[count] > 0)
			aux = v[count] - 1;
		else
			aux = 0;
		v[count] = aux;

		if(((v[count]+1) % 2 != 0) && (flag == 0)){
			count++;
			stars++;

		} else{
			count--;
			flag++;
		}
	}
	
	for(int i = 0; i < n; i++)
		x = v[i] + x;
	if(count < 0)
		stars++;

	cout << stars << " " << x << endl;

	return 0;
		
}


