#include <bits/stdc++.h>

using namespace std;

// we try replacing a wrong letter with a random letter as long it's in the dict.
// discard this item in dict so don't revisit.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unordered_set<string> dict;
    string s;
    while (cin >> s) {
        if (s == "--") break;
        dict.insert(s);
    }
    string s1, s2;
    while (cin >> s1 >> s2) {
        unordered_set<string> tmpDict = dict;
        if (s1 == s2) {
            cout << "Yes\n";
            continue;
        }
        queue<string> q;
        q.emplace(s1);
        int found = 0;
        while (!q.empty()) {
            string ss = q.front();
            q.pop();
            if (ss == s2) {
                cout << "Yes\n";
                found = 1;
                break;
            }
            for (int i = 0; i < ss.size(); i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == ss[i]) continue;
                    string t = ss;
                    t[i] = c;
                    if (tmpDict.find(t) != tmpDict.end() || t == s2) {
                        q.emplace(t);
                        tmpDict.erase(t);
                    }
                }
            }
        }
        if (!found) cout << "No\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
