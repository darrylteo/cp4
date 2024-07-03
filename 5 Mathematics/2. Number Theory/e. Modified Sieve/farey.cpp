#include <bits/stdc++.h>

using namespace std;

// euler's totient function counts how many relatively primes u can put as numerator for j

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const int MAX_N = 10005;
    int EulerPhi[MAX_N+10];
    for (int i = 1; i <= MAX_N; ++i) EulerPhi[i] = i;
    for (int i = 2; i <= MAX_N; ++i)
        if (EulerPhi[i] == i) // i is a prime number
            for (int j = i; j <= MAX_N; j += i)
                EulerPhi[j] = (EulerPhi[j]/i) * (i-1);

    int EulerPhiCum[MAX_N+10];
    EulerPhiCum[0] = 0;
    for (int i = 1; i <= MAX_N; ++i) EulerPhiCum[i] = EulerPhiCum[i-1] + EulerPhi[i];

    int T;
    cin >> T;
    while (T--) {
        int t, n;
        cin >> t >> n;
        cout << t << " " << EulerPhiCum[n] + 1 << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}