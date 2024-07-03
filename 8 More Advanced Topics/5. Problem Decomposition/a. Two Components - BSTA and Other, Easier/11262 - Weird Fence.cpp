#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi match, vis; // global variables
vector<vi> AL;
vii blue, red;
int P, k;

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
    for (int i = 0; i < P; ++i) AL[i].clear();
    // augmented thingy uses directed graph from left to right
    for (int i = 0; i < blue.size(); ++i) {
        for (int j = 0; j < red.size(); ++j){
            int x1 = blue[i].first, y1 = blue[i].second;
            int x2 = red[j].first, y2 = red[j].second;
            if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= length * length) AL[i].push_back(j + (int) blue.size());
        }
    }
    match.assign(P, -1);
    int MCBM = 0;
    for (int L = 0; L < blue.size(); ++L) { // for each free vertices
        vis.assign(blue.size(), 0); // reset first
        MCBM += Aug(L); // try to match L
    }
    return MCBM >= k;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> P >> k;
        blue.clear();
        red.clear();
        string color;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y >> color;
            if (color == "blue") blue.emplace_back(x, y);
            else red.emplace_back(x, y);
        }
        if (min(blue.size(), red.size()) < k) {
            cout << "Impossible" << endl;
            continue;
        }
        AL.assign(P, vi());
        int lo = 0, hi = 5000, mid;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (ok(mid)) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}