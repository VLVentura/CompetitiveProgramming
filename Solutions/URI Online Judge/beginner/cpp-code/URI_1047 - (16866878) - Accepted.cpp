#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int hi, mi, hf, mf;

	cin >> hi >> mi >> hf >> mf;

	int timeInit, timeFinal, gameTime, gameTime_h, gameTime_m;

	timeInit = (hi * 3600) + (mi * 60);
	timeFinal = (hf * 3600) + (mf * 60);

	gameTime = abs(timeInit - timeFinal);

	if(hi > hf || (mi >= mf && hi == hf))
		gameTime = 86400 - gameTime;

	gameTime_h = gameTime / 3600;
	gameTime = gameTime - (gameTime_h * 3600);

	gameTime_m = gameTime / 60;

	cout << "O JOGO DUROU " << gameTime_h << " HORA(S) E " << gameTime_m << " MINUTO(S)" << endl; 

	return 0;	
}

