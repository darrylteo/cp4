#include <bits/stdc++.h>

using namespace std;

// simple example why we need to insert into unordered_set
/*
1
2 2
ab
abcd
e
cde
*/
// ab + cde == abcd + e

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
        unordered_set<string> s;
        vector<string> a, b;
        int x, y;
        cin >> x >> y;
        cin.ignore();
        for (int j = 0; j < x; ++j) {
            string t;
            getline(cin, t);
            a.push_back(t);
        }
        for (int j = 0; j < y; ++j) {
            string t;
            getline(cin, t);
            b.push_back(t);
        }
        for (const auto& j : a) {
            for (const auto& k : b) {
                s.insert(j + k);
            }
        }
        cout << s.size() << '\n';

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
