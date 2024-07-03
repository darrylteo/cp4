#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int chars[20] = {};
        for (int i = 1; i <= x; ++i) {
            string s = to_string(i);
            for (char c : s) {
                chars[c - '0']++;
            }
        }
        for (int i = 0; i < 9; ++i) {
            cout << chars[i] << " ";
        }
        cout << chars[9];
        cout << "\n";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}