#include <bits/stdc++.h>
#include <cstring>
using namespace std;

vector<string> mapa;

int horizontal(int i, int j, const char word[]){
	if(mapa[i].size() - 4 >= j){
		return strncmp(&mapa[i][j], word, 4) == 0;
	}
	return 0;
}

int vertical(int i, int j, const char word[]){
	if(mapa.size() - 4 >= i){
		for(int k = 0; k < 4; k++){
			if(word[k] != mapa[i + k][j]) return 0;
		}
		return 1;
	}
		return 0;
}

int diagonalDir(int i, int j, const char word[]){
	if((mapa[i].size() - 4 >= j) && (mapa.size() - 4 >= i)){
		for(int k = 0; k < 4; k++){
			if(word[k] != mapa[i + k][j + k]) return 0;
		}
		return 1;
	}	
	return 0;
}

int diagonalEsq(int i, int j, const char word[]){
	if((j >= 3) && (mapa.size() - 4 >= i)){
		for(int k = 0; k < 4;k++){
			if(word[k] != mapa[i + k][j - k]) return 0;
		}
		return 1;
	}
	return 0;
}

int main() { 
	
	string aux;
	while(getline(cin, aux)){
		mapa.push_back(aux);
	}

	int counter = 0;
	for(int i = 0; i < mapa.size(); i++){
		for(int j = 0; j < mapa[i].size(); j++){
			counter += horizontal(i, j, "XMAS");
			counter += horizontal(i, j, "SAMX");
			
			counter += vertical(i, j,"XMAS");
			counter += vertical(i, j,"SAMX");

			counter += diagonalDir(i, j, "XMAS");
			counter += diagonalDir(i, j, "SAMX");

			counter += diagonalEsq(i, j, "XMAS");
			counter += diagonalEsq(i, j, "SAMX");
			
		}
	}
	
	
	cout << counter << "\n";

	return 0;
}
