// Collecting Beepers

#include <bits/stdc++.h>

using namespace std;

#define LSOne(S) ((S) & -(S))

const int MAX_n = 10;

double dist[MAX_n][MAX_n], memo[MAX_n][1 << (MAX_n - 1)]; // Karel + max 10 beepers

double dp(int u, int mask) {                        // mask = free coordinates
    if (mask == 0) return 0;              // close the loop
    double &ans = memo[u][mask];
    if (ans != -1) return ans;                     // computed before
    ans = 2000000000;
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v);          // offset v by +1. // ctz = count trailing zeros
        ans = min(ans, dist[u][v] + dp(v, mask ^ two_pow_v)); // keep the min
        m -= two_pow_v;
    }
    return ans;
}

vector<int> path;
void getPath(int u, int mask) {                    // backtracking routine
    if (mask == 0) return;                         // close the loop
    double opt = dp(u, mask);
    int m = mask;
    while (m) {                                    // up to O(n)
        int two_pow_v = LSOne(m);                    // but this is fast
        int v = __builtin_ctz(two_pow_v);          // offset v by +1. // ctz = count trailing zeros
        if (fabs(opt - (dist[u][v] + dp(v, mask ^ two_pow_v))) < 1e-9) { // if same, same state
            path.push_back(v);
            getPath(v, mask ^ two_pow_v); // recurse on this state
            return;
        }
        m -= two_pow_v;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, cases = 1;
    while (cin >> n, n) {
        int x[MAX_n], y[MAX_n];
        for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
        for (int i = 0; i < n; ++i)                  // build distance table
            for (int j = i; j < n; ++j)
                dist[i][j] = dist[j][i] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) + 16.00;
        for (int i = 0; i < n; ++i)                  // initialize memo
            for (int j = 0; j < (1 << n); ++j)
                memo[i][j] = -1;
	// if don't go back 1 circle, the first city matters. e.g. (1,1), (5,5), (10,10). can see if start with (5,5) it's gonna take longer
	// might be better to add dummy first node with 0 dist to all nodes.
        double best = INT_MAX;
        int bestIdx = 0;
        for (int i = 0; i < n; ++i) {
            double shortestHere = dp(i, (1 << n) - 1 - (1 << i));
            if (shortestHere < best) {
                best = shortestHere;
                bestIdx = i;
            }
        }

        path.clear();
        getPath(bestIdx, (1 << n) - 1 - (1 << bestIdx));
        cout << "**********************************************************\n";
        cout << "Network #" << cases++ << "\n";
        cout << "Cable requirement to connect (" << x[bestIdx] << "," << y[bestIdx] << ") to (" << x[path[0]] << ","
             << y[path[0]] << ") is " << fixed << setprecision(2) << dist[bestIdx][path[0]] << " feet.\n";
        for (int i = 0; i < path.size() - 1; ++i) {
            cout << "Cable requirement to connect (" << x[path[i]] << "," << y[path[i]] << ") to ("
                 << x[path[i + 1]] << "," << y[path[i + 1]] << ") is " << fixed << setprecision(2)
                 << dist[path[i]][path[i + 1]] << " feet.\n";
        }
        cout << "Number of feet of cable required is " << fixed << setprecision(2) << dp(bestIdx, (1 << n) - 1 - (1 << bestIdx))
             << ".\n";


    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}