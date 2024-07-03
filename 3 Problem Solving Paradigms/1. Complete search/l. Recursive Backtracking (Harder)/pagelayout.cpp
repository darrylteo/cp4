#include <bits/stdc++.h>

using namespace std;

// not too hard... wonder why kattis 5.3.
// just the standard add - recurse - remove backtracking method owo

struct ad {
    int w, h, x, y;
};

vector<ad> ads;
vector<int> used;
int n, totalArea, area;

bool isValidOne(int i, int j) {
    ad ad1 = ads[i], ad2 = ads[j];
    if (ad1.x < ad2.x) {
        if (ad1.x + ad1.w <= ad2.x) return true;
    } else {
        if (ad2.x + ad2.w <= ad1.x) return true;
    }
    if (ad1.y < ad2.y) {
        if (ad1.y + ad1.h <= ad2.y) return true;
    } else {
        if (ad2.y + ad2.h <= ad1.y) return true;
    }
    return false;
}

// check (the new) ads[idx] with all used ads
bool isValidAll(int idx) {
    for (int j = 0; j < n; ++j) {
        if (idx == j || !used[j]) continue;
        if (!isValidOne(idx, j)) return false;
    }
    return true;
}

void dfs(int idx) {
    totalArea = max(totalArea, area);
    if (idx == n) return;
    for (int i = idx; i < n; ++i) {
        if (used[i]) continue;
        used[i] = 1;
        area += ads[i].w * ads[i].h;
        if (isValidAll(i)) dfs(i + 1);
        used[i] = 0;
        area -= ads[i].w * ads[i].h;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n, n) {
        totalArea = 0;
        ads.clear();
        ads.resize(n);
        used.clear();
        used.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> ads[i].w >> ads[i].h >> ads[i].x >> ads[i].y;
        }
        dfs(0);
        cout << totalArea << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

