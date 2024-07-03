#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int C, S;

ll mod(ll a, ll m) {                           // returns a (mod m)
    return ((a % m) + m) % m;                        // ensure positive answer
}

ll extEuclid(ll a, ll b, ll &x, ll &y) {    // pass x and y by ref
    ll xx = y = 0;
    ll yy = x = 1;
    while (b) {                                    // repeats until b == 0
        ll q = a / b;
        ll tmp = b;
        b = a % b;
        a = tmp;
        tmp = xx;
        xx = x - q * xx;
        x = tmp;
        tmp = yy;
        yy = y - q * yy;
        y = tmp;
        // DON'T USE TIE FOR UVA!!!!!!!!!
//        tie(a, b) = tuple(b, a % b);
//        tie(x, xx) = tuple(xx, x - q * xx);
//        tie(y, yy) = tuple(yy, y - q * yy);
    }
    return a;                                      // returns gcd(a, b)
}

ll modInverse(ll b, ll m) {                   // returns b^(-1) (mod m)
    ll x, y;
    ll d = extEuclid(b, m, x, y);                 // to get b*x + m*y == d
    if (d != 1) return -1;                         // to indicate failure
    // b*x + m*y == 1, now apply (mod m) to get b*x == 1 (mod m)
    return mod(x, m);
}

ll crt(vll r, vll m) {
    // m_t = m_0*m_1*...*m_{n-1}
    ll mt = 1;
    for (long long i: m) mt *= i;
    ll x = 0;
    for (int i = 0; i < (int) m.size(); ++i) {
        ll a = mod(r[i] * modInverse(mt / m[i], m[i]), m[i]);
        x = mod(x + a * (mt / m[i]), mt);
    }
    return x;
}

// test quotient * ratio + remainder values only instead of all values. from https://github.com/morris821028/UVa/blob/master/volume117/11754%20-%20Code%20Feat.cpp
// about 10x faster than naive complete function
void complete2(const vector<vll> &rr, const vll &m) {
    int base = 0;
    for (int i = 0; i < C; i++) {
        if (m[base] * rr[i].size() < m[i] * rr[base].size()) base = i;
    }
    for (int i = 0, ratio = 0; i < S; ratio++) {
        for (int j = 0; j < rr[base].size() && i < S; j++) {
            long long mn = (long long) ratio * m[base] + rr[base][j];
            if (mn == 0) continue;
            int f = 1;
            for (int k = 0; k < C; k++)
                f &= find(rr[k].begin(), rr[k].end(), mn % m[k]) != rr[k].end();
            if (f) {
                cout << mn << '\n';
                i++;
            }
        }
    }
}

bool ok(const vector<vll>& rr, const vll& m, ll x) { // is x ok for any combination within r?
    for (int i = 0; i < C; ++i) {
        ll val = x % m[i];
        if (find(rr[i].begin(), rr[i].end(), val) == rr[i].end()) return false;
    }
    return true;
}

void complete(const vector<vll> &rr, const vll &m) {
    // try all integers until S prints
    int cnt = 0;
    ll x = 1;
    while (cnt < S) {
        if (ok(rr, m, x)) {
            cout << x << '\n';
            ++cnt;
        }
        ++x;
    }
}

vll ans;
vll r;

void dfs(const vector<vll> &rr, const vll &m, int i) {
    if (i == C) {
        ans.push_back(crt(r, m));
        return;
    }
    for (ll j : rr[i]) {
        r[i] = j;
        dfs(rr, m, i + 1);
    }
}

void crtt(const vector<vll> &rr, const vll &m) {
    ans.clear();
    r.resize(C);
    dfs(rr, m, 0);
    sort(ans.begin(), ans.end());
    // this part got me WA many times.
    // you need to print more values than just the crt ans, by adding multiples of M if not >= S yet
    // see my test case on udebug
    ll M = 1;
    for (ll i : m) M *= i;
    for(int i = 0, ratio = 0; i < S; ratio++) {
        for (int j = 0; j < ans.size() && i < S; j++) {
            long long mn = ans[j] + ratio * M;
            if (mn == 0) continue;
            cout << mn << '\n';
            i++;
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (cin >> C >> S, C) {
        vll m(C);
        vector<vll> rr(C);
        for (int i = 0; i < C; ++i) {
            int x;
            cin >> x;
            m[i] = x;
            cin >> x;
            while (x--) {
                int y;
                cin >> y;
                rr[i].push_back(y);
            }
            sort(rr[i].begin(), rr[i].end());
            rr[i].erase(unique(rr[i].begin(), rr[i].end()), rr[i].end());
        }
        int cnt = 1, bad = 0;
        for (int i = 0; i < C; ++i) {
            cnt *= rr[i].size();
            if (cnt >= 10000) {
                bad = 1;
                break;
            }
        }
        if (bad) complete2(rr, m);
        else crtt(rr, m);

        cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

