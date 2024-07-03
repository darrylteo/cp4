#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef complex<double> cd;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

const double PI = acos(-1.0);

// from https://cp-algorithms.com/algebra/fft.html
void fft(vector<cd> &a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        ld ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd &x: a) x /= n;
    }
}

// from book
vll multiply(vll p1, vll p2) {
    int n = 1;
    while (n < (int) p1.size() + (int) p2.size() - 1) n <<= 1;
    vector<cd> A(p1.begin(), p1.end());
    vector<cd> B(p2.begin(), p2.end());
    A.resize(n, 0);
    B.resize(n, 0);

    fft(A, false);
    fft(B, false);

    vector<cd> C(n, 0);
    for (int i = 0; i < n; i++) C[i] = A[i] * B[i];
    fft(C, true);

    vector<ll> ans(n, 0);
    for (int i = 0; i < n; i++) ans[i] = round(C[i].real());
    ans.resize(p1.size() + p2.size() - 1);

    return ans;
}

// all pairs for n=3.
// (1,1), (1,2), (2,1), (2,2). only bad pair is (2,1) since b>=a.
// sort of (ans - bad) / 2 + bad

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vll f(n, 0);
    for (ll i = 1; i < n; i++) {
        f[(i * i) % n]++; // collect all a^2 mod n (also can be used for b^2 mod n)
    }
    vll res = multiply(f, f);
    // we will mod n to res here, rather than in the multiply function
    for (int i = n; i < 2 * n; ++i) res[i - n] += res[i];
    res.resize(n); // contain freqs for c^2 mod n
    for (ll i = 1; i < n; i++) {
        res[(2 * i * i) % n]--;
    }
    // count for (ans - bad) / 2
    ll all = 0;
    for (ll i = 1; i < n; i++) { // try for each value of c
        all += res[(i * i) % n];
    }
    all /= 2;
    // count for + bad
    res.assign(n, 0);
    for (ll i = 1; i < n; i++) {
        res[(2 * i * i) % n]++;
    }
    for (ll i = 1; i < n; i++) { // try for each value of c
        all += res[(i * i) % n];
    }

    cout << all << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
