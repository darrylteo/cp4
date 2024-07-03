#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1300;
const int MAX_W = 1300;
const int MAX_K = 20;

// W is remaining value, K is remaining cnt of numbers

int N, k, ans, memo[MAX_N][MAX_W][MAX_K];

// generate primes
vector<int> primes;
bitset<MAX_N> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < MAX_N; ++i)
        if (bs[i]) {
            primes.push_back(i);
            for (int j = i * i; j < MAX_N; j += i) bs[j] = 0;
        }
}

// rather than store best weight, memo stores the number of ways to get the final answer once we get to this point
int dp(int idx, int remW, int remK) {
    if (remW == 0 && remK == 0) return 1;
    if (idx == primes.size() || remW < 0 || remK < 0) return 0;
    if (memo[idx][remW][remK] != -1) return memo[idx][remW][remK];
    return memo[idx][remW][remK] = dp(idx + 1, remW, remK) + dp(idx + 1, remW - primes[idx], remK - 1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    memset(memo, -1, sizeof memo); // don't reset since the weight (=1) and values (primes) don't change
    while (cin >> N >> k, N || k) {
        ans = 0;
        for (int i = 0; i < primes.size(); ++i) {
            if (primes[i] > N) break;
            ans += dp(i + 1, N - primes[i], k - 1);
        }
        cout << ans << '\n';


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
