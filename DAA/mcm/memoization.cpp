#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int mcm(int i, int j, vector<int>& arr) {
    if (i == j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {
        int cost = mcm(i, k, arr) + mcm(k + 1, j, arr) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans, cost);
    }

    dp[i][j] = ans;
    return ans;
}

int main() {
    vector<int> arr = {40, 20, 30, 10, 30};
    int n = arr.size();

    // normal initialization
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            dp[i][j] = -1;

    cout << mcm(1, n - 1, arr);
}
