#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    next:
    while (cin >> a >> b) {
        int lastPos = -1;
        for (char c: a) {
            int newLastPos = b.find(c, lastPos + 1);
            if (newLastPos == string::npos) {
                cout << "No" << endl;
                goto next;
            }
            if (newLastPos <= lastPos) {
                cout << "No" << endl;
                goto next;
            }
            lastPos = newLastPos;
        }
        cout << "Yes" << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
