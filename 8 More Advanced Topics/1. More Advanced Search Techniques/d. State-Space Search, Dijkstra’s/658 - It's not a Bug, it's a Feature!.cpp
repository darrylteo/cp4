#include <bits/stdc++.h>

using namespace std;

int dist[(1 << 20) + 5];

// TLE for reading string with + and -
// try bitset everything

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, cases = 1;
    while (cin >> n >> m, n) {
        vector<tuple<int, int, int, int, int>> patches(m); // dist, before+, before-, after+, after-
        for (int i = 0; i < m; i++) {
            int x;
            string a, b;
            cin >> x >> a >> b;
            int beforeHave = 0, beforeNotHave = 0, afterHave = 0, afterNotHave = 0;
            for (int j = 0; j < n; j++) {
                if (a[j] == '+') beforeHave |= (1 << j);
                if (a[j] == '-') beforeNotHave |= (1 << j);
                if (b[j] == '+') afterHave |= (1 << j);
                if (b[j] == '-') afterNotHave |= (1 << j);
            }
            patches[i] = {x, beforeHave, beforeNotHave, afterHave, afterNotHave};
        }
        for (int i = 0; i < (1 << n); i++) dist[i] = 1e9;
        dist[(1 << n) - 1] = 0; // all bugs are present
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, (1 << n) - 1); // dist, mask (all bugs are present)
        while (!pq.empty()) {
            auto [d, mask] = pq.top();
            pq.pop();
            if (dist[mask] < d) continue;
            for (auto [x, a, b, c, d] : patches) {
                if ((mask & a) == a && (mask & b) == 0) { // can apply this patch (have all bugs in a and none in b)
                    int newMask = mask;
                    newMask |= c; // add bugs in c
                    newMask &= ~d; // remove bugs in d
                    if (dist[newMask] > dist[mask] + x) { // found a better way
                        dist[newMask] = dist[mask] + x;
                        pq.emplace(dist[newMask], newMask);
                    }
                }
            }
        }
        cout << "Product " << cases++ << endl;
        if (dist[0] == 1e9) {
            cout << "Bugs cannot be fixed.\n\n";
        } else {
            cout << "Fastest sequence takes " << dist[0] << " seconds.\n\n";
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs\n";
    return 0;
}

