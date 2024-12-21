#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

void stringToMap(string content, map<long long, long>& stones) {
    int i = 0;
    long tam = content.size();
    while(i < tam) {
        if(content[i] == ' ') i++;
        if(isdigit(content[i])) {
            string num1;
            while(i < tam && isdigit(content[i])) {
                num1 += content[i];
                i++;
            }
			if(stones.count(stol(num1))){
				stones[stol(num1)]++;
			}
			else {
				stones[stol(num1)] = 1;
			}
        } else {
            i++;
        }
    }
}


pair<long long, long long> splitNumber(long long stone) {
    string aux = to_string(stone);
    long meio = aux.size() / 2;
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
    

    map<long long, long>stones;
	stringToMap(content, stones);
	

    int blinks = 75;
    for(int i = 0; i < blinks; i++) {
		map<long long, long> newStones;
        for(auto stone : stones) {
            if(stone.first == 0) {
            	newStones[1] = stone.second;
			}
            else if(isEven(stone.first)) {
                pair<long, long> sla;
				sla = splitNumber(stone.first);
				if(newStones.count(sla.first)) {
					newStones[sla.first] += stone.second;
				}
				else newStones[sla.first] = stone.second;
				if(newStones.count(sla.first)) {
					newStones[sla.second] += stone.second;
				}
				else newStones[sla.second] = stone.second;
            }
            else {
                newStones[stone.first * 2024] = stone.second;
            }
        }
        stones = newStones;
    }
    
	long sum = 0;
	for(auto stone : stones){
		sum += stone.second;
	}
    cout << "\n" << sum << "\n";
    
	return 0;
}
