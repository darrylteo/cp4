#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

vi match, vis; // global variables
vector<vi> AL;

int Aug(int L) {
    if (vis[L]) return 0; // L visited, return 0
    vis[L] = 1;
    for (auto &R: AL[L])
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L; // flip status
            return 1; // found 1 matching
        }
    return 0; // no matching
}

struct tower {
    int x, y, P;
};

bool ccw(tower tw1, tower tw2, tower tw3) {
    int tw1tw2x = tw2.x - tw1.x;
    int tw1tw2y = tw2.y - tw1.y;
    int tw1tw3x = tw3.x - tw1.x;
    int tw1tw3y = tw3.y - tw1.y;
    return tw1tw2x * tw1tw3y - tw1tw2y * tw1tw3x > -1e-8;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cases = 1;
    while (cin >> N, N) {
        vector<tower> towers(N);
        for (int i = 0; i < N; ++i) cin >> towers[i].x >> towers[i].y >> towers[i].P;
        int a, b, R;
        cin >> a >> b >> R;
        a--;
        b--;
        vector<tower> twLeft, twRight;
        for (int i = 0; i < N; ++i) {
            if (towers[i].P == 0) continue; // free tower no count
            if (ccw(towers[a], towers[b], towers[i])) twLeft.push_back(towers[i]);
            else twRight.push_back(towers[i]);
        }
        // let left be smaller
        if (twLeft.size() > twRight.size()) swap(twLeft, twRight);
        int V = twLeft.size() + twRight.size();
        int Vleft = twLeft.size();
        // get adj list
        AL.assign(V, vi());
        for (int i = 0; i < twLeft.size(); ++i) {
            for (int j = 0; j < twRight.size(); ++j) {
                if (hypot(twLeft[i].x - twRight[j].x, twLeft[i].y - twRight[j].y) - R < 1e-8 && twLeft[i].P > twRight[j].P) {
                    AL[i].push_back(j + Vleft);
                }
            }
        }
        // MCBM
        match.assign(V, -1);
        int MCBM = 0;
        for (int L = 0; L < Vleft; ++L) { // for each free vertices
            vis.assign(Vleft, 0); // reset first
            MCBM += Aug(L); // try to match L
        }
        cout << "Case " << cases++ << ": " << MCBM << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}