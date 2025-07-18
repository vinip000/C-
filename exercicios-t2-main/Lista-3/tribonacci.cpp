#include <iostream>

using namespace std;

/**
 * Função recursiva para calcular o n-ésimo termo da sequência de Tribonacci.
 *
 * A sequência de Tribonacci é definida da seguinte forma:
 * T(n) = T(n-1) + T(n-2) + T(n-3) para n > 2,
 * T(0) = 0, T(1) = T(2) = 1.
 *
 * @param n: O índice do termo desejado na sequência de Tribonacci.
 * @return: O n-ésimo termo da sequência.
 */
int tribonacci(int n) {
    // Caso base 1: O primeiro termo da sequência, T(0), é 0.
  if (n == 0) {
    return 0;
  }
  // Caso base 2 e 3: Os termos T(1) e T(2) são ambos 1.
  else if (n == 1 || n == 2) {
    return 1;
  }
  // Caso geral: Para termos n > 2, o n-ésimo termo é a soma dos três termos anteriores.
  // Usamos chamadas recursivas para calcular os termos anteriores.
  else {
    return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
  }
}

int main() {
  int n;
  cout << "Digite o valor de n para calcular o n-ésimo termo da sequência de Tribonacci: ";
  cin >> n;

  // Calcula o n-ésimo termo da sequência de Tribonacci usando a função recursiva.
  int resultado = tribonacci(n);

  cout << "O " << n << "-ésimo termo da sequência de Tribonacci é: " << resultado << endl;

  return 0;
}
