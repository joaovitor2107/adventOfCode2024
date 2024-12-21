#include <bits/stdc++.h>
#include <cctype>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
	string aux;
	int result = 0;
	bool enabled = true;

	while(getline(cin, aux)){
		
		for(int i = 0; i < aux.size(); i++){
			int j = i;
			if(i + 8 >= aux.size()) break;
				if(aux[j] == 'd' &&
				j + 1 < aux.size() && aux[j + 1] == 'o' &&
				j  +2 < aux.size() && aux[j + 2] == '(' && 
				j + 3 < aux.size() && aux[j + 3] == ')'){
					enabled = true;
				}

				if(aux[j] == 'd' &&
				j + 1 < aux.size() && aux[j + 1] == 'o' &&
				j  +2 < aux.size() && aux[j + 2] == 'n' && 
				j + 3 < aux.size() && aux[j + 3] == '\'' && 
				j + 4 < aux.size() && aux[j + 4] == 't' &&
				j + 5 < aux.size() && aux[j + 5] == '(' &&
				j + 6 < aux.size() && aux[j + 6] == ')'){
					enabled = false;
				}


				if (aux[j] == 'm' && 
            	j + 1 < aux.size() && aux[j + 1] == 'u' && 
            	j + 2 < aux.size() && aux[j + 2] == 'l' && 
            	j + 3 < aux.size() && aux[j + 3] == '(' &&
				enabled == true){
					j += 4;
					string num1;
					string num2;
					while(isdigit(aux[j])){
						num1.push_back(aux[j]);
						j++;
					}
					if(aux[j] == ','){
						j++;
						while(isdigit(aux[j])){
							num2.push_back(aux[j]);
							j++;
						}
						if(aux[j] == ')'){
							result += stoi(num1) * stoi(num2);
						}
					}
			} 
		}
	}

	cout << result << "\n";

	return 0;
}
