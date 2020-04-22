#include <bits/stdc++.h>

using namespace std;

#define deb(x) cout << #x << " " << x << "\n";
#define all(x) x.begin(), x.end()

int grid[8][8];
void initialize(){
	int value = 0;
	for(int i = 0; i < 8; ++i){
		for(int j = 0;  j < 8; ++j){
			grid[i][j] = value++;
		}
	}
}

int get_row(int &q){
	if(q >= 0 && q <= 7)
		return 0;
	else if(q > 7 && q <= 15)
		return 1; 
	else if(q > 15 && q <= 23)
		return 2;
	else if(q > 23 && q <= 31)
		return 3;
	else if(q > 31 && q <= 39)
		return 4;
	else if(q > 39 && q <= 47)
		return 5;
	else if(q > 47 && q <= 55)
		return 6;
	else 
		return 7;      
}

int get_col(int &row, int &q){
	for(int j = 0; j < 8; ++j){
		if(grid[row][j] == q)
			return j;
	}
}

int get_new_k(int &k_row, int &&k_col){
	return grid[k_row][k_col];
}

int get_new_k(int &&k_row, int &k_col){
	return grid[k_row][k_col];
}

bool king_move(int &k_row, int &k_col, int &nq_row, int &nq_col, int &nq){
	if(nq_row == k_row){
		if(nq == get_new_k(k_row, k_col + 1) || nq == get_new_k(k_row, k_col - 1))
			return false;
	}
	else if(nq_col == k_col){
		if(nq == get_new_k(k_row + 1, k_col) || nq == get_new_k(k_row - 1, k_col))
			return false;
	}

	return true;
}

int should_stop(int &k, int &nq){
	if((k == 56 && nq == 49) || (k == 0 && nq == 9) || (k == 63 && nq == 54) || (k == 7 && nq == 14))
		return -2;
	
	return 1;
}

int move_queen(int &q, int &nq, int &k){

	int q_row = get_row(q);
	int q_col = get_col(q_row, q);

	int nq_row = get_row(nq);
	int nq_col = get_col(nq_row, nq);

	int k_row = get_row(k);
	int k_col = get_col(k_row, k);

	if((q_row != nq_row) && (q_col != nq_col))
		return -1;
	else if(nq_row == k_row || nq_col == k_col){
		if(q_row == k_row || q_col == k_col){
			if((k < q && nq < k) || (k > q && nq > k))
				return -1;
			else if(!king_move(k_row, k_col, nq_row, nq_col, nq))
				return 0;
			else
				return 1;
		}
		else if(!king_move(k_row, k_col, nq_row, nq_col, nq))
			return 0;
		else
			should_stop(k, nq);
	}
	else
		should_stop(k, nq);
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	initialize();

	int k = 0, q = 0, nq = 0;
	while(cin >> k >> q >> nq){
		if(k == q)
			cout << "Illegal state" << "\n";	//q and k at the same square
		else if(nq == k || q == nq)
			cout << "Illegal move" << "\n";	    //q to k square
		else{

			int q_move = move_queen(q, nq, k);

			if(q_move == -1)
				cout << "Illegal move" << "\n";
			else if(q_move == 0){
				cout << "Move not allowed" << "\n";
			}
			else{
				if(q_move == 1)
					cout << "Continue" << "\n";
				else
					cout << "Stop" << "\n";
			}
		}
	}
	return 0;
}