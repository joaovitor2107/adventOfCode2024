#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void stringToVector(string content, vector<long long>& stones) {
    int i = 0;
    int tam = content.size();
    while(i < tam) {
        if(content[i] == ' ') i++;
        if(isdigit(content[i])) {
            string num1;
            while(i < tam && isdigit(content[i])) {
                num1 += content[i];
                i++;
            }
            stones.push_back(stoll(num1));
        } else {
            i++;
        }
    }
}



pair<long long, long long> splitNumber(long long stone) {
    string aux = to_string(stone);
    int meio = aux.size() / 2;
    string num1 = aux.substr(0, meio);
    string num2 = aux.substr(meio);
    return {stoll(num1), stoll(num2)};
}


bool isEven(long long stone) {
    return to_string(stone).size() % 2 == 0;
}


int main() {
    
	ifstream file("input11.txt");
    string content;
    if(file.is_open()) {
        getline(file, content);
    }
    file.close();
    

    vector<long long> stones;
    stringToVector(content, stones);
	

    int blinks = 25;
    for(int i = 0; i < blinks; i++) {
        vector<long long> newStones;
        for(int j = 0; j < stones.size(); j++) {
            if(stones[j] == 0) {
                newStones.push_back(1);
            }
            else if(isEven(stones[j])) {
                pair<long, long> sla;
				sla = splitNumber(stones[j]);
                newStones.push_back(sla.first);
                newStones.push_back(sla.second);
            }
            else {
                newStones.push_back(stones[j] * 2024LL);
            }
        }
        stones = newStones;
    }
    

    for(long long stone : stones) {
        cout << stone << " ";
    }
    cout << "\n" << stones.size() << "\n";
    
	return 0;
}
