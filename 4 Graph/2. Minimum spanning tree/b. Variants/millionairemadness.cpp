#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

const int dr4[] = {0, 1, 0, -1};
const int dc4[] = {1, 0, -1, 0};
int graph[1005][1005], visited[1005][1005], best[1005][1005], r, c;

// hard for kattis easy rating

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];
            best[i][j] = INT_MAX;
            visited[i][j] = 0;
        }
    }


    priority_queue<iii, vector<iii>, greater<iii>> pq; // (weight, x, y). weight only for sorting
    pq.emplace(0, 0, 0);
    best[0][0] = 0;
    while (!pq.empty()) {
        iii front = pq.top();
        pq.pop();
        int xCurr = get<1>(front), yCurr = get<2>(front);
        if (visited[xCurr][yCurr]) continue;
        visited[xCurr][yCurr] = 1;
        for (int i = 0; i < 4; i++) {
            int xNext = xCurr + dr4[i], yNext = yCurr + dc4[i];
            if (xNext < 0 || xNext >= r || yNext < 0 || yNext >= c) continue;
            int climbCost = max(0, graph[xNext][yNext] - graph[xCurr][yCurr]); // cost to make current ladder
            climbCost = max(climbCost, best[xCurr][yCurr]); // a previous ladder may be used if it was higher
            if (climbCost < best[xNext][yNext]) {
                best[xNext][yNext] = climbCost;
                pq.emplace(climbCost, xNext, yNext);
            }
        }
    }
    cout << best[r - 1][c - 1] << endl;




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


