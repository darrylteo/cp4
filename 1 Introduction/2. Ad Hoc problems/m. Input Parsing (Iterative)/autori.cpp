#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string s;
    cin >> s;
    string res;
    for (char c : s) {
        if (c>='A' && c<='Z') {
            res += c;
        }
    }
    cout << res << endl;
    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}