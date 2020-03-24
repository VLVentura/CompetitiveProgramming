#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int M{0}, deprec_t{0};
	double P{0.0}, B{0.0};
	vector<pair<int,double>> historical;

	while(scanf(" %d %lf %lf %d", &M, &P, &B, &deprec_t), (M >= 0)){
		while(deprec_t--){
			pair<int, double> temp;
			scanf(" %d %lf", &temp.first, &temp.second);
			historical.push_back(temp);
		}

		int index{0}, time{0};
		double owes{B}, carValue{(B+P)-(B+P)*historical[index].second}, valueMonth{B/M};
		while(time < M  && owes >= carValue){
			++time;
			if(index < historical.size() - 1) time == historical[index + 1].first ? ++index : index = index;
			owes -= valueMonth;
			carValue -= carValue*historical[index].second;
		}
		printf("%d ", time);
		time != 1 ? printf("months\n") : printf("month\n");
		historical.clear();
	}	

	return 0;
}