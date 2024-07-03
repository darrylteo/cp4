#include <bits/stdc++.h>

using namespace std;

// huhh? since when did kattis check on extra spaces and newlines.

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bool a[1001] = {};
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[x] = true;
    }
    string s;
    for (int i = 0; i < 1001; ++i) {
        if (a[i]) {
            int x = i;
            while (a[x] == a[x + 1]) { // while next bus also exists
                ++x;
            }
            if (x == i) {
//                cout << i << ' ';
                s += to_string(i) + ' ';
            } else if (x == i + 1) {
//                cout << i << ' ' << x << ' ';
                s += to_string(i) + ' ' + to_string(x) + ' ';
            } else if (x > i + 1) {
//                cout << i << '-' << x << ' ';
                s += to_string(i) + '-' + to_string(x) + ' ';
            }
            i = x; // skip till here
        }
    }
    s.pop_back();
    cout << s << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
