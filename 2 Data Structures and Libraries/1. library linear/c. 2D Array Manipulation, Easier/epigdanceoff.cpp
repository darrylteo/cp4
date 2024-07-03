#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    vector<string> grid(2000);
    int n, m, line = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid[i] = s;
    }
    for (int j = 0; j < m; j++) {
        bool allBlank = true;
        for (int i = 0; i < n; i++) {
            if (grid[i][j] != '_') {
                allBlank = false;
                break;
            }
        }
        if (allBlank) {
            line++;
        }
    }

    cout << line + 1 << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




