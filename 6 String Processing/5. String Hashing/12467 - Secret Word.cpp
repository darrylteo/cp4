#include <bits/stdc++.h>

using namespace std;


string T, P;
int n, m, b[1000005]; // b = back table

void kmpPreprocess() {                                // call this first
    int i = 0, j = -1;
    b[0] = -1;                     // starting values
    while (i < m) {                                   // pre-process P
        while ((j >= 0) && (P[i] != P[j])) j = b[j];  // different, reset j
        ++i;
        ++j;                                     // same, advance both
        b[i] = j;
    }
}

int best;

void kmp() {
    n = T.size();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if (j > best) best = j;
        if (j == m) j = b[j];
    }
}

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// kmp can find out the longest substring that matches the prefix of the string

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> P;
        if (isPalindrome(P)) {
            cout << P << endl;
            continue;
        }
        m = P.size();
        T = P;
        reverse(T.begin(), T.end());
        kmpPreprocess();

        best = 0;
        kmp();
        string ans = P.substr(0, best);
        reverse(ans.begin(), ans.end());
        if (ans.empty()) cout << P[0] << '\n';
        else cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


