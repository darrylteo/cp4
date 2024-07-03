#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    while (cin >> n, n) {
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        stable_sort(v.begin(), v.end(), [](string a, string b) {
            if (a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        });
        for (int i = 0; i < n; i++) cout << v[i] << endl;
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
