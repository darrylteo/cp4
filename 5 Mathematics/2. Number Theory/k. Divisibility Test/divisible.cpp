#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int MOD, n, ans = 0, cum = 0;
        cin >> MOD >> n;
        unordered_map<int, int> m;
        while (n--) {
            int x;
            cin >> x;
            cum = (cum + x) % MOD;
            if (cum == 0) {
                ans++;
            }
            ans += m[cum]; // m[cum] is the number of times cum has occurred before so if we take this cumsum - those cumsums we would get a perfectly divisible subarray
            m[cum]++;
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


