#include <bits/stdc++.h>

using namespace std;

void process(string::iterator &it_letter, string::iterator &it_init, string::iterator &it, char &&c, 
			 string &highway, size_t &distance, size_t &min_distance){
	
	++distance;

	min_distance == 0 ? min_distance = distance : min_distance = min(min_distance, distance);
	it_letter = find(it, highway.end(), c);

	if(it_letter != highway.end()){
		it_init = it;
		distance = 0;
	} else it = highway.end();
}


int main(){
	
	string highway;
	size_t l{0};

	while(scanf("%ld ", &l) && l){
		getline(cin, highway);

		auto it = find(highway.begin(), highway.end(), 'Z');
		if(it != highway.end()) printf("0\n");
		else {
			
			size_t distance{0}, min_distance{0};

			auto it_r = find(highway.begin(), highway.end(), 'R');
			auto it_d = find(highway.begin(), highway.end(), 'D');

			auto it_init = min(it_r, it_d);

			it = it_init;

			while(it != highway.end()){
				++it;
				if(*it_init == 'D'){

					if(*it == '.') ++distance;
					else if(*it == 'R') process(it_d, it_init, it, 'D', highway, distance, min_distance);
					else if(*it == 'D'){
						distance = 0;
						it_init = it;
					}

				} else {

					if(*it == '.') ++distance;
					else if(*it == 'D') process(it_r, it_init, it, 'R', highway, distance, min_distance);
					else if(*it == 'R'){
						distance = 0;
						it_init = it;
					}
				}
			}
			printf("%ld\n", min_distance);		
		}
	}

	return 0;	
}
					    