#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    end:
    while (T--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.size();
        vector<int> sub1(26), sub2(26);
        set<vector<int>> sub1_set, sub2_set;
        // build the set of substrings of daughter 1st
        for (int i = n; i > 0; --i) { // substr size i
            // init sub2
            sub2.assign(26, 0);
            for (int j = 0; j < i; ++j) ++sub2[s2[j] - 'a'];
            for (int j = 0; j <= n - i; ++j) { // start index j for s2
                if (j != 0) {
                    --sub2[s2[j - 1] - 'a'];
                    ++sub2[s2[j + i - 1] - 'a'];
                }
                sub2_set.insert(sub2);
            }
        }

        // check each word in father dict
        for (int i = n; i > 0; --i) { // substr size i
            // init sub1
            sub1.assign(26, 0);
            for (int j = 0; j < i; ++j) ++sub1[s1[j] - 'a'];
            for (int j = 0; j <= n - i; ++j) { // start index j for s1
                if (j != 0) {
                    --sub1[s1[j - 1] - 'a'];
                    ++sub1[s1[j + i - 1] - 'a'];
                }
                if (sub2_set.find(sub1) != sub2_set.end()) {
                    cout << s1.substr(j, i) << '\n';
                    goto end;
                }
            }
        }
        cout << "NONE\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
