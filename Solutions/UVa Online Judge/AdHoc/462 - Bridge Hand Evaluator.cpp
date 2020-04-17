#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define FOR_ALL(x) for(auto it = x.begin(); it != x.end(); ++it)

int value_to_sum(char &c){
	switch(c){
		case 'A':
			return 4;
		case 'K':
			return 3;
		case 'Q':
			return 2;
		case 'J':
			return 1;
		default:
			return 0;
	}
}

void stopepd(bool *honor_card, char &s){
	int i = 0;

	switch(s){
		case 'S':
			i = 0;
			break;
		case 'H':
			i = 1;
			break;
		case 'D':
			i = 2;
			break;
		case 'C':
			i = 3;
			break;
	}

	honor_card[i] = 1;
}


void num_of_suits(int *suits, char &c){
	int i = 0;

	switch(c){
		case 'S':
			i = 0;
			break;
		case 'H':
			i = 1;
			break;
		case 'D':
			i = 2;
			break;
		case 'C':
			i = 3;
			break;
	}

	++suits[i];
}

int process_cards(char &c, char &s, int *suits, bool *honor_card){
	int i = 0;
	switch(s){
		case 'S':
			i = 0;
			break;
		case 'H':
			i = 1;
			break;
		case 'D':
			i = 2;
			break;
		case 'C':
			i = 3;
			break;
	}

	if(c == 'K'){
		if(suits[i] < 2)
			return 1;
		else{
			honor_card[i] = 1;
			return 0;
		}
	}
	else if(c == 'Q'){
		if(suits[i] < 3)
			return 1;
		else{
			honor_card[i] = 1;
			return 0;
		}
	}
	else{
		return suits[i] < 4 ? 1 : 0; 
	}
}

bool all_true(bool *honor_card){
	for(int i = 0; i < 4; ++i){
		if(honor_card[i] == false)
			return false;
	}
	return true;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	string str;
	while(getline(cin, str)){
		
		vector<pair<char, char>> royal_cards(13); // card / suit
		int total_value = 0, i = 0, sub_value = 0, extra_sum = 0;
		int suits[4] = {0}; // 0 spades / 1 hearts / 2 diamonds / 3 clubs
		bool honor_card[4] = {0}; // 0 spades / 1 hearts / 2 diamonds / 3 clubs

		for(auto it = str.begin(); it < str.end(); it+=3){
			int value = value_to_sum(*it);

			if(value == 4)
				stopepd(honor_card, *(it+1));
			if(value != 0 && value != 4){
				royal_cards[i].first = *it;
				royal_cards[i++].second = *(it+1);
			}

			total_value += value;
			num_of_suits(suits, *(it+1));
		}

		for(int j = 0; j < i; ++j){
			sub_value += process_cards(royal_cards[j].first, royal_cards[j].second, suits, honor_card);
		}

		int index = 0, n = INT_MIN;

		for(int j = 0; j < 4; ++j){
			if(suits[j] == 0 || suits[j] == 1)
				extra_sum += 2;
			else if(suits[j] == 2)
				++extra_sum;
			
			if(j <= 3){
				int before = n;
				n = max(suits[j], n);
				n != before ? index = j : index = index;
			}
		}

		if(total_value - sub_value >= 16 && all_true(honor_card)) 
			cout << "BID NO-TRUMP" << "\n";
		else if(total_value - sub_value + extra_sum >= 14){
			cout << "BID ";
			if(index == 0)
				cout << "S" << "\n";
			else if(index == 1)
				cout << "H" << "\n";
			else if(index == 2)
				cout << "D" << "\n";
			else 
				cout << "C" << "\n";
		}
		else 
			cout << "PASS" << "\n";
		
	}
	return 0;
}
