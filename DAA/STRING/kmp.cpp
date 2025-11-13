#include <bits/stdc++.h>
using namespace std;

// Build LPS (Longest Prefix Suffix) array
void computeLPS(string pat, vector<int>& lps) {
    int m = pat.size();
    int len = 0;      // length of previous longest prefix-suffix
    lps[0] = 0;       // lps[0] is always 0

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len != 0) {
                len = lps[len - 1];  // go to previous LPS
            } 
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search
void KMPSearch(string text, string pat) {
    int n = text.size();
    int m = pat.size();

    vector<int> lps(m);
    computeLPS(pat, lps);

    int i = 0; // index for text
    int j = 0; // index for pattern

    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j - 1];  // continue searching
        }

        else if (i < n && text[i] != pat[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text = "ababcabcabababd";
    string pat = "ababd";

    KMPSearch(text, pat);
}
