#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, vector<int>& board, int row, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(n, board, row + 1, solutions);
        }
    }
}

void printSolutions(const vector<vector<int>>& solutions, int n) {
    for (const auto& solution : solutions) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (solution[i] == j) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    int n = 16;  // Alterar para outro valor de N, se necessário
    vector<int> board(n, -1);
    vector<vector<int>> solutions;

    solveNQueens(n, board, 0, solutions);

    cout << "Número de soluções encontradas: " << solutions.size() << "\n";
    printSolutions(solutions, n);

    return 0;
}
