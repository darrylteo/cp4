#include <bits/stdc++.h>

using namespace std;

#define MAXN 432

typedef vector<int> vi;
typedef unsigned long long ull;
typedef vector<ull> vull;

bitset<MAXN> primes;
vi primesVec;

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

// nCk = n! / (k! * (n-k)!)

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    for (int i = 2; i < MAXN; ++i) {
        if (!primes[i]) primesVec.push_back(i);
    }

    vector<map<int, int>> factorsAll(MAXN);
    for (int N = 2; N < MAXN; ++N) {
        for (int i = 2; i <= N; ++i) {
            int tmp = i;
            for (int j: primesVec) {
                while (tmp % j == 0) {
                    tmp /= j;
                    factorsAll[N][j]++;
                }
                if (j * j > tmp) break;
            }
            if (tmp > 1) factorsAll[N][tmp]++;
        }
    }

    int n, k;
    while (cin >> n >> k) {
        ull ans = 1;
        for (auto &p: factorsAll[n]) {
            int power = p.second - factorsAll[k][p.first] - factorsAll[n-k][p.first];
            ans *= power + 1;
        }
        cout << ans << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}