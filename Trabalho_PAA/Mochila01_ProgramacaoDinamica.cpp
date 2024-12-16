//Problema da Mochila 0-1 (0/1 Knapsack): O objetivo é maximizar o valor total, 
//sem exceder o peso permitido, considerando que cada item pode 
//ser selecionado no máximo uma vez.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Função para resolver o problema da mochila 0/1
int knapsack01(int capacity, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 5;

    cout << "Problema da Mochila 0/1:\n";
    cout << "Capacidade: " << capacity << "\n";
    cout << "Valores máximos: " << knapsack01(capacity, weights, values) << "\n";

    return 0;
}
