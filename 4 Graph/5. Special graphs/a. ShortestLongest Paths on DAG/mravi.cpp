#include <bits/stdc++.h>

using namespace std;

// for each leaf, dfs back to root
// if superpipe, new val = sqrt(val)/weight

struct pipes {
    int parent;
    double weight;
    bool superpipe;
};

// likely to get WA if don't used fixed precision

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pipes> AL(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int p, u, w, s; // parent, current, weight, superpipe
        cin >> p >> u >> w >> s;
        AL[u].parent = p;
        AL[u].weight = (double) w / 100;
        AL[u].superpipe = s;
    }
    double maxReq = 0;
    for (int i = 1; i <= n; i++) {
        double req;
        cin >> req;
        if (req == -1) continue;
        // dfs to root
        int u = i;
        while (u != 1) {
            if (AL[u].superpipe) {
                req = sqrt(req);
            }
            req /= AL[u].weight;
            u = AL[u].parent;
        }
        maxReq = max(maxReq, req);
    }
    cout << fixed << setprecision(5) << maxReq << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}