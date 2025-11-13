#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();

    int dp[n][n];

    // normal initialization to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    // length of chain
    for (int len = 2; len < n; len++) {

        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][n-1];
}
