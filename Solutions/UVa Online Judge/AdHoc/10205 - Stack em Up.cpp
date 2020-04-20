#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()

void initialize(vector<pair<char,char>> &sorted){
	char suits[] = "CDHS";
	char values[] = "23456789TJQKA";
	int index = 0;

	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 13; ++j){
			sorted[index].first =  suits[i];
			sorted[index++].second = values[j];
		}
	}
}

vector<pair<char,char>> shuffle(vector<int> &order, vector<pair<char,char>> &deck){
	vector<pair<char,char>> new_deck(52);
	for(int i = 0; i < 52; ++i){
		new_deck[i] = deck[order[i]-1];
	}
	return new_deck;
}

void print_suit(char &c){
	switch(c){
		case 'C':
			cout << "Clubs";
			break;
		case 'D':
			cout << "Diamonds";
			break;
		case 'H':
			cout << "Hearts";
			break;
		case 'S':
			cout << "Spades";
			break;
	}
}

void print_value(char &c){
	if(isalpha(c)){
		switch(c){
			case 'A':
				cout << "Ace";
				break;
			case 'K':
				cout << "King";
				break;
			case 'Q':
				cout << "Queen";
				break;
			case 'J':
				cout << "Jack";
				break;
			case 'T':
				cout << "10";
				break;
		}
	}
	else{
		cout << c; 
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	bool blank_line = true;
	int inputs = 0, tc = 0;
	vector<pair<char,char>> sorted(52);
	initialize(sorted);
	
	cin >> tc;
	while(tc--){

		int j = 0;
		cin >> inputs;

		vector<vector<int>> orders(inputs, vector<int>(52));

		while(j < inputs){
			for(int i = 0; i < 52; ++i){
				cin >> orders[j][i];
			}
			++j;
		}

		string k;
		vector<pair<char,char>> deck(sorted);
		getline(cin,k);
		while(getline(cin,k)){
			if(k.size() == 0)
				break;
			int n = stoi(k);
			deck = shuffle(orders[n-1], deck);
		}

		if(blank_line)
			blank_line = false;
		else
			cout << "\n";

		for(int i = 0; i < 52; ++i){
			print_value(deck[i].second); 
			cout << " of "; 
			print_suit(deck[i].first); 
			cout << "\n";
		}
	}
	return 0;
}