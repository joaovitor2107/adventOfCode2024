#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isNumber(const string& str){
	return all_of(str.begin(), str.end(), ::isdigit);
}

int main(){
	
	ifstream file("arquivo9.txt");
	string content;
	string line;

	if(file.is_open()){
		while(getline(file, line)){
			content += line + '\n';
		}
		file.close();
	}

	vector<string> codigo;

	for(int i = 0; i < content.size(); i++){
	
		if(i % 2 == 0 && isdigit(content[i])){
			int j = 0;
			string num = to_string(i/2);
			while(j < content[i] - '0'){
				codigo.push_back(num);
				j++;
			}
		}
		else if(i % 2 != 0 && isdigit(content[i])){
			int j = 0;
			while(j < content[i] - '0'){
				codigo.push_back(".");
				j++;
			}
		}
	
	}

	int l = 0;
	int r = codigo.size() - 1;

	long int result = 0;

	while (l < r){
		if(codigo[l] != ".") l++;
		if(!isNumber(codigo[r])) r--;

		if(codigo[l] == "." && isNumber(codigo[r])){
			codigo[l] = codigo[r];
			codigo[r] = ".";
			l++;
			r--;
		}
	}

	for(int i = 0; i < codigo.size(); i++){
		if(!isNumber(codigo[i])) break;
		result += stoi(codigo[i]) * i;
	}

	cout << result << "\n";

	return 0;
}
