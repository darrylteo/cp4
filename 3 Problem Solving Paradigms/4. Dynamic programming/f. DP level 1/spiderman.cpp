#include <bits/stdc++.h>

using namespace std;

int heights[45], dp[45][1005], n; // for each id, currHeight, stores the height of building required

int solve(int id, int height) {
    if (id == n) {
        if (height == 0) return 0; // reached street
        return 1e7; // didn't reach street
    }
    if (height < 0) return 1e7; // went below street
    int &ans = dp[id][height];
    if (ans != -1) return ans;
    ans = min(solve(id + 1, height + heights[id]), solve(id + 1, height - heights[id]));
    ans = max(ans, height);
    return ans;
}

void getPath(int id, int height) {
    if (id == n) return;
    if (height < 0) return;
    if (solve(id + 1, height + heights[id]) < solve(id + 1, height - heights[id])) {
        cout << "U";
        getPath(id + 1, height + heights[id]);
    } else {
        cout << "D";
        getPath(id + 1, height - heights[id]);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    cin >> N;
    while (N--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> heights[i];
        memset(dp, -1, sizeof dp);
        if(solve(0, 0) < 1e7) { // solve i, j means we are at ith idx and currHeight is j. so we start from 0 idx, 0 height (street)
            getPath(0, 0);
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


