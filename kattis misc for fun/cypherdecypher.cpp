#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string mult;
    int Q;
    cin >> mult >> Q;
    while (Q--) {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            int val = s[i] - 'A';
            val = (val * stoi(mult.substr(i, 1))) % 26;
            cout << (char) (val + 'A');
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
