#include <iostream>
#include <locale.h>

using namespace std;

/**
 * Função para criar um conjunto de inteiros.
 * @param vetor: Referência para o vetor a ser preenchido.
 * @param tamanho: Referência para o tamanho do vetor.
 */
void criar(int*& vetor, int& tamanho) {
  cout << "Digite o tamanho do conjunto: ";
  cin >> tamanho;

  vetor = new int[tamanho];

  for (int i = 0; i < tamanho; i++) {
    cout << "Digite o elemento " << i + 1 << ": ";
    cin >> vetor[i];
  }
}

/**
 * Função recursiva para gerar e imprimir todos os subconjuntos de um conjunto.
 * @param conjunto: Conjunto original.
 * @param subconjunto: Array temporário para armazenar subconjuntos enquanto são gerados.
 * @param tamanhoConjunto: Tamanho do conjunto original.
 * @param posicao: Posição atual no conjunto.
 * @param posicaoSubconjunto: Posição atual no subconjunto.
 */
void gerarSubconjuntos(const int* conjunto, int* subconjunto, int tamanhoConjunto, int posicao, int posicaoSubconjunto) {

    // Base da recursão: se a posição atual for igual ao tamanho do conjunto, imprime o subconjunto.
  if (posicao == tamanhoConjunto) {
    cout << "{ ";
    for (int i = 0; i < posicaoSubconjunto; i++) {
      cout << subconjunto[i] << " ";
    }
    cout << "}" << endl;
    return;
  }

  // Recursão sem adicionar o elemento atual ao subconjunto.
  gerarSubconjuntos(conjunto, subconjunto, tamanhoConjunto, posicao + 1, posicaoSubconjunto);

  // Adicionar o elemento atual ao subconjunto e chamar a função recursivamente.
  subconjunto[posicaoSubconjunto] = conjunto[posicao];
  gerarSubconjuntos(conjunto, subconjunto, tamanhoConjunto, posicao + 1, posicaoSubconjunto + 1);
}

int main() {
  setlocale(LC_ALL, "portuguese");
  int tamanho;
  int* conjunto;

  criar(conjunto, tamanho);

  // Array temporário para armazenar subconjuntos enquanto são gerados.
  int* subconjunto = new int[tamanho];

  gerarSubconjuntos(conjunto, subconjunto, tamanho, 0, 0);

  // Liberar memória.
  delete[] subconjunto;
  delete[] conjunto;

  return 0;
}
