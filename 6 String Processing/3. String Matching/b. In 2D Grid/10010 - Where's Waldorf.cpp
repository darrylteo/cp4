#include <bits/stdc++.h>

using namespace std;

int dirr8[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dirc8[] = {1, -1, 0, 0, 1, -1, -1, 1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        if (t > 1) cout << '\n';
        int R, C;
        cin >> R >> C;
        vector<string> grid(R);
        for (int i = 0; i < R; i++) {
            cin >> grid[i];
            transform(grid[i].begin(), grid[i].end(), grid[i].begin(), ::toupper); // convert to uppercase
        }
        int Q;
        cin >> Q;
        int q = 0;
        done:
        for (; q < Q;) {
            string s;
            cin >> s;
            transform(s.begin(), s.end(), s.begin(), ::toupper); // convert to uppercase
            int n = s.size();
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (grid[r][c] == s[0]) {
                        for (int i = 0; i < 8; i++) {
                            int r1 = r, c1 = c;
                            bool found = true;
                            for (int j = 1; j < n; j++) {
                                r1 += dirr8[i];
                                c1 += dirc8[i];
                                if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C || grid[r1][c1] != s[j]) {
                                    found = false;
                                    break;
                                }
                            }
                            if (found) {
                                cout << r + 1 << " " << c + 1 << endl;
                                q++;
                                goto done;
                            }
                        }
                    }
                }
            }
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


