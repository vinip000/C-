#include <iostream>

using namespace std;

/**
 * Função recursiva que gera e imprime a sequência de Collatz.
 *
 * A Conjectura de Collatz diz que, para qualquer número inteiro positivo n:
 * - Se n for par, divida-o por 2.
 * - Se n for ímpar, multiplique-o por 3 e some 1.
 * - Repita o processo com o novo valor de n, até que n seja 1.
 *
 * @param n: Número atual na sequência.
 */
void sequenciaCollatz(int n) {
    // Imprime o valor atual de n.
  cout << n << " ";

  // Caso base: se n for 1, a função retorna, encerrando a recursão.
  if (n == 1) {
    return;
  }
  // Se n for par, divida-o por 2 e continue a sequência.
  else if (n % 2 == 0) {
    sequenciaCollatz(n / 2);
  }
  // Se n for ímpar, multiplique-o por 3, some 1 e continue a sequência.
  else {
    sequenciaCollatz(3 * n + 1);
  }
}

int main() {
  int numeroInicial;
  cout << "Informe um número inteiro positivo: ";
  cin >> numeroInicial;

  // Verifica se o número inserido é positivo.
  if (numeroInicial > 0) {
    cout << "Sequência de Collatz para " << numeroInicial << ": ";
    sequenciaCollatz(numeroInicial);
    cout << endl; // Adiciona uma quebra de linha após a sequência.
  }
  else {
    cout << "Por favor, insira um número inteiro positivo." << endl;
  }

  return 0;
}
