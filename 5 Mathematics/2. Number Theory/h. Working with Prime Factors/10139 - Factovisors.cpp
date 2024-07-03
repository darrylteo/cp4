#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int vp(int p, int n) {                           // Legendre's formula
    ll ans = 0;
    for (ll pi = p; pi <= n; pi *= p)
        ans += n / pi;                                 // floor by default
    return ans;
}

// uva stored separately from kattis as it requires ll instead of int, and m==0 does not return "does not divide"

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        bool possible;
        if (m <= n) possible = true;            // always true
        else {                                       // factorize m
            unordered_map<int, int> factor_m;          // in any order
            int temp = m;
            int PF = 2;
            while ((temp > 1) && ((long long) PF * PF <= m)) {
                int freq = 0;
                while (temp % PF == 0) {                   // take out this factor
                    ++freq;
                    temp /= PF;
                }
                if (freq > 0) factor_m[PF] = freq;
                ++PF;                                    // next factor
            }
            if (temp > 1) factor_m[temp] = 1;

            possible = true;
            for (auto &[p, e]: factor_m)              // for each p^e in m
                if (vp(p, n) < e) {                      // has support in n!?
                    possible = false;                      // ups, not enough
                    break;
                }
        }

        printf("%d %s %d!\n", m, possible ? "divides" : "does not divide", n);
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
