#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

const int MAXN = 1500;

bitset<MAXN> primes;
vi p;
const int MAX_N = 2000005;
int numDiffPFarr[MAX_N+10] = {0};
int ans[MAX_N+10];

// sieve of eratosthenes. primes[i] = false if i is prime so i don't need to memset
inline void sieve() {
    primes[0] = primes[1] = true;
    for (int i = 2; i * i < MAXN; ++i) {
        if (!primes[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = true;
            }
        }
    }
}

int numDiv(ll N) {
    int ans = 1; // start from ans = 1
    for (int i = 0; (i < (int)p.size()) && (p[i]*p[i] <= N); ++i) {
        int power = 0; // count the power
        while (N%p[i] == 0) { N /= p[i]; ++power; }
        ans *= power+1; // follow the formula
    }
    return (N != 1) ? 2*ans : ans; // last factor = N^1
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    for (int i = 2; i < MAXN; ++i) {
        if (!primes[i]) {
            p.push_back(i);
        }
    }


    for (int i = 2; i <= MAX_N; ++i)
        if (numDiffPFarr[i] == 0) // i is a prime number
            for (int j = i; j <= MAX_N; j += i)
                ++numDiffPFarr[j]; // j is a multiple of i


    // memoize ans since Q > q.
    int Q, q;
    cin >> Q;
    memset(ans, -1, sizeof(ans));
    while (Q--) {
        cin >> q;
        if (ans[q] == -1) {
            ans[q] = numDiv(q) - numDiffPFarr[q];
        }
        cout << ans[q] << '\n';

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}