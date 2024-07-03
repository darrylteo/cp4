#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

bool checkArithmetic(vi &v) {
    int n = v.size();
    if (n == 1) {
        return true;
    }
    int d = v[1] - v[0];
    for (int i = 2; i < n; i++) {
        if (v[i] - v[i - 1] != d) {
            return false;
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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if (checkArithmetic(v)) {
            cout << "arithmetic" << '\n';
            continue;
        }
        sort(v.begin(), v.end());
        if (checkArithmetic(v)) {
            cout << "permuted arithmetic" << '\n';
            continue;
        } else {
            cout << "non-arithmetic" << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}

