#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int level;
    int profit;
    int weight;
    float bound;
};

bool compareByRatio(pair<int, int> a, pair<int, int> b) {
    return (float)a.second / a.first > (float)b.second / b.first;
}

float calculateBound(Node u, int n, int capacity, const vector<pair<int, int>>& items) {
    if (u.weight >= capacity) {
        return 0;
    }

    float bound = u.profit;
    int totalWeight = u.weight;
    for (int i = u.level + 1; i < n; i++) {
        if (totalWeight + items[i].first <= capacity) {
            totalWeight += items[i].first;
            bound += items[i].second;
        } else {
            bound += (capacity - totalWeight) * ((float)items[i].second / items[i].first);
            break;
        }
    }
    return bound;
}

int knapsackBranchAndBound(int capacity, vector<pair<int, int>>& items) {
    sort(items.begin(), items.end(), compareByRatio);

    queue<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    u.bound = calculateBound(u, items.size(), capacity, items);
    Q.push(u);

    int maxProfit = 0;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == -1 || u.bound > maxProfit) {
            v.level = u.level + 1;
            v.weight = u.weight + items[v.level].first;
            v.profit = u.profit + items[v.level].second;

            if (v.weight <= capacity && v.profit > maxProfit) {
                maxProfit = v.profit;
            }

            v.bound = calculateBound(v, items.size(), capacity, items);
            if (v.bound > maxProfit) {
                Q.push(v);
            }

            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = calculateBound(v, items.size(), capacity, items);
            if (v.bound > maxProfit) {
                Q.push(v);
            }
        }
    }
    return maxProfit;
}

int main() {
    vector<pair<int, int>> items = {{2, 40}, {3, 50}, {4, 100}, {5, 95}};
    int capacity = 7;

    cout << "Valor máximo na mochila: " << knapsackBranchAndBound(capacity, items) << endl;

    return 0;
}
