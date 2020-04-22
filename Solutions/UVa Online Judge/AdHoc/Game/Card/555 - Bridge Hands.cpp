#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

char whos_next(char &c){
	switch(c){
		case 'N':
			return 'E';
		case 'E':
			return 'S';
		case 'S':
			return 'W';
		case 'W':
			return 'N';
	}
}

int find_pos(char *turns, int &t){
	if(t == 0){
		for(int i = 0; i < 4; ++i){
			if(turns[i] == 'S') return i;
		}
	}
	else if(t == 1){
		for(int i = 0; i < 4; ++i){
			if(turns[i] == 'W') return i;
		}
	}
	if(t == 2){
		for(int i = 0; i < 4; ++i){
			if(turns[i] == 'N') return i;
		}
	}
	if(t == 3){
		for(int i = 0; i < 4; ++i){
			if(turns[i] == 'E') return i;
		}
	}
}

//convert the cards
// T   J    Q    K    A
// T U(J) V(Q) W(K) Y(A)
char transform_this_letter(char &c){
	switch(c){
		case 'J':
			return 'U';
		case 'Q':
			return 'V';
		case 'K':
			return 'W';
		case 'A':
			return 'Y';
		case 'U':
			return 'J';
		case 'V':
			return 'Q';
		case 'W':
			return 'K';
		case 'Y':
			return 'A';
	}

}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int still_input = 0;
	char dealer = 'a';
	string buffer, str;

	while(getline(cin, buffer) && buffer != "#"){
		if(buffer.size() == 1)
			dealer = buffer[0];
		else if(still_input < 2){
			if(still_input == 0)
				str = buffer;
			else
				str += buffer;
			++still_input;
		}
		
		if(still_input == 2){
			char turns[4];
			for(int i = 0; i < 4; ++i){
				if(i == 0)
					turns[i] = whos_next(dealer);
				else
					turns[i] = whos_next(turns[i-1]);
			}
			
			//convert the suits
			// C D   S  H
			// C D G(S) H
			for(int i = 0; i < 4; ++i){
				int pos = find_pos(turns, i);
				int j = 0;
				vector<pair<char, char>> vec(13);
				for(auto it = str.begin() + (2*pos); it < str.end(); it+=8){
					if(*it == 'S')
						vec[j].first = 'G';
					else
						vec[j].first = *it;

					if(isalpha(*(it+1)) && *(it+1) != 'T')
						vec[j].second = transform_this_letter(*(it+1));
					else
						vec[j].second = *(it+1);
					++j;
				}
				
				sort(ALL(vec));
				
				cout << turns[pos] << ": ";
				for(auto it = vec.begin(); it != vec.end(); ++it){
					if(it->first == 'G')
						cout << "S";
					else
						cout << it->first;

					if(isalpha(it->second) && it->second != 'T')
						cout << transform_this_letter(it->second);
					else
						cout << it->second;

					it == vec.end() - 1 ? cout << "\n" : cout << " ";

				}
			}

			still_input = 0;
		}

	}

	return 0;
}