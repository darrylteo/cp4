#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

const int dr4[] = {0, 1, 0, -1};
const int dc4[] = {1, 0, -1, 0};
int graph[1005][1005], visited[1005][1005], best[1005][1005], r, c;

// very similar to previous qn millionairemadness

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
            if (j == 0) {
                best[i][j] = graph[i][j];
            }
        }
    }


    priority_queue<iii, vector<iii>, greater<iii>> pq; // (weight, x, y). weight only for sorting
    for (int i = 0; i < r; i++) pq.emplace(best[i][0], i, 0); // start from any in left col
    while (!pq.empty()) {
        iii front = pq.top();
        pq.pop();
        int xCurr = get<1>(front), yCurr = get<2>(front);
        if (visited[xCurr][yCurr]) continue;
        visited[xCurr][yCurr] = 1;
        for (int i = 0; i < 4; i++) {
            int xNext = xCurr + dr4[i], yNext = yCurr + dc4[i];
            if (xNext < 0 || xNext >= r || yNext < 0 || yNext >= c) continue;
            int climbCost = max(graph[xNext][yNext], best[xCurr][yCurr]); // cost to come this cell
            if (climbCost < best[xNext][yNext]) {
                best[xNext][yNext] = climbCost;
                pq.emplace(climbCost, xNext, yNext);
            }
        }
    }
    int bestOverall = INT_MAX;
    for (int i = 0; i < r; i++) {
        bestOverall = min(bestOverall, best[i][c - 1]);
    }
    cout << bestOverall << endl;




    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


