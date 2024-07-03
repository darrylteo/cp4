#include <bits/stdc++.h>

using namespace std;

typedef complex<double> cd;
typedef vector<int> vi;
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

vi multiply(vi p1, vi p2) {
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
    vi res; // prepare output
    for (auto &p: C) res.push_back(round(p.real()));
    res.resize(p1.size() + p2.size() - 1); // resize to original degree
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi p1(n + 1);
        for (int i = 0; i <= n; i++) cin >> p1[i];
        cin >> n;
        vi p2(n + 1);
        for (int i = 0; i <= n; i++) cin >> p2[i];
        vi res = multiply(p1, p2);
        cout << res.size() - 1 << endl;
        for (int i : res) cout << i << " ";
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
