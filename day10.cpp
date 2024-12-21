#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int sumOfpossibilities = 0; 

void possibilites(vector<string> &content, int locRow, int locCollum, int numBuscado, int row, int collum, vector<vector<bool>>& visited){
	
	if(numBuscado == 10){
		if(visited[locRow][locCollum]) return;
		sumOfpossibilities++;
		visited[locRow][locCollum] = true; // para a parte dois so mudar para false
	}
	if(numBuscado > 10) return;

	if(locRow + 1 < row && locCollum < collum && content[locRow + 1][locCollum] - '0' == numBuscado){
		possibilites(content, locRow + 1, locCollum, numBuscado + 1, row, collum, visited);
	}
	
	if(locRow - 1 >= 0 && locCollum < collum && content[locRow - 1][locCollum] - '0' == numBuscado){
		possibilites(content, locRow - 1, locCollum, numBuscado + 1, row, collum, visited);
	}
	
	if(locRow < row && locCollum + 1 < collum && content[locRow][locCollum + 1] - '0' == numBuscado){
		possibilites(content, locRow , locCollum + 1, numBuscado + 1, row, collum, visited);
	}
	
	if(locRow < row && locCollum - 1 >= 0 && content[locRow][locCollum - 1] - '0' == numBuscado){
		possibilites(content, locRow, locCollum - 1, numBuscado + 1, row, collum, visited);
	}


	return;
};

int main(){
	
	ifstream file("arquivo10.txt");
	string line;
	vector<string> content;
	if(file.is_open()){
		while(getline(file, line)){
			content.push_back(line);
		}
		file.close();
	}
	
	for(int i = 0; i < content.size(); i++){
		cout <<  content[i];
		cout << "\n";
	}

	
	int sizeOfRow = content.size();
	int sizeOfCollum = content[0].size();
	for(int i = 0; i < sizeOfRow; i++){
		for(int j = 0; j < sizeOfCollum; j++){
			if(content[i][j] == '0'){
				vector<vector<bool>> visited(sizeOfRow, vector<bool>(sizeOfCollum, false));
				possibilites(content, i, j, 1, sizeOfRow, sizeOfCollum, visited);
			}
		}
	}

	cout << sumOfpossibilities << "\n";

	return 0;
}
