#include <iostream>

using namespace std;

// Mescla duas subpartes de arr[].
void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;  // n1 e n2 são os tamanhos das duas subpartes a serem mescladas
  int L[n1], R[n2];  // Arrays temporários para armazenar as duas subpartes a serem mescladas

  // Copiar dados para L[] e R[]
  for (int i = 0; i < n1; i++) L[i] = arr[l + i];
  for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

  // Iniciar o processo de mesclagem de L[] e R[] de volta para arr[]
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
      // Se o elemento atual de L[] for menor ou igual ao elemento atual de R[], 
      // então adicione L[i] em arr[k] e mova para o próximo elemento de L[]
    arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
  }
  // Copiar os elementos restantes de L[], se houver algum
  while (i < n1) arr[k++] = L[i++];
  // Copiar os elementos restantes de R[], se houver algum
  while (j < n2) arr[k++] = R[j++];
}

// Implementa o Merge Sort
void mergeSort(int arr[], int l, int r) {
    // Base da recursão: se l < r, ou seja, se o segmento tem mais de 1 elemento
  if (l < r) {
    int m = l + (r - l) / 2;   // Encontra o meio do array para dividí-lo em duas metades
    mergeSort(arr, l, m);     // Ordena a primeira metade
    mergeSort(arr, m + 1, r); // Ordena a segunda metade
    merge(arr, l, m, r);      // Mescla as duas metades ordenadas
  }
}

int main() {
  int arr[] = { 12, 11, 13, 5, 6, 7 }; // Array de exemplo a ser ordenado
  int size = sizeof(arr) / sizeof(arr[0]);

  // Ordena o array usando merge sort
  mergeSort(arr, 0, size - 1);

  // Imprime o array ordenado
  for (int i = 0; i < size; i++) cout << arr[i] << " ";

  return 0;
}
