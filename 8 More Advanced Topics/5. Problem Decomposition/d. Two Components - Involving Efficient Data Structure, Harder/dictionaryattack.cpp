#include <bits/stdc++.h>

using namespace std;

// sort of meet in the middle. dictionary do swaps only, and query do digit replacement only.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vector<unordered_set<string>> st(4); // after 0, 1, 2, 3 swaps
    while (n--) {
        string s;
        cin >> s;
        st[0].insert(s);
    }
    for (int k = 1; k <= 3; ++k) {
        for (auto &s: st[k - 1]) {
            for (int i = 0; i < s.size() - 1; i++) {
                string t = s;
                swap(t[i], t[i + 1]);
                st[k].insert(t);
            }
        }
    }
    string q;
    while (cin >> q) {
        // only check is st[x], where x<=3-numCnt, contains q. e.g. 1 numCnt could be 0, 1, 2 swap.
        int numCnt = 0;
        for (char c: q) if (isdigit(c)) numCnt++;
        if (numCnt > 3) {
            cout << q << '\n';
            continue;
        }
        vector<string> words[numCnt + 1];
        words[0].push_back(q);
        // replace each digit with a letter
        for (int k = 1; k <= numCnt; ++k) {
            for (auto &s: words[k - 1]) {
                for (int i = 0; i < s.size(); ++i) {
                    if (isdigit(s[i])) {
                        for (char c = 'a'; c <= 'z'; ++c) {
                            string t = s;
                            t[i] = c;
                            words[k].push_back(t);
                        }
                        for (char c = 'A'; c <= 'Z'; ++c) {
                            string t = s;
                            t[i] = c;
                            words[k].push_back(t);
                        }
                        break; // only change one digit
                    }
                }
            }
        }
        bool found = false;
        for (const string& word: words[numCnt]) { // words with all digits replaced
            if (found) break;
            int minn = 0, maxx = 3 - numCnt; // 3- numCnt or less swaps
            for (int k = minn; k <= maxx; ++k) {
                if (st[k].count(word)) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) cout << q << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
