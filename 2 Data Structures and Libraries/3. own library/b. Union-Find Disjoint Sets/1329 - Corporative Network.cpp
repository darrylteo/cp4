#include <bits/stdc++.h>

using namespace std;

// gonna try without ufds... end up so much easier ._.
// keyword here is the one that gets merged is the CENTER of cluster A. so can safely update all the way up to parent.
// this makes it clear it is a UFDS question

// merges links and updates dist
int solve(int x, vector<int> &parent, vector<int> &dist) {
    if (x == parent[x])	return x;
    int p = solve(parent[x], parent, dist); // all internal nodes get their parent updated to root
    dist[x] += dist[parent[x]]; // and their distance is updated to distance to root too
    return parent[x] = p; // faster than splitting into 2 lines then returning p
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> parent(N + 1), dist(N + 1);
        for (int i = 1; i <= N; ++i) {
            parent[i] = i;
        }
        char c;
        int a, b;
        while (cin >> c) {
            if (c == 'O') break;
            if (c == 'E') {
                cin >> a;
                solve(a, parent, dist);
                cout << dist[a] << '\n';
            } else {
                cin >> a >> b;
                parent[a] = b;
                dist[a] = abs(a - b) % 1000;
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
