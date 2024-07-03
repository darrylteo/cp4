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

int cnt;

void kmp() {
    n = T.size();
    int i = 0, j = 0;
    while (i < n) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        i++; j++;
        if (j == m) {
            j = b[j];
            cnt++;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) {
        map<char, int> alphabet;
        map<int, char> alphabetInverse;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            alphabet[s[i]] = i;
            alphabetInverse[i] = s[i];
        }
        cin >> P >> T;
        m = P.size();
        vector<int> ans;
        // shift 0
        kmpPreprocess();
        cnt = 0;
        kmp();
        if (cnt == 1) {
            ans.push_back(0);
        }
        // shift 1 to s.size() - 1
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; j < m; ++j) {
                P[j] = alphabetInverse[(alphabet[P[j]] + 1) % s.size()];
            }
            kmpPreprocess();
            cnt = 0;
            kmp();
            if (cnt == 1) {
                ans.push_back(i);
            }
        }
        // output
        if (ans.empty()) {
            cout << "no solution" << endl;
        } else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << '\n';
        } else {
            cout << "ambiguous: ";
            for (int i = 0; i < ans.size() - 1; ++i) {
                cout << ans[i] << " ";
            }
            cout << ans[ans.size() - 1] << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


