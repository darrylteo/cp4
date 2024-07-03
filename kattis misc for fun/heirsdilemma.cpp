#include <bits/stdc++.h>

using namespace std;

bool ok(int x) {
    int tmp = x;
    vector<int> digits(10, 0);
    while (x) {
        int dig = x % 10;
        digits[dig]++;
        if (digits[dig] > 1) return false;
        if (dig == 0) return false;
        x /= 10;
    }
    for (int i = 1; i <= 9; i++) {
        if (digits[i] == 1) {
            if (tmp%i) return false;
        }
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (ok(i)) {
            cnt++;
        }
    }
    cout << cnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
