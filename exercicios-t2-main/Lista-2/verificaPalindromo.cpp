#include <iostream>
#include <string>
using namespace std;

/**
 * Função recursiva para verificar se uma palavra é um palíndromo.
 *
 * Um palíndromo é uma palavra, frase, número ou qualquer outra sequência de
 * caracteres que leia o mesmo para a frente e para trás (ignorando espaços,
 * pontuações e capitalização), como "radar" ou "madam".
 *
 * @param palavra: A palavra a ser verificada.
 * @return: Retorna 'true' se a palavra for um palíndromo, caso contrário, 'false'.
 */
bool verificar(string palavra) {
    // Caso base: se a palavra tiver apenas uma letra ou nenhuma, ela é um palíndromo.
  if (palavra.size() <= 1) {
    return true;
  }

  // Verifica se os caracteres das extremidades são iguais e, em caso afirmativo,
  // chama recursivamente a função para a subpalavra no meio.
  if (palavra[0] == palavra.back() && verificar(palavra.substr(1, palavra.length() - 2))) {
    return true;
  }

  // Se não atender à condição acima, a palavra não é um palíndromo.
  return false;
}

int main() {
  string palavra;
  cout << "Digite uma palavra: " << endl;
  cin >> palavra;

  // Chama a função 'verificar' e imprime o resultado.
  if (verificar(palavra)) {
    cout << "A palavra é um palíndromo." << endl;
  }
  else {
    cout << "A palavra não é um palíndromo." << endl;
  }

  return 0;
}
