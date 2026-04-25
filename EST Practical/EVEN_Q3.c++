#include <bits/stdc++.h>
using namespace std;
vector<int> computeLPS(string pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0, i = 1;

    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } 
        else {
            if (len != 0)
                len = lps[len - 1];
            else
                i++;
        }
    }
    return lps;
}
void KMP(string text, string pattern) {
    vector<int> lps = computeLPS(pattern);
    vector<int> ans;

    int i = 0, j = 0;

    while (i < text.length()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == pattern.length()) {
            ans.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < text.length() && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    if (ans.empty()) {
        cout << "[]";
    } else {
        cout << "[";
        for (int k = 0; k < ans.size(); k++) {
            cout << ans[k];
            if (k != ans.size() - 1)
                cout << ", ";
        }
        cout << "]";
    }
}

int main() {
    string text, pattern;

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    KMP(text, pattern);

    return 0;
}