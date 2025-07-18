#include <iostream>
#include <locale.h>
using namespace std;

/**
 * Função para criar e preencher um vetor.
 *
 * @param vetor: Ponteiro de referência para o vetor que será alocado dinamicamente.
 * @param tamanho: Referência para a variável que armazenará o tamanho do vetor.
 * @return: O primeiro elemento do vetor. No entanto, esta decisão de design pode ser revisada, pois pode ser confusa.
 */
int criarVetor(int*& vetor, int& tamanho) {
  cout << "Digite o tamanho do vetor: ";
  cin >> tamanho;

  // Aloca espaço dinamicamente para o vetor com base no tamanho fornecido pelo usuário.
  vetor = new int[tamanho];

  // Preenche o vetor com os valores fornecidos pelo usuário.
  for (int i = 0; i < tamanho; i++) {
    cout << "Digite o elemento " << i + 1 << " do vetor: ";
    cin >> vetor[i];
  }

  // A função retorna o primeiro elemento. Pode ser revisado para tornar o design mais claro.
  return vetor[0];
}

/**
 * Função recursiva para encontrar o maior valor no vetor.
 *
 * @param vetor: Ponteiro para o vetor.
 * @param tamanho: Tamanho do vetor ou subvetor a ser verificado.
 * @return: O maior valor no vetor ou subvetor.
 */
int encontrarMaior(int* vetor, int tamanho) {
    // Caso base: se o tamanho do vetor ou subvetor for 1, 
    // o único elemento presente é o maior.
  if (tamanho == 1) {
    return vetor[0];
  }

  // Chamada recursiva para encontrar o maior valor no restante do vetor, 
  // ignorando o primeiro elemento.
  int maiorRestante = encontrarMaior(vetor + 1, tamanho - 1);

  // Retorna o maior entre o primeiro elemento e o maior valor encontrado no restante do vetor.
  return (vetor[0] > maiorRestante) ? vetor[0] : maiorRestante;
}

int main() {
  setlocale(LC_ALL, "portuguese");
  int tamanho;
  int* vetor;

  criarVetor(vetor, tamanho);

  // Encontra e imprime o maior valor no vetor.
  int maior = encontrarMaior(vetor, tamanho);
  cout << "O maior valor no vetor é: " << maior << endl;

  // Libera a memória previamente alocada para o vetor.
  delete[] vetor;

  return 0;
}
