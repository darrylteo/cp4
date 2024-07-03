#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// follow diagram. if match then is 0 cost else 1 cost
const int dr8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dc8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int r, c;
    cin >> r >> c;
    vector<vector<int>> grid(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            grid[i][j] = s[j] - '0';
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--, c1--, r2--, c2--;
        vector<vector<int>> dist(r, vector<int>(c, -1));
        deque<ii> dq;
        dq.push_front({r1, c1});
        dist[r1][c1] = 0;
        while (!dq.empty()) {
            ii u = dq.front();
            dq.pop_front();
            if (u.first == r2 && u.second == c2) {
                cout << dist[u.first][u.second] << endl;
                break;
            }
            for (int i = 0; i < 8; i++) {
                int r3 = u.first + dr8[i];
                int c3 = u.second + dc8[i];
                if (r3 >= 0 && r3 < r && c3 >= 0 && c3 < c) {
                    // unvisited or can improve
                    if (dist[r3][c3] == -1 || dist[r3][c3] > dist[u.first][u.second] + (i != grid[u.first][u.second])) {
                        if (i == grid[u.first][u.second]) {
                            dist[r3][c3] = dist[u.first][u.second];
                            dq.push_front({r3, c3});
                        } else {
                            dist[r3][c3] = dist[u.first][u.second] + 1;
                            dq.push_back({r3, c3});
                        }
                    }
                }
            }
        }
    }


    // bonus test case to understand the "can improve" part.
    // stepping to the 3 (1,3) has free move to 0 (2,4) and up to 3 (1,4) but (0,3) explores (1,4) 1st and set dist to 4
    /*
    3 5
    71004
    10733
    74440
    1
    1 1 2 5
     */

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}