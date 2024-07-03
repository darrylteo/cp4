#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))
#define ll long long

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_3_Problem_Solving_Paradigms/Dynamic_Programming/kattis_bustour.cpp

const int MAX_n = 21;
ll dist[MAX_n][MAX_n], memoLeft[MAX_n][1 << (MAX_n - 1)], memoRight[MAX_n][1 << (MAX_n - 1)], n;

ll dpRight(int u, int mask) {                        // mask = free coordinates
    if (mask == 0) return dist[u][n - 1];                   // go attraction
    ll &ans = memoRight[u][mask];
    if (ans != -1) return ans;                     // computed before
    ans = INT_MAX;
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v) + 1;          // offset v by +1. // ctz = count trailing zeros
        ans = min(ans, dist[u][v] + dpRight(v, mask ^ two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

ll dpLeft(int u, int mask) {                        // mask = free coordinates
    if (mask == 0) return dist[u][0];                   // go HQ
    ll &ans = memoLeft[u][mask];
    if (ans != -1) return ans;                     // computed before
    ans = INT_MAX;
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v) + 1;          // offset v by +1. // ctz = count trailing zeros
        ans = min(ans, dist[u][v] + dpLeft(v, mask ^ two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

// after some debugging i realized need left and right memo since if i == j, i.e. choose same city as the middle
// notice we call the same bitmask twice, once on left once on right. if call it on same memo it will return answer from 1st call

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m, cases = 1;
    while (cin >> n >> m) {
        cout << "Case " << cases++ << ": ";
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INT_MAX;
            }
        }
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = dist[v][u] = w;
        }
        // shortest path (simulate skip town)
        for (int k = 0; k < n; ++k) {
            for (int u = 0; u < n; ++u) {
                for (int v = 0; v < n; ++v) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
        if (n == 3) {
            cout << 2 * (dist[0][1] + dist[1][2]) << '\n';
            continue;
        }

        ll currBest = INT_MAX;
        memset(memoLeft, -1, sizeof memoLeft);
        memset(memoRight, -1, sizeof memoRight);
        for (int bm = 0; bm < (1 << (n - 2)); ++bm) {
            if (__builtin_popcount(bm) != (n - 2) / 2) continue;
            int bm_complement = ((1 << (n - 2)) - 1) ^ bm;
            for (int i = 1; i < n - 1; ++i) { // don't include HQ or attraction
                for (int j = 1; j < n - 1; ++j) {
                    if (!(bm & (1 << (i - 1))) || !(bm & (1 << (j - 1)))) continue; // i and j not in half1
                    ll a = dpRight(i, bm_complement); // i to attraction (half1)
                    ll b = dpLeft(i, bm ^ (1 << (i - 1))); // i to HQ (half2)
                    ll c = dpLeft(j, bm_complement); // j to attraction (half2)
                    ll d = dpRight(j, bm ^ (1 << (j - 1))); // j to HQ (half1)
                    ll cur = a + b + c + d;
                    currBest = min(currBest, cur);
                }
            }
        }
        cout << currBest << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}