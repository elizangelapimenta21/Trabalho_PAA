#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void primMST(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> key(n, INT_MAX);
    vector<bool> mstSet(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int count = 0; count < n - 1; ++count) {
        int minKey = INT_MAX, u;

        for (int v = 0; v < n; ++v) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = true;

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    cout << "Arestas na Árvore Geradora Mínima:\n";
    for (int i = 1; i < n; ++i)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    primMST(graph);
    return 0;
}
