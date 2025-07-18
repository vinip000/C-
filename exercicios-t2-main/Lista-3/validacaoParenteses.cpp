#include <iostream>
#include <stack>
#include <string>

using namespace std;

/**
 * Função que verifica se os parênteses em uma expressão estão balanceados.
 * @param expressao: Uma string contendo a expressão a ser verificada.
 * @return: Verdadeiro se os parênteses estiverem balanceados, falso caso contrário.
 */
bool verificaParenteses(const string& expressao) {
    // Pilha usada para armazenar parênteses abertos.
  stack<char> pilha;

  // Iterar por cada caractere da expressão.
  for (char caractere : expressao) {
      // Se o caractere é um parêntese aberto, empilhamos na pilha.
    if (caractere == '(') {
      pilha.push(caractere);
    }
    // Se o caractere é um parêntese fechado, precisamos verificar a correspondência.
    else if (caractere == ')') {
        // Se a pilha está vazia neste momento, significa que um parêntese fechado
        // não tem correspondente aberto, então a expressão é desbalanceada.
      if (pilha.empty()) {
        return false;
      }
      // Se não, desempilhamos o parêntese aberto correspondente.
      else {
        pilha.pop();
      }
    }
  }

  // Se a pilha estiver vazia ao final, todos os parênteses abertos tiveram seus
  // pares fechados, portanto, estão balanceados.
  return pilha.empty();
}

int main() {
  string expressao;
  cout << "Digite uma expressao matematica: ";
  getline(cin, expressao);

  if (verificaParenteses(expressao)) {
    cout << "Os parenteses estao balanceados." << endl;
  }
  else {
    cout << "Os parenteses nao estao balanceados." << endl;
  }

  return 0;
}
