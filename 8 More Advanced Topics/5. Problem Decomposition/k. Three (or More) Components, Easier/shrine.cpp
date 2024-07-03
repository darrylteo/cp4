#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, N, D, R = 1000;
    while (cin >> W >> N >> D, W) {
        vector<bool> vis(N + 1, false);
        while (D--) {
            int x, tmp;
            cin >> x;
            tmp = x;
            while (tmp <= N) {
                vis[tmp] = true;
                tmp += x;
            }
        }
        vector<int> shrines;
        if (vis[N]) shrines.push_back(0);
        for (int i = 1; i < N; i++) {
            if (vis[i]) shrines.push_back(i);
        }
        // divide circle up into N segments. use a^2 = b^2 + c^2 - 2bc cos A
        int sz = (int) shrines.size();
        vector<double> dist(sz, 0);
        for (int i = 1; i < sz; i++) {
            int n = shrines[i] - shrines[i - 1];
            dist[i] = sqrt(2 * R * R * (1 - cos(2 * M_PI / N * n)));
        }
        dist[0] = sqrt(2 * R * R * (1 - cos(2 * M_PI / N * (shrines[0] + N - shrines[sz - 1]))));
        // for each starting point, BSTA the answer
        double best = 1e9;
        for (int u = 0; u < sz/W; ++u) { // u is the starting point
            double low = 0, high = 2 * M_PI * R;
            while (high - low > 1e-4) {
                double mid = (low + high) / 2;
                int nextIdx = (u + 1) % sz, w = 0; // workers. count the number of COMPLETED workers. if W completed, but still have shrines, break;
                double curr = 0; // current distance
                bool ok = true;
                while (nextIdx != u) {
                    curr += dist[nextIdx];
                    if (curr > mid) {
                        curr = 0;
                        w++;
                    }
                    if (w >= W) {
                        ok = false;
                        break;
                    }
                    nextIdx = (nextIdx + 1) % sz;
                }
                if (ok) {
                    best = min(best, mid);
                    high = mid;
                } else {
                    low = mid;
                }
            }
        }
        cout << fixed << setprecision(1) << best + 2000 << endl; // 2000 is dist exclude from shrine to shrine
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}