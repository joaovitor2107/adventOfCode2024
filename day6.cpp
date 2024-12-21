#include <iostream>
#include <string>
#include <vector>
using namespace std;
int counter = 0;
vector<string> mapa;

int funcAux(vector<string> &mapa, int locx, int locy, int sentido){
	
	if(sentido == 3){
		if(mapa.size() - 1 < locy) return sentido;
		if(mapa[locy][locx] == '.'){
			counter++;
			mapa[locy][locx] = 'X';
		}
		if(locy + 1 > mapa.size() - 1) return sentido;
		if(mapa[locy + 1][locx] == '#'){
			return 4;	
		}
	}
	else if(sentido == 2){
		if(mapa[locy].size() - 1 < locx) return sentido;
		if(mapa[locy][locx] == '.'){
			counter++; 
			mapa[locy][locx] = 'X';
		} 
		if(locx + 1 > mapa[locy].size() - 1) return sentido;
		if(mapa[locy][locx + 1] == '#'){
			return 3;
		}
	}
	else if(sentido == 1){
		if(locy < 0) return sentido;
		if(mapa[locy][locx] == '.'){
			counter++; 
			mapa[locy][locx] = 'X';
		} 
		if(locy - 1 < 0)return sentido;
		if(mapa[locy - 1][locx] == '#'){
			return 2;
		}
	}
	else if(sentido == 4){
		if(locx < 0) return sentido;
		if(mapa[locy][locx] == '.'){
			counter++; 
			mapa[locy][locx] = 'X';
		} 
		if(locx - 1 < 0) return sentido;
		if(mapa[locy][locx - 1] == '#'){
			return 1;
		}
	}

	return sentido;
}

int main(){
	
	string aux;
	int locy;
	int locx;
	int coluna = 0;
	while(getline(cin, aux)){
		for(int i = 0; i < aux.size(); i++){
			if(aux[i] == '^' || aux[i] == 'v' || aux[i] == '>' || aux[i] == '<'){
				locx = i;
				locy = coluna;
			}
		}
		coluna++;
		mapa.push_back(aux);
	}
	
	mapa[locy][locx] = '.';
	int sentido = 1;
	while(true){
		if(locy >= mapa.size() || locx >= mapa[locy].size() || locx < 0 || locy < 0) break;
		sentido = funcAux(mapa, locx, locy, sentido);

		if(sentido == 3){ 
			locy++;
		}
		else if(sentido == 2){
			locx++;
		}
		else if(sentido == 1){
			locy--;
		}
		else if(sentido == 4){
			locx--;
		}
	}


	for(int i = 0; i < mapa.size(); i++){
		for(int j = 0; j < mapa[i].size(); j++){
			cout << mapa[i][j];
		}
		cout << "\n";

	}

	cout << counter << "\n";

	return 0;
}
