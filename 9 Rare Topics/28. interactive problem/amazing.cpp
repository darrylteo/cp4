#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int dirr[] = {0, 1, 0, -1};
const int dirc[] = {1, 0, -1, 0};
const string dir[] = {"up", "right", "down", "left"};

set<pii> vis;

void dfs(pii cur, pii prev) {
    vis.insert(cur);
    string res;

    int prev_dir = -1;
    for (int k = 0; k < 4; k++) {
        pii next = {cur.first + dirr[k], cur.second + dirc[k]};
        if (vis.find(next) == vis.end()) {
            cout << dir[k] << endl << flush;
            cin >> res;
            if (res == "solved") exit(0);
            if (res == "wall") continue;
            if (res == "ok") dfs(next, cur);
        } else if (next == prev) {
            prev_dir = k;
        }
    }

    if (cur != make_pair(0, 0)) { // it's okay to go back after trying all new directions
        cout << dir[prev_dir] << endl << flush;
        cin >> res;
    } else {
        cout << "no way out" << endl << flush;
        exit(0);
    }
}

// ref: https://github.com/BrandonTang89/Competitive_Programming_4_Solutions/blob/main/Chapter_9_Rare_Topics/9.31_Interactive_Problem/kattis_amazing.cpp

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dfs({0, 0}, {0, 0});

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
