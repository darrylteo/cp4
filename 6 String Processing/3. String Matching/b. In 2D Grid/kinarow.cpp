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
    int h = 0, g = 0; // hansel uses x, gretel uses o
    cin >> T;
    for (int t = 1; t <= T; t++) {
        next:
        if (t > T) break;
        int R, C, K;
        cin >> C >> R >> K;
        vector<string> grid(R);
        for (int i = 0; i < R; i++) cin >> grid[i];

        for (int i = 0; i < 2; ++i) {
            string s(K, i ? 'x' : 'o'); // K marks in a row
            int n = s.size();
            for (int r = 0; r < R; r++) {
                for (int c = 0; c < C; c++) {
                    if (grid[r][c] == s[0]) {
                        for (int ii = 0; ii < 8; ii++) {
                            int r1 = r, c1 = c;
                            bool found = true;
                            for (int j = 1; j < n; j++) {
                                r1 += dirr8[ii];
                                c1 += dirc8[ii];
                                if (r1 < 0 || r1 >= R || c1 < 0 || c1 >= C || grid[r1][c1] != s[j]) {
                                    found = false;
                                    break;
                                }
                            }
                            if (found) {
                                if (i) h++;
                                else g++;
                                t++;
                                goto next; // playing with fire :P
                            }
                        }
                    }
                }
            }
        }
    }
    cout << h << ":" << g << '\n';

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


