#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cuts = -1; // don't cut on first word insertion
        set<char> matched;
        while (n--) {
            string newWord;
            cin >> newWord;
            vector<char> toRemove;
            for (char c: matched) {
                if (newWord.find(c) == string::npos) { // can't match newWord
                    toRemove.push_back(c);
                }
            }
            for (char c: toRemove) {
                matched.erase(c);
            }
            if (matched.empty()) {
                cuts++;
                for (char c: newWord) {
                    matched.insert(c);
                }
            }
        }
        cout << cuts << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
