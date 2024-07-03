#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int drK[] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dcK[] = {1, -1, 1, -1, 2, -2, 2, -2};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);


    int r1, c1, r2, c2;
    string s1, s2;
    while (cin >> s1 >> s2) {
        vector<string> ans;
        r1 = s1[0] - 'a';
        c1 = s1[1] - '1';
        r2 = s2[0] - 'a';
        c2 = s2[1] - '1';
        vector<vi> moves2here(8, vi(8, -1));
        queue<ii> q;
        q.emplace(r1, c1);
        moves2here[r1][c1] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            if (u.first == r2 && u.second == c2) break;
            for (int i = 0; i < 8; i++) {
                int rn = u.first + drK[i];
                int cn = u.second + dcK[i];
                if (rn >= 0 && rn < 8 && cn >= 0 && cn < 8 && moves2here[rn][cn] == -1) {
                    moves2here[rn][cn] = moves2here[u.first][u.second] + 1;
                    q.emplace(rn, cn);
                }
            }

        }
        cout << "To get from " << s1 << " to " << s2 << " takes " << moves2here[r2][c2] << " knight moves." << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}