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


    int T;
    cin >> T;
    while (T--) {
        vector<string> ans;
        string s;
        cin >> s;
        int r = s[0] - 'a';
        int c = s[1] - '1';
        vector<vi> moves2here(8, vi(8, -1));
        queue<ii> q;
        q.push({r, c});
        moves2here[r][c] = 0;
        while (!q.empty()) {
            ii u = q.front();
            q.pop();
            for (int i = 0; i < 8; i++) {
                int r2 = u.first + drK[i];
                int c2 = u.second + dcK[i];
                if (r2 >= 0 && r2 < 8 && c2 >= 0 && c2 < 8 && moves2here[r2][c2] == -1) {
                    moves2here[r2][c2] = moves2here[u.first][u.second] + 1;
                    q.push({r2, c2});
                }
            }
        }



        int maxMoves = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                maxMoves = max(maxMoves, moves2here[i][j]);
            }
        }
        // collect all maxmove cells into ans
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (moves2here[i][j] == maxMoves) {
                    string tmp;
                    tmp.push_back('a' + i);
                    tmp.push_back('1' + j);
                    ans.push_back(tmp);
                    tmp.clear();
                }
            }
        }
        // sort
        sort(ans.begin(), ans.end(), [](const string &a, const string &b) {
            if (a[1] == b[1]) {
                return a[0] < b[0];
            }
            return a[1] > b[1];
        });
        cout << maxMoves;
        for (auto &i : ans) {
            cout << " " << i;
        }
        cout << endl;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}