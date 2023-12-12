#include <iostream>
#include <vector>
#include <climits>
using namespace std;

float optimalBST(const vector<float>& probabilities, int n) {
    vector<vector<float>> dp(n + 2, vector<float>(n + 1, 0));
    vector<float> prefixSum(n + 2, 0);

    // Compute prefix sum for probabilities
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + probabilities[i];
    }

    // Initialize base cases for single nodes
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = probabilities[i];
    }

    for (int length = 2; length <= n; ++length) {
        for (int i = 1; i <= n - length + 1; ++i) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            float sum = prefixSum[j] - prefixSum[i - 1];

            for (int r = i; r <= j; ++r) {
                float cost = dp[i][r - 1] + dp[r + 1][j] + sum;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    vector<float> probabilities = {0, 0.15, 0.10, 0.05, 0.10, 0.20};
    int n = probabilities.size() - 1; // Number of keys

    cout << "Initial probabilities: ";
    for (int i = 1; i <= n; ++i) {
        cout << probabilities[i] << " ";
    }
    cout << endl;

    float minCost = optimalBST(probabilities, n);

    cout << "Minimum search cost for Optimal BST: " << minCost << endl;

    return 0;
}

