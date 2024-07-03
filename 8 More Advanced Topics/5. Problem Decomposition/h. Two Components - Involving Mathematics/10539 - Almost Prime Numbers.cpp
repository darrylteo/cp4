#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1000000;
int prime[MAXN + 5];
vector<ll> p;

void sieve() {
    for (int i = 0; i <= MAXN; i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i] == 1) {
            for (int j = i + i; j <= MAXN; j += i) {
                prime[j] = 0;
            }
        }
    }
}

// the almost prime numbers just prime numbers to the power of {2, 3, 4, 5, 6, etc.}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    for (int i = 2; i <= MAXN; i++) {
        if (prime[i]) p.push_back(i);
    }
    vector<ll> almost_prime;
    for (int i = 0; i < p.size(); i++) {
        ll x = p[i] * p[i];
        double checker = (double) p[i] * p[i]; // to avoid overflow
        while (checker <= 1e12) {
            almost_prime.push_back(x);
            x *= p[i];
            checker *= p[i];
        }
    }
    sort(almost_prime.begin(), almost_prime.end());

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        int lb = lower_bound(almost_prime.begin(), almost_prime.end(), n) - almost_prime.begin();
        cin >> n;
        int ub = upper_bound(almost_prime.begin(), almost_prime.end(), n) - almost_prime.begin();
        cout << ub - lb << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
