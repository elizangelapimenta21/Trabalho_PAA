//Na mochila fracionária, cada item pode ser dividido para aproveitar o espaço.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estrutura para armazenar peso e valor
struct Item {
    int weight;
    int value;

    // Para ordenação decrescente com base no valor por peso
    bool operator<(const Item& other) const {
        return (double)value / weight > (double)other.value / other.weight;
    }
};

double fractionalKnapsack(int capacity, const vector<Item>& items) {
    vector<Item> sortedItems = items;
    sort(sortedItems.begin(), sortedItems.end());

    double maxValue = 0.0;

    for (const Item& item : sortedItems) {
        if (capacity >= item.weight) {
            maxValue += item.value;
            capacity -= item.weight;
        } else {
            maxValue += (double)capacity / item.weight * item.value;
            break;
        }
    }

    return maxValue;
}

int main() {
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int capacity = 50;

    cout << "Problema da Mochila Fracionária:\n";
    cout << "Capacidade: " << capacity << "\n";
    cout << "Valor máximo: " << fractionalKnapsack(capacity, items) << "\n";

    return 0;
}
