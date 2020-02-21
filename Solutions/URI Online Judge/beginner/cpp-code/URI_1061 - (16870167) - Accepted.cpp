#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){

	string s1, s2;
	char ponto1, ponto2, ponto3, ponto4;
	int di, hi, mi, si, df, hf, mf, sf;
	int gameTime, gameTime_h, gameTime_m, gameTime_s, gameTime_d;

	cin >> s1 >> di
		>> hi >> ponto1 >> mi >> ponto2 >> si
		>> s2 >> df
		>> hf >> ponto3 >> mf >> ponto4 >> sf;

	gameTime = (60 - si + sf) + 
			   (60 - 1 - mi + mf) * 60 + 
			   (24 - 1 - hi + hf) * 3600 + 
			   (df - di - 1) * 86400;

	gameTime_d = gameTime / 86400;
	gameTime = gameTime - (gameTime_d * 86400);

	gameTime_h = gameTime / 3600;
	gameTime = gameTime - (gameTime_h * 3600);

	gameTime_m = gameTime / 60;
	gameTime = gameTime - (gameTime_m * 60);

	gameTime_s = gameTime;

	cout << gameTime_d << " dia(s)\n" 
		 << gameTime_h << " hora(s)\n"
		 << gameTime_m << " minuto(s)\n"
		 << gameTime_s << " segundo(s)" << endl;

	return 0;	
	
}