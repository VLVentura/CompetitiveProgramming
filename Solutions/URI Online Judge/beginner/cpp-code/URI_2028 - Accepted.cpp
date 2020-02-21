#include <iostream>
#include <vector>

using namespace std;

int main(){

	int c = 0, n;

	while(cin >> n && n != EOF){
		c++;

		vector<int> v;
		v.push_back(0);

		for(int i = 0; i <= n; i++){
			for(int j = 0; j < i; j++)
				v.push_back(i);
		}

		cout << "Caso " << c << ": " << v.size() << " numero";
		if(v.size() != 1)
			cout << "s" << endl;
		else
			cout << endl;
		
		for(int i = 0; i < v.size(); i++){
			cout << v.at(i);
			if(i == v.size() - 1)
				cout << endl;
			else
				cout << " ";
		}
		
		cout << endl;
	}

	return 0;		
}
