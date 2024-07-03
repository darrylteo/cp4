#include <bits/stdc++.h>

using namespace std;

#define MAXN 32005

typedef vector<int> vi;

int primes[MAXN];

// sieve of eratosthenes. primes[i] = 0 if i is prime so i don't need to memset
void sieve() {
    primes[0] = primes[1] = 1;
    for (int i = 2; i * i < MAXN; i++) {
        if (primes[i] == 0) {
            for (int j = i * i; j < MAXN; j += i) {
                primes[j] = 1;
            }
        }
    }
}

void print(vi &v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << " ";
    }
    cout << '\n';
}

// easy on the surface but a little tricky to debug... see the 2 comments
// probably is due to the way i model the qn. if i stored a vector of all sequences i could just search from there...

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    sieve();
    int a, b;
    vi vPrimes;
    for (int i = 0; i < MAXN; i++) {
        if (primes[i] == 0) {
            vPrimes.push_back(i);
        }
    }
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        if (a > b) swap(a, b);
        for (int i = 0; i < vPrimes.size() - 2; i++) {
            if (vPrimes[i] > b) break;
            if (vPrimes[i] >= a - 50) { // 50 is arbitrary. e.g. seq 251 257 263 269. if a = 252, b = 270 we should NOT print 257 263 269 since it is a subsequence of a forbidden sequence 251 257 263 269
                vi ans;
                ans.push_back(vPrimes[i]);
                int diff = vPrimes[i + 1] - vPrimes[i];
                int j = i + 1;
                for (; j < vPrimes.size() - 1; j++) {
                    if (vPrimes[j] - vPrimes[j - 1] == diff) {
                        ans.push_back(vPrimes[j]);
                    } else {
                        break;
                    }
                }
                if (ans.size() >= 3) {
                    if (ans[ans.size() - 1] <= b && ans[0] >= a) print(ans); // make sure it is not a subsequence as per qn description
                    i = j - 2; // so doesn't print a subsequence of prev sequence
                }
            }
        }

    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}