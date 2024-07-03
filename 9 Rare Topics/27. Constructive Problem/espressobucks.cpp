    #include <bits/stdc++.h>

    using namespace std;

    const int dirr[] = {0, 0, 1, -1};
    const int dirc[] = {1, -1, 0, 0};

    int main() {
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        //freopen("error.txt", "w", stderr);

        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int n, m;
        cin >> n >> m;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#') {
                    continue;
                }
                int found = 0;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dirr[k];
                    int nj = j + dirc[k];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (grid[ni][nj] == 'E') {
                            found = 1;
                            break;
                        }
                    }
                }
                if (!found) {
                    grid[i][j] = 'E';
                }
            }
        }
        for (int i = 0; i < n; i++) {
            cout << grid[i] << endl;
        }


        cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
        return 0;
    }
