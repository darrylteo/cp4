#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef complex<ld> cd;
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

// weird qn. everything need super high precision

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vll f(60001);
    int minn = 1e7, maxx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x]++;
        minn = min(minn, x);
        maxx = max(maxx, x);
    }
    vll res = multiply(f, f);
    res = multiply(res, f);
    res = multiply(res, f);
    ll cnt = 0;
    ld total = 0, totalCnt = 0; // either bigint or ld
    for (int i = 0; i < res.size(); i++) {
        if (res[i] > 0) {
            cnt++;
            total += res[i] * i;
            totalCnt += res[i];
        }
    }
    cout << maxx * 4 << " " << minn * 4 << " " << cnt << " " << fixed << setprecision(8)
         << total / totalCnt << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
