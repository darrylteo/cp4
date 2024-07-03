#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    bool cups[3] = {true, false, false};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'A') {
            swap(cups[0], cups[1]);
        } else if (s[i] == 'B') {
            swap(cups[1], cups[2]);
        } else {
            swap(cups[0], cups[2]);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (cups[i]) {
            cout << i + 1 << endl;
            break;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
