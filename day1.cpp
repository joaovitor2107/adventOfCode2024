#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
	
	int aux, aux2; 
	vector<int> temp;
	vector<int> temp2;
	while(cin >> aux >> aux2){
		temp.push_back(aux);
		temp2.push_back(aux2);
	}
	sort(temp.begin(), temp.end());
	sort(temp2.begin(), temp2.end());

	int res = 0;
	for(int i = 0; i < temp.size(); i++){
		res = abs(temp[i] - temp2[i]);
	}

	cout << res << "\n";

	return 0;
} 
