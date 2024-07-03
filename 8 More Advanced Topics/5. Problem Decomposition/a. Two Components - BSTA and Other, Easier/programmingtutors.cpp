#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi match, vis; // global variables
vector<vi> AL;
vii blue, red;
int N;

int Aug(int L) {
    if (vis[L]) return 0; // L visited, return 0
    vis[L] = 1;
    for (auto &R : AL[L])
        if ((match[R] == -1) || Aug(match[R])) {
            match[R] = L; // flip status
            return 1; // found 1 matching
        }
    return 0; // no matching
}

bool ok(int length) {
    for (int i = 0; i < 2*N; ++i) AL[i].clear();
    // augmented thingy uses directed graph from left to right
    for (int i = 0; i < blue.size(); ++i) {
        for (int j = 0; j < red.size(); ++j){
            int x1 = blue[i].first, y1 = blue[i].second;
            int x2 = red[j].first, y2 = red[j].second;
            if (abs(x1 - x2) + abs(y1 - y2) <= length) AL[i].push_back(j + (int) blue.size());
        }
    }
    match.assign(2*N, -1);
    int MCBM = 0;
    for (int L = 0; L < blue.size(); ++L) { // for each free vertices
        vis.assign(blue.size(), 0); // reset first
        MCBM += Aug(L); // try to match L
    }
    return MCBM == N; // must match all
}

// repeat of uva 11262 - Weird Fence

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int x, y;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        blue.emplace_back(x, y);
    }
    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        red.emplace_back(x, y);
    }
    AL.assign(2 * N, vi());
    int lo = 0, hi = 1e9, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (ok(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}