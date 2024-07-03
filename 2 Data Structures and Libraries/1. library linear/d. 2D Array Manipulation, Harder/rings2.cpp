    #include <bits/stdc++.h>

    using namespace std;

    bool complete (vector<vector<int>> &grid, int n, int m) {
        // check if all are filled
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (grid[i][j] == -1)
                    return false;
        }
        return true;
    }

    int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("error.txt", "w", stderr);

        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                grid[i][j] = s[j];
        }

        // fill first ring
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // either beside a '.' or on edges are ring 1
                if (grid[i][j] == 'T' && (i == 0 || j == 0 || i == n - 1 || j == m - 1 ||
                                          grid[i - 1][j] == '.' || grid[i][j - 1] == '.' ||
                                          grid[i + 1][j] == '.' || grid[i][j + 1] == '.')) {
                    grid[i][j] = '1';
                }
            }
        }

        // convert all to ints (easier to work with esp when >= 10)
        vector<vector<int>> grid_int(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'T') {
                    grid_int[i][j] = -1;
                } else if (grid[i][j] == '.') {
                    grid_int[i][j] = 0;
                } else {
                    grid_int[i][j] = 1;
                }
            }
        }

        int ringNo = 1;
        vector<vector<int>> tmp = grid_int;
        while (!complete(grid_int, n, m)) {
            // fill next ring
            ringNo++;
            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < m - 1; j++) {
                    int left = grid_int[i][j - 1], right = grid_int[i][j + 1], up = grid_int[i - 1][j], down = grid_int[i + 1][j];
                    int checkSides = max(max(left, right), max(up, down));
                    // if current is empty and all neighbours are filled, fill current
                    if (grid_int[i][j] == -1 && checkSides > 0) {
                        tmp[i][j] = ringNo;
                    }
                }
            }
            grid_int = tmp;
        }

        // print
        int maxRing = 0;
        for (int i = 0; i < n; i++) {
            for (int j : grid_int[i]) {
                maxRing = max(maxRing, j);
            }
        }
        if (maxRing < 10) {
            for (int i = 0; i < n; i++) {
                string s;
                for (int j = 0; j < m; j++) {
                    if (grid_int[i][j] == 0) {
                        s += "..";
                    } else {
                        s += '.' + to_string(grid_int[i][j]);
                    }
                }
                cout << s << endl;
            }
        } else {
            for (int i = 0; i < n; i++) {
                string s;
                for (int j = 0; j < m; j++) {
                    if (grid_int[i][j] == 0) {
                        s += "...";
                    } else if (grid_int[i][j] < 10) {
                        s += ".." + to_string(grid_int[i][j]);
                    } else {
                        s += "." + to_string(grid_int[i][j]);
                    }
                }
                cout << s << endl;
            }
        }
    


        cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
        return 0;
    }
