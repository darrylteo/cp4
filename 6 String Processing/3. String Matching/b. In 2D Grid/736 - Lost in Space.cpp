#include <bits/stdc++.h>

using namespace std;

string dirNames[] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
int dirr8[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dirc8[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    string buf;
    cin >> T >> ws;
    for (int t = 1; t <= T; t++) {
        if (t > 1) cout << '\n';
        int N;
        cin >> N;
        cin.ignore();
        vector<string> grid(N);
        for (int i = 0; i < N; i++) {
            getline(cin, grid[i]);
        }

        string s;
        while (getline(cin, s)) {
            if (s.empty()) break;
            cout << '\n' << s << '\n';
            int n = s.size(), any = 0;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    if (grid[r][c] == s[0]) {
                        for (int i = 0; i < 8; i++) {
                            int r1 = r, c1 = c;
                            bool found = true;
                            for (int j = 1; j < n; j++) {
                                r1 += dirr8[i];
                                c1 += dirc8[i];
                                // skip spaces for this qn.
                                if (r1 >= 0 && r1 < N && c1 >= 0 && c1 < N && grid[r1][c1] == ' ') {
                                    j--;
                                    continue;
                                }
                                if (r1 < 0 || r1 >= N || c1 < 0 || c1 >= N || grid[r1][c1] != s[j]) {
                                    found = false;
                                    break;
                                }
                            }
                            if (found) {
                                any = 1;
                                cout << "(" << r + 1 << "," << c + 1 << ") - " << dirNames[i] << '\n';
                            }
                        }
                    }
                }
            }
            if (!any) cout << "not found\n";
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


