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

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vll p1(200001);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p1[x] = 1;
    }
    int m;
    cin >> m;
    vll holes(200001);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        holes[x] = 1;
    }
    ll ans = 0;
    // check initial 1 shot
    for (int i = 0; i < 200001; i++) {
        if (p1[i] && holes[i]) {
            ans++;
            holes[i] = 0;
        }
    }
    // convolute and check for 2 shot
    vll p2 = multiply(p1, p1);
    for (int i = 0; i < 200001; i++) {
        if (p2[i] && holes[i]) {
            ans++;
            holes[i] = 0;
        }
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
