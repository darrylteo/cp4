#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cout << "Case " << i << ": ";
        int m;
        cin >> m;
        vector<string> words;
        string s;
        for (int j = 0; j < m; ++j) {
            cin >> s;
            words.push_back(s);
        }
        sort(words.begin(), words.end());
        int best = INT_MAX;
        do {
            string combined = words[0];
            for (int j = 1; j < m; ++j) {
                string next = words[j];
                string curr = combined;
                int len = min(next.length(), curr.length());
                int matchSize = 0;
                for (int k = 0; k < len; ++k) {
                    string a = curr.substr(curr.length() - k - 1);
                    string b = next.substr(0, k + 1);
                    if (a == b) {
                        matchSize = k + 1;
                    }
                }
                combined += next.substr(matchSize);
            }
            best = min(best, (int) combined.length());
        } while (next_permutation(words.begin(), words.end()));
        cout << best << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
