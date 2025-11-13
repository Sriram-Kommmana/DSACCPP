#include <bits/stdc++.h>
using namespace std;

int rodCutRec(vector<int>& len, vector<int>& price, int n, int rod) {
    if (n == 0 || rod == 0)
        return 0;

    if (len[n-1] <= rod) {
        return max(
            price[n-1] + rodCutRec(len, price, n, rod - len[n-1]),
            rodCutRec(len, price, n-1, rod)
        );
    }
    else {
        return rodCutRec(len, price, n-1, rod);
    }
}

int main() {
    vector<int> len = {1,2,3,4,5,6,7,8};
    vector<int> price = {1,5,8,9,10,17,17,20};
    int rod = 8;
    cout << rodCutRec(len, price, len.size(), rod);
}
