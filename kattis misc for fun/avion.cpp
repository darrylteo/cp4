#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool found = false;
    for (int i = 1; i <= 5; ++i) {
        string s, match = "FBI";
        cin >> s;
        if (s.find(match) != string::npos) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "HE GOT AWAY!";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}