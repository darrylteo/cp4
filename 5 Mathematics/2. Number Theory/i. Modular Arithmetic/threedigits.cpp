#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

const ull MOD = 1e12;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    cin >> n;
    ull ans = 1;
    for (ull i = 1; i <= n; i++) {
        ans *= i;
        while (ans % 10 == 0) ans /= 10;
        ans %= MOD;
    }
    string s = to_string(ans);
    int start = min((int) s.size(), 3); // important to use this else we will chop off zeroes e.g. 999 322 001 would return 1 otherwise
    s = s.substr(s.size() - start);
    cout << s << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


