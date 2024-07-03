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

// to get area A of parallelogram, it is area of rectangle, minus the 4 triangles touching corners.
// from first example. it is 8 - 2(3*1) - 2(1*1) = 4
// or in algebraic terms, it is (a+b)(c+d) - ac - bd = ad + bc = A. length was split into a and b, width into c and d.
// ad + bc = A is same as our previous questions of convolution
// cnt of ad and bc to be found using modified sieve page 288 BUT remove the prime part and change 2 to 1

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int MAX_N = 500000;
    vll numDiffPFarr(MAX_N + 1, 0);
    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = i; j <= MAX_N; j += i) {
            ++numDiffPFarr[j]; // j is a multiple of i
        }
    }

    vll res = multiply(numDiffPFarr, numDiffPFarr); // convolution of ad and bc, so have freqs of A here

    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        ll a = -1, w = -1;
        for (int i = l; i <= r; ++i) {
            if (res[i] > w) {
                a = i;
                w = res[i];
            }
        }
        cout << a << " " << w << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
