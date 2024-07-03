#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n, root;
    string s;
    cin >> n;
    root = pow(2, n + 1) - 1;
    int currPos = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L') {
            currPos = currPos * 2 + 1;
        } else {
            currPos = currPos * 2 + 2;
        }
    }
    cout << root - currPos << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
