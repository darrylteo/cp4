#include <bits/stdc++.h>

using namespace std;

#define abs_val(a)       (((a)>0)?(a):-(a))
typedef long long ll;

ll mulMod(ll a, ll b, ll c) {
    ll x = 0, y = a % c;
    while (b > 0) {
        if (b & 1) x += y;
        if (x >= c) x %= c;
        y <<= 1;
        if (y >= c) y %= c;
        b >>= 1;
    }
    return x % c;
}

ll gcd(ll a, ll b) {
    return !b ? a : gcd(b, a % b);
}

ll Mod(ll a, ll b, ll p) {
    ll res = 1;
    ll x = a % p;

    while (b) {
        if (b & 1) res = mulMod(res, x, p);
        x = mulMod(x, x, p);
        b >>= 1;
    }
    return res % p;
}

bool millerTest(ll d, ll s, ll n) {
    ll a = rand() % (n - 4) + 2;
    ll x = Mod(a, s, n);

    if (x == 1 || x == n - 1) return true;

    for (int r = 1; r < d; r++) {
        x = mulMod(x, x, n);
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(ll n, int k = 20) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    ll s = n - 1, d = 0;
    while (s % 2 == 0) {
        s >>= 1;
        d++;
    }
    for (int i = 0; i < k; i++) {
        if (!millerTest(d, s, n)) return false;
    }
    return true;
}

map<ll, ll> MAP;

ll pollard_rho(ll n)  //pollard rho implementation
{
    if (n % 2 == 0) return 2;

    ll x = rand() % n + 1;
    ll c = rand() % n + 1;
    ll y = x;
    ll g = 1;

    //fn is f(x) = x*x + c
    while (g == 1) {
        x = (mulMod(x, x, n) + c) % n;
        y = (mulMod(y, y, n) + c) % n;
        y = (mulMod(y, y, n) + c) % n;
        g = gcd(abs_val(x - y), n);
    }
    return g;
}

void factorize(ll n)   //fn to factorize the number
{
    if (n == 1) return;

    if (isPrime(n))      //if n is prime,store it
    {
        MAP[n]++;
        return;
    }
    ll divisor = pollard_rho(n);   //get a divisor of n
    factorize(divisor);
    factorize(n / divisor);
}

// since book say details not important, for now, we just copy "template" code above from:
// https://rextester.com/discussion/TIJY97700/Pollard-Rho-Brent-Integer-Factorization-11476-Factorizing-Larget-Integers

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        ll n;
        cin >> n;
        cout << n << " = ";
        MAP.clear();
        factorize(n);
        auto it1 = MAP.begin();
        if (it1->second > 1) cout << it1->first << "^" << it1->second;
        else cout << it1->first;
        MAP.erase(it1);
        for (auto &itr: MAP) {
            if (itr.second > 1) cout << " * " << itr.first << "^" << itr.second;
            else cout << " * " << itr.first;
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
