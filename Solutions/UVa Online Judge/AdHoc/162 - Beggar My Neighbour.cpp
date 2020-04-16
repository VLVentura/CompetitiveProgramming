#include <bits/stdc++.h>

using namespace std;

void process_input(string &str, deque<char> &dealer, deque<char> &non_dealer, bool &player){
	for(auto it = str.begin() + 1; it < str.end(); it+=3){
		player ? non_dealer.emplace_back(*it) : dealer.emplace_back(*it);
		player = !player;
	}
}

char get_card(deque<char> &hand){
	char c = hand.back();
	hand.pop_back();
	return c;
}

bool is_a_face_card(char &c){
	switch(c){
		case 'A':
		case 'K':
		case 'Q':
		case 'J':
			return true;
		default:
			return false;
	}
}

int how_many_cards(char &c){
	switch(c){
		case 'A':
			return 4;
		case 'K':
			return 3;
		case 'Q':
			return 2;
		case 'J':
			return 1;
	}
}

void take_deck(deque<char> &deck, deque<char> &hand){
	while(!deck.empty()){
		hand.emplace_front(deck.front());
		deck.pop_front();
	}
}

bool have_cards_to_play(bool &player, deque<char> &dealer, deque<char> &non_dealer){
	if(player)
		return ((int)non_dealer.size() >= 1) ? true : false;
	else
		return ((int)dealer.size() >= 1) ? true : false;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	string str;
	deque<char> dealer, non_dealer, deck;

	while(getline(cin, str) && str != "#"){
		int input = 0;
		bool player = true;
		
		process_input(str, dealer, non_dealer, player);
		do{
			getline(cin, str);
			process_input(str, dealer, non_dealer, player);
			++input;
		}while(input < 3);

		bool player_has_cards = true;
		while(player_has_cards){

			player ? deck.emplace_back(get_card(non_dealer)) : deck.emplace_back(get_card(dealer));
			player = !player;
			player_has_cards = have_cards_to_play(player, dealer, non_dealer);
							
			if(is_a_face_card(deck.back())){

				int i = 0, n = how_many_cards(deck.back());

				while(i < n && player_has_cards){

					player ? deck.emplace_back(get_card(non_dealer)) : deck.emplace_back(get_card(dealer));
					++i;

					if(is_a_face_card(deck.back())){
						i = 0;
						n = how_many_cards(deck.back());
						player = !player;
					}

					player_has_cards = have_cards_to_play(player, dealer, non_dealer);
				}

				if(player && !non_dealer.empty())
					take_deck(deck, dealer);
				else if(player == false && !dealer.empty())
					take_deck(deck, non_dealer);
				else if((dealer.empty() || non_dealer.empty()) && i == n){
					if(player){
						take_deck(deck, dealer);
						deck.emplace_back(get_card(dealer));
					}
					else{
						take_deck(deck, non_dealer);
						deck.emplace_back(get_card(non_dealer));
					}
				}
				player = !player;
			}
		}

		non_dealer.empty() ? cout << "1" << right << setw(3) << dealer.size() << "\n" :
							 cout << "2" << right << setw(3) << non_dealer.size() << "\n";
		deck.clear();
		dealer.clear();
		non_dealer.clear();
	}

	return 0;
}