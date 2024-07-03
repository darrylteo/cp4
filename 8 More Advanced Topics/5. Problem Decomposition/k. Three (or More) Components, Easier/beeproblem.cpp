#include <bits/stdc++.h>

using namespace std;

vector<string> grid;
int R, C, h;
const int dirr[] = {1, 1, 0, -1, -1, 0};
const int dirc[] = {-1, 1, 2, 1, -1, -2};

int flood(int r, int c) {
    grid[r][c] = '#'; // mark completed
    int ans = 1;
    for (int i = 0; i < 6; i++) {
        int nr = r + dirr[i], nc = c + dirc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == '#') continue;
        ans += flood(r + dirr[i], c + dirc[i]);
    }
    return ans;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> R >> C >> ws;
    C = C * 2;
    grid.resize(R);
    for (int i = 0; i < R; i++) {
        getline(cin, grid[i]);
        if (i%2 == 0) grid[i] += ' ';
    }
    vector<int> floods;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == '.') {
                floods.push_back(flood(i, j));
            }
        }
    }
    sort(floods.rbegin(), floods.rend());
    int cnt = 0;
    while (h > 0) {
        h -= floods[cnt++];
    }
    cout << cnt << endl;


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

