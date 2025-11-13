#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int lcsMemo(string s1, string s2, int i, int j) {
    if (i == 0 || j == 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i-1] == s2[j-1])
        return dp[i][j] = 1 + lcsMemo(s1, s2, i-1, j-1);

    return dp[i][j] = max(lcsMemo(s1, s2, i-1, j),
                          lcsMemo(s1, s2, i, j-1));
}

int main() {
    string s1 = "abcde";
    string s2 = "ace";

    // normal initialization
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            dp[i][j] = -1;

    cout << lcsMemo(s1, s2, s1.size(), s2.size());
}
