#include <iostream>
#include <string>
using namespace std;

// Função recursiva para inverter uma string
string inverterString(string palavra) {
  // Se a palavra tem tamanho 0 ou 1, ela já está "invertida",
  // então retornamos a própria palavra.
  if (palavra.size() <= 1) {
    return palavra;
  }

  // Recursivamente, invertemos a parte restante da string.
  // O `palavra.substr(1)` pega a string a partir do segundo caractere,
  // e a chamada recursiva irá ocorrer até que o caso base seja atingido.
  // Após isso, concatenamos o primeiro caractere ao final.
  return inverterString(palavra.substr(1)) + palavra[0];
}

int main() {
  string palavra;
  cout << "Digite uma palavra: ";
  cin >> palavra;

  string invertida = inverterString(palavra);
  cout << "Palavra invertida: " << invertida << endl;

  return 0;
}
