#include <bits/stdc++.h>

using namespace std;

int lastZeroIndex(string a) {
    int n = a.size(), cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == '0') {
            cnt++;
        } else {
            return n - cnt;
        }
    }
    return 0;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    string a, b, ans;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    if (n >= m) {
        for (int i = 0; i < n - m + 1; i++) {
            ans += a[i];
        }
        int lastZero = lastZeroIndex(a); // last from back i.e. first from left
        if (lastZero >= n - m + 1) {
            ans += ".";
        }
        for (int i = n - m + 1; i < lastZero; i++) {
            ans += a[i];
        }

    } else {
        ans += "0.";
        for (int i = 0; i < m - n - 1; i++) {
            ans += "0";
        }
        for (int i = 0; i < n; i++) {
            ans += a[i];
        }
    }

    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




