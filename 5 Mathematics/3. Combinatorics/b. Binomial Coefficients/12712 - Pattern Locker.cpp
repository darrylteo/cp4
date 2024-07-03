#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

//ans=SUM_{i=M}^{N} L2 choose i * i!
//L2!/(L2-i)!
//
//10!/7!
//=10x9x8
//
//10!/6!
//=10x9x8x7
//
//10!/5!
//=10x9x8x7x6
//
// add up = 10x9x8x(1+7x(1+6))
// if until 4!, then 10x9x8x(1+7x(1+6x(1+5))) // O(N)

#define MOD 10000000000007

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        int L, M, N;
        cin >> L >> M >> N;
        int L2 = L * L;
        ull first = L2 - N + 1, last = L2 - M + 1; // from our example first = 5, last 8
        ull ans = first;
        for (ull i = first; i < last; ++i) {
            ans = (ans + 1) * (i + 1) % MOD;
        }
        for (ull i = last + 1; i <= L2; ++i) {
            ans *= i;
            ans %= MOD;
        }
        cout << "Case " << cases << ": " << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}


