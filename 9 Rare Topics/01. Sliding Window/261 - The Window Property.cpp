#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string s;
    while (getline(cin, s)) { // can have spaces -_-
        int bad = 0, earliestIdx = 1e9;
        for (int sz = 1; sz <= s.size(); sz++) {
            set<string> st;
            for (int i = 0; i + sz <= s.size(); i++) {
                st.insert(s.substr(i, sz));
                if (st.size() == sz + 2) {
                    earliestIdx = min(earliestIdx, i + sz);
                    bad = 1;
                    break;
                }
            }
        }
        if (!bad) cout << "YES\n";
        else cout << "NO:" << earliestIdx << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}