#include <bits/stdc++.h>

using namespace std;

bool canMatch(const string& s, const string& D) {
    int n = s.size();
    int m = D.size();
    if (n != m) return false;
    unordered_map<char, char> DtoS, StoD;
    for (int i = 0; i < n; i++) {
        if (DtoS.find(D[i]) == DtoS.end()) {
            DtoS[D[i]] = s[i];
        } else if (DtoS[D[i]] != s[i]) {
            return false;
        }
        if (StoD.find(s[i]) == StoD.end()) {
            StoD[s[i]] = D[i];
        } else if (StoD[s[i]] != D[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> mStart(n), mEnd;
        for (int i = 0; i < n; i++) cin >> mStart[i];
        string D, X;
        cin >> D >> X;
        for (const string& s: mStart) {
            if (canMatch(s, D)) mEnd.push_back(s);
        }
        if (mEnd.size() == 0) {
            cout << "IMPOSSIBLE\n";
        } else {
            unordered_map<char, char> decrypt, encrypt;
            // put the first string in mEnd into map
            for (int i = 0; i < D.size(); i++) {
                decrypt[mEnd[0][i]] = D[i];
                encrypt[D[i]] = mEnd[0][i];
            }
            // check for mix-ups. e.g. in sample input 3
            for (int i = 1; i < mEnd.size(); i++) {
                for (int j = 0; j < D.size(); j++) {
                    if (encrypt[D[j]] != mEnd[i][j]) { // from example, encrypt['e'] = 'b' but on second round it is 'f'. so 'b' and 'f' cannot be used in decryption
                        decrypt[encrypt[D[j]]] = '?';
                        decrypt[mEnd[i][j]] = '?';
                    }
                }
            }
            // check if 1 letter remaining
            if (decrypt.size() == 25 && encrypt.size() == 25) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (decrypt.find(c) == decrypt.end()) {
                        for (char d = 'a'; d <= 'z'; d++) {
                            if (encrypt.find(d) == encrypt.end()) {
                                decrypt[c] = d;
                                encrypt[d] = c;
                                break;
                            }
                        }
                    }
                }
            }
            // print answer
            for (char c: X) {
                cout << (decrypt.find(c) == decrypt.end() ? '?' : decrypt[c]);
            }
            cout << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

