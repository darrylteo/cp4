#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000010

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

// get overall pow for each prime factor, then multiply the (pow+1)s

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

    int T;
    cin >> T;
    for (int cases = 1; cases <= T; ++cases) {
        string s;
        cin >> s;
        int cnt = 0;
        while (s.back() == '!') {
            s.pop_back();
            ++cnt;
        }
        int n = stoi(s);
        vector<int> nums;
        for (int i = n; i > 0; i -= cnt) {
            nums.push_back(i);
        }

        // let's get powers 1st
        map<int, int> mp;
        for (int N: nums) {
            for (int i = 0; (i < (int) primesVec.size()) && (primesVec[i] * primesVec[i] <= N); ++i) {
                int power = 0; // count the power
                while (N % primesVec[i] == 0) {
                    N /= primesVec[i];
                    ++power;
                }
                if (power) {
                    mp[primesVec[i]] += power;
                }
            }
            if (N > 1) {
                mp[N] += 1;
            }
        }

        ull ans = 1, infReached = 0;
        for (auto &p: mp) {
            ans *= (p.second + 1);
            if (ans > (ull) 1e18) {
                infReached = 1;
                break;
            }
        }

        cout << "Case " << cases << ": ";
        if (infReached) {
            cout << "Infinity\n";
        } else {
            cout << ans << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}