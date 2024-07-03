#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

// kinda weird but can see that the pattern is sum of AP then divide by 2

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    for (int cases = 1; cases <= n; ++cases) {
        long long x;
        cin >> x;
        long long ans;
        ans = x * (x-1) / 2;
        if (ans % 2 == 0) {
            cout << "Case " << cases << ": " << ans / 2 << '\n';
        } else {
            cout << "Case " << cases << ": " << ans << "/2" << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


