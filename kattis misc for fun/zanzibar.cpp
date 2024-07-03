#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    string buf;
    getline(cin, buf);
    T = stoi(buf);
    while (T--) {
        getline(cin, buf);
        stringstream ss(buf);
        int curr, prev, ans = 0;
        ss >> prev;
        while (ss >> curr) {
            if (curr > 2 * prev) {
                ans += curr - 2 * prev;
            }
            prev = curr;
        }
        cout << ans << '\n';
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
