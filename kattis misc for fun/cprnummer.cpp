#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    vector<int> v = {4, 3, 2, 7, 6, 5, 0, 4, 3, 2, 1};
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '-') {
            sum += (s[i] - '0') * v[i];
        }
    }

    int rem = sum % 11;
    if (rem == 0) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
