#include <bits/stdc++.h>

using namespace std;

int N, F;
vector<int> r; // r: radius, A: (base) area

bool ok(double V) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += (int) (M_PI * r[i] * r[i] / V);
        if (cnt >= F + 1) return true;
    }
    return false;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> F;
        r.resize(N);
        for (int i = 0; i < N; i++) cin >> r[i];
        double lo = 0, hi = 1e9;
        while (abs(hi - lo) > 1e-6) {
            double mid = (lo + hi) / 2;
            if (ok(mid)) lo = mid;
            else hi = mid;
        }
        cout << fixed << setprecision(4) << lo << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}