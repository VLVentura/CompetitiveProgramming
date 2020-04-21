#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(), x.end()

vector<pair<char,char>> hand_on_top(vector<pair<char,char>> &deck, vector<pair<char,char>> &cards){
	vector<pair<char,char>> temp(52);
	int index = 0;

	for(int i = cards.size() - 1; i >= 0; --i)
		temp[index++] = cards[i];

	index = cards.size();

	for(int i = 24; i >= 0; --i)
		temp[index++] = deck[i];

	return temp;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int tc = 0, cnt = 1;

	cin >> tc;
	while(cnt <= tc){
		
		vector<pair<char,char>> deck(52), cards(27);
		for(int i = 51; i >= 0; --i){
			cin >> deck[i].first >> deck[i].second; // value, suit
		}
		copy(deck.begin()+25, deck.end(), cards.begin());

		int y = 0, x = 0;
		for(int i = 0; i < 3; ++i){
			if(isalpha(cards[0].first)){
				x = 10;
			}
			else{
				x = cards[0].first - '0';
			}

			y += x;
			
			if(x == 10){
				cards.erase(cards.begin());
			}
			else{
				cards.erase(cards.begin(),cards.begin()+(10-x+1));
			}
		}

		deck = hand_on_top(deck, cards);

		cout << "Case " << cnt++ << ": ";	
		cout << deck[y-1].first << deck[y-1].second << "\n";
	}	

	return 0;
}
