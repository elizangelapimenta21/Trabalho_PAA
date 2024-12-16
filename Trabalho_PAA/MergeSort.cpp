#include <iostream>
#include <vector>

using namespace std;

// Função para mesclar dois subvetores
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Preenchendo os subvetores L e R
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Mesclando os subvetores de volta ao vetor original
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Copiando elementos restantes, se existirem
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Função principal do MergeSort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Divisão
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Conquista
        merge(arr, left, mid, right);
    }
}

// Função para imprimir o vetor
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> test1 = {38, 27, 43, 3, 9, 82, 10};
    vector<int> test2 = {1, 3, 2, 6, 4, 5};
    vector<int> test3 = {10, 8, 6, 4, 2, 0};

    cout << "Caso de Teste 1: ";
    printArray(test1);
    mergeSort(test1, 0, test1.size() - 1);
    cout << "Ordenado: ";
    printArray(test1);

    cout << "Caso de Teste 2: ";
    printArray(test2);
    mergeSort(test2, 0, test2.size() - 1);
    cout << "Ordenado: ";
    printArray(test2);

    cout << "Caso de Teste 3: ";
    printArray(test3);
    mergeSort(test3, 0, test3.size() - 1);
    cout << "Ordenado: ";
    printArray(test3);

    return 0;
}
