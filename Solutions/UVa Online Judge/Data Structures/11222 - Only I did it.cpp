#include <bits/stdc++.h>

using namespace std;

#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',', ' ');\
						stringstream _ss(_s);\
						istream_iterator<string> _it(_ss);\
						err(_it, args);}
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << "[" << *it << ": " << a << "] ";
	err(++it, args...);
}
#define debug(...) error(__VA_ARGS__); cout << "\n";

void print_vector(vector<int> &vec){
	int size = (int)vec.size();
	if(size != 0){
		cout << " ";
	}
	for(int i = 0; i < size; ++i){
		cout << vec[i];
		if(i != size - 1){
			cout << " ";
		}
	}
	cout << "\n";
}

void sort_if(vector<int> &vec){
	if(!is_sorted(vec.begin(), vec.end())){
		sort(vec.begin(), vec.end());
	}
}

void erase_inside_equals(vector<int> &vec){
	for(auto it = vec.begin(); it < vec.end(); ++it){
		auto bef_it = it;

		it = lower_bound(it+1, vec.end(), *it);
		while(it != vec.end() && *it == *bef_it){
			vec.erase(it);
			it = bef_it;
			it = lower_bound(it+1, vec.end(), *it);
		}

		it = bef_it;
	}
}

void erase_same_elements(vector<int> &first, vector<int> &second, vector<int> &aux, bool &&flag_to_erase = false){
	
	for(auto it_first = first.begin(); it_first < first.end(); ++it_first){
		auto it = lower_bound(second.begin(), second.end(), *it_first);
		if(it != second.end() && *it == *it_first){
			first.erase(it_first);
			aux.emplace_back(*it);
			--it_first;
		}
	}

	if(flag_to_erase){
		for(auto it_aux = aux.begin(); it_aux < aux.end(); ++it_aux){
			auto it = lower_bound(second.begin(), second.end(), *it_aux);
			if(it != second.end() && *it == *it_aux){
				second.erase(it);
			}
		}
	}
}


int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int T = 0, tc = 0, q = 0, n = 0;
	vector<int> one, two, three, aux_one, aux_two;

	cin >> T;
	while(tc < T){

		for(int i = 0; i < 3; ++i){
			cin >> q;

			for(int j = 0; j < q; ++j){
				cin >> n;
				if(i == 0){	
					one.push_back(n);
					if(j == q-1){
						sort_if(one);
						erase_inside_equals(one);
					}
				}
				else if(i == 1){
					two.push_back(n);
					if(j == q-1){
						sort_if(two);
						erase_inside_equals(two);
						erase_same_elements(two, one, aux_one);
					}
				}
				else{
					three.push_back(n);
					if(j == q-1){
						sort_if(three);
						erase_inside_equals(three);
						erase_same_elements(three, one, aux_one, true);
						erase_same_elements(three, two, aux_two, true);
					}
				}
			}
		}


		cout << "Case #" << ++tc << ":\n";

		int size_one = (int)one.size(), size_two = (int)two.size(), size_three = (int)three.size();
		int max_size = max({size_one, size_two, size_three});

		if(max_size == size_one && max_size == size_two && max_size == size_three){
			for(int i = 0; i < 3; ++i){
				if(i == 0){
					cout << i+1 << " " << size_one;
					print_vector(one);
				}
				else if(i == 1){
					cout << i+1 << " " << size_two;
					print_vector(two);
				}
				else{
					cout << i+1 << " " << size_three;
					print_vector(three);
				}
			}
		}
		else if(max_size == size_one && max_size == size_two && max_size > size_three){
			for(int i = 0; i < 2; ++i){
				if(i == 0){
					cout << i+1 << " " << size_one;
					print_vector(one);
				}
				else{
					cout << i+1 << " " << size_two;
					print_vector(two);
				}
			}
		}
		else if(max_size == size_one && max_size == size_three && max_size > size_two){
			for(int i = 0; i < 2; ++i){
				if(i == 0){
					cout << i+1 << " " << size_one;
					print_vector(one);
				}
				else{
					cout << i+2 << " " << size_three;
					print_vector(three);
				}
			}
		}
		else if(max_size == size_two && max_size == size_three && max_size > size_one){
			for(int i = 0; i < 2; ++i){
				if(i == 0){
					cout << i+2 << " " << size_two;
					print_vector(two);
				}
				else{
					cout << i+2 << " " << size_three;
					print_vector(three);
				}
			}
		}
		else if(max_size == size_one && max_size > size_two && max_size > size_three){
			cout << "1 " << size_one;
			print_vector(one);
		}
		else if(max_size == size_two && max_size > size_one && max_size > size_three){
			cout << "2 " << size_two;
			print_vector(two);
		}
		else{
			cout << "3 " << size_three;
			print_vector(three);
		}

		one.clear();
		two.clear();
		three.clear();
		aux_one.clear();
		aux_two.clear();
	}

	return 0;
}