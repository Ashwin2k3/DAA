#include <iostream>
#include <vector>
using namespace std;

// Function to perform simple matrix multiplication
vector<vector<int>> multiplyMatrix(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size();    // Rows of matrix A
    int n = A[0].size(); // Columns of matrix A
    int p = B[0].size(); // Columns of matrix B

    vector<vector<int>> result(m, vector<int>(p, 0));

    // Perform multiplication
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

int main() {
    vector<vector<int>> A = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> B = {{7, 8}, {9, 10}, {11, 12}};

    vector<vector<int>> result = multiplyMatrix(A, B);

    // Display the result of matrix multiplication
    cout << "Resultant matrix after multiplication:" << endl;
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

