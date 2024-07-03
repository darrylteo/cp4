#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cases = 0, n;
    while (cin >> n, n) {
        vector<string> front, back;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (i % 2 == 0) {
                front.push_back(s);
            } else {
                back.push_back(s);
            }
        }
        reverse(back.begin(), back.end());
        cout << "SET " << ++cases << endl;
        for (auto &s : front) {
            cout << s << endl;
        }
        for (auto &s : back) {
            cout << s << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}
