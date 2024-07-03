#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi match, vis; // global variables
vector<vi> AL, dist;
vii humans, aliens;
int H, A; // humans aliens

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

// as + ar * t <= hs + hr * (t - dist) to win.
// t >= (as - hs + hr * dist) / (hr - ar)
bool canMatch(int i, int j, int year) {
    if (dist[i][j] > year) return false; // time that he reached alien > year?
    int as = aliens[j].first, ar = aliens[j].second; // start, rate
    int hs = humans[i].first, hr = humans[i].second; // start, rate
    if (hr <= ar) return hs >= as + dist[i][j] * ar; // best to leave at time 0 since aliens grow faster
    else {
        double t = (double) (as - hs + hr * dist[i][j]) / (hr - ar);
        return t <= year;
    }
}

bool ok(int year) { // year REACHED... -_- comprehension issue. i used year of human take off earlier
    AL.assign(H, vi());
    // augmented thingy uses directed graph from left to right
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < A; ++j) {
            if (canMatch(i, j, year)) AL[i].push_back(j);
        }
    }
    match.assign(H + A, -1);
    int MCBM = 0;
    for (int L = 0; L < H; ++L) { // for each free vertices
        vis.assign(H, 0); // reset first
        MCBM += Aug(L); // try to match L
    }
    return MCBM == A;
}

// kinda challenging to understand the problem statement

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> H >> A, H) {
        humans.resize(H);
        aliens.resize(A);
        for (int i = 0; i < H; ++i) cin >> humans[i].first >> humans[i].second;
        for (int i = 0; i < A; ++i) cin >> aliens[i].first >> aliens[i].second;
        dist.assign(H, vi(A));
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < A; ++j) {
                cin >> dist[i][j];
            }
        }
        int lo = 0, hi = 1e6, mid;
        if (H < A || !ok(hi)) {
            cout << "IMPOSSIBLE\n";
        } else {
            while (lo < hi) {
                mid = (lo + hi) / 2;
                if (ok(mid)) hi = mid;
                else lo = mid + 1;
            }
            cout << lo << endl;
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}