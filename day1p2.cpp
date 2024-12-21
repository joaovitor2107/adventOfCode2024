#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    
    int aux1, aux2; 
    vector<int> aux;
    unordered_map<int, int> lista;
    while(cin >> aux1 >> aux2){
        aux.push_back(aux1);
        if(lista.count(aux2) == 0){
            lista[aux2] = 1;
        }
        else{
            lista[aux2]++;
        }
    }

    int result = 0;
    for(auto i : aux){
        if(lista.count(i) == 0){
            continue;
        }
        result += i * lista[i];
    }

    cout << result << "\n";

	 return 0;
}
