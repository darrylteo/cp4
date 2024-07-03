#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;
const double PI = acos(-1.0);

void FFT(vector<cd> &A) {
    int n = A.size();
    if (n == 1) return;
    vector<cd> A0(n / 2), A1(n / 2); // divide
    for (int k = 0; 2 * k < n; ++k) {
        A0[k] = A[2 * k];
        A1[k] = A[2 * k + 1];
    }
    FFT(A0); // conquer
    FFT(A1);
    for (int k = 0; 2 * k < n; ++k) { // combine
        cd x = cd(cos(2 * PI * k / n), sin(2 * PI * k / n));
        A[k] = A0[k] + x * A1[k];
        A[k + n / 2] = A0[k] - x * A1[k];
    }
}

void IFFT(vector<cd> &A) {
    for (auto &p: A) p = conj(p); // complex conjugate
// a + bi -> a - bi
    FFT(A);
    for (auto &p: A) p = conj(p); // complex conjugate
// **not needed for our purpose**
    for (auto &p: A) p /= A.size(); // scale down (1/n)
}

vll multiply(vi p1, vi p2) {
    int n = 1; // n needs to be a power of 2
    while (n < p1.size() + p2.size() - 1) n <<= 1;
    vector<cd> A(p1.begin(), p1.end()); // prepare A and B for FFT calls
    vector<cd> B(p2.begin(), p2.end());
    A.resize(n);
    B.resize(n);
    FFT(A); // transform
    FFT(B);
    vector<cd> C(n); // perform the multiplication
    for (int k = 0; k < n; ++k) C[k] = A[k] * B[k];
    IFFT(C); // inverse transform
    vll res; // prepare output
    for (auto &p: C) res.push_back(round(p.real()));
    res.resize(p1.size() + p2.size() - 1); // resize to original degree
    return res;
}

// a few extra cases to consider since we remove the zeroes:
// 1. x + y = z, where y = -x and z = 0. 0 was removed from v. so here add back res[100000] choice for x+y, numZeroes for z. i.e. res[100000] * numZeroes.
// 2. 0 + 0 = 0. add back numZeroes choice for first 0, numZeroes-1 for second 0, numZeroes-2 for third 0. i.e. numZeroes * (numZeroes-1) * (numZeroes-2).
// 3. x + y = z, where y = 0, z = x. p1[x] choices for x, numZeroes for y, p1[x] - 1 for z. i.e. p1[x] * numZeroes * (p1[x] - 1).
// 4. x + y = z, where x = 0, z = y. numZeroes for x, p1[y] choices for y, p1[y] - 1 for z. i.e. numZeroes * p1[y] * (p1[y] - 1).

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vi p1(100005), p2(100005);
    int n;
    cin >> n;
    vi v;
    ll numZeroes = 0; // ll here since we have ~n^3
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            numZeroes++;
            continue;
        }
        v.push_back(x);
        p1[50000 + x]++;
    }
    p2 = p1;
    vll res = multiply(p1, p2);
    for (int i: v) res[2 * (50000 + i)]--; // must be pairwise diff

    ll ans = 0;
    for (int i: v) ans += res[i + 100000]; // x + y = i
    ans += res[100000] * numZeroes; // x + y = 0
    ans += numZeroes * (numZeroes - 1) * (numZeroes - 2); // 0 + 0 = 0
    for (int i = 0; i < 100005; i++) {
        ans += p1[i] * numZeroes * (p1[i] - 1); // x + 0 = i
        ans += numZeroes * p1[i] * (p1[i] - 1); // 0 + x = i
    }
    cout << ans << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
