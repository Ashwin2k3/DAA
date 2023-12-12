#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the Longest Common Subsequence using Dynamic Programming
string longestCommonSubsequence(const string& text1, const string& text2) {
    int m = text1.size();
    int n = text2.size();

    // Create a DP matrix to store the lengths of LCS
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP matrix
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Retrieve the Longest Common Subsequence from the DP matrix
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs = text1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return lcs;
}

int main() {
    string text1 = "ABCBDAB";
    string text2 = "BDCAB";

    cout << "Text 1: " << text1 << endl;
    cout << "Text 2: " << text2 << endl;

    string lcs = longestCommonSubsequence(text1, text2);

    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}

