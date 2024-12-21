#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

  int aux;
  string linha;
  int safe = 0;
  while (getline(cin, linha)) {
    istringstream aux(linha);
    int numero;
    vector<int> numeros;

    while (aux >> numero) {
      numeros.push_back(numero);
    }

    if (numeros.size() < 2) {
      safe++;
      continue;
    }

    bool menor = false;
    if (numeros[0] > numeros[1])
      menor = true;

    for (int i = 1; i < numeros.size(); i++) {
      if (1 > abs(numeros[i - 1] - numeros[i]) ||
          abs(numeros[i - 1] - numeros[i]) > 3) {
        break;
      }
      if (numeros[i - 1] > numeros[i] && menor == false) {
        break;
      }
      if (numeros[i - 1] < numeros[i] && menor == true) {
        break;
      }
      if (i == numeros.size() - 1)
        safe++;
    }
  }
  cout << safe << "\n";

  return 0;
}
