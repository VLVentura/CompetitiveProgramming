#include <bits/stdc++.h>

using namespace std;

int main(){
	
	size_t n{0}	, m{0}, c{0}, tc{1}, device_cons{0};
	vector<pair<size_t, bool>> devices;

	while(scanf(" %ld %ld %ld", &n, &m, &c) && (n || m || c)){
		size_t max_cons{0}, consume{0};

		while(n-- && scanf(" %ld", &device_cons))
			devices.emplace_back(make_pair(device_cons, false));

		size_t index{0};

		while(m-- && scanf(" %ld", &index)){
			--index;

			devices[index].second = !devices[index].second;
			
			if(devices[index].second) consume += devices[index].first;
			else consume -= devices[index].first;

			consume > max_cons ? max_cons = consume : max_cons = max_cons;
		}

		printf("Sequence %ld\n", tc++);
		(max_cons > c) ? printf("Fuse was blown.\n\n") : 
					  	printf("Fuse was not blown.\nMaximal power consumption was %ld amperes.\n\n", max_cons);

		devices.clear();
	}

	return 0;
}
