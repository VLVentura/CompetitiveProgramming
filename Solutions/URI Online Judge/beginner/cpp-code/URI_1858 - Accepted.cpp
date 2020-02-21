#include <iostream>
#include <string>

using namespace std;

int main(){

	int n, t, menor = 20, indice = 1;

	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> t;
	
		if(t < menor){
			menor = t;
			indice = i;
		}
	}
	
	
	cout << indice << endl;	

	return 0;			
}