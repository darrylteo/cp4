#include <bits/stdc++.h>

using namespace std;

// seems like next_permutation can already

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<char> v;
    for (char c : s) {
        v.push_back(c);
    }
    if (next_permutation(v.begin(), v.end())) {
        for (char c : v) {
            cout << c;
        }
    } else {
        cout << 0;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
