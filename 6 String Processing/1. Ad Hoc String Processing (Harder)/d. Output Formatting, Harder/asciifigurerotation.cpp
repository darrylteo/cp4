#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, start = 1;
    string buf;
    while (getline(cin, buf), buf != "0") {
        if (start != 1) cout << '\n';
        start = 0;
        n = stoi(buf);
        vector<string> grid(n);
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            getline(cin, grid[i]);
            max_len = max(max_len, (int) grid[i].size());
        }
        for (int i = 0; i < n; i++) {
            while (grid[i].size() < max_len) {
                grid[i] += ' ';
            }
        }
        // rotate
        vector<string> old_data = grid;
        vector<string> new_data(max_len, string(n, ' '));
        for (int i = 0; i < max_len; i++) {
            for (int j = 0; j < n; j++) {
                new_data[i][j] = old_data[n - 1 - j][i];
            }
        }
        // swap '-' and '|'
        for (int i = 0; i < max_len; i++) {
            for (int j = 0; j < n; j++) {
                if (new_data[i][j] == '-') new_data[i][j] = '|';
                else if (new_data[i][j] == '|') new_data[i][j] = '-';
            }
        }
        // clear ws
        for (int i = 0; i < max_len; i++) {
            while (new_data[i].back() == ' ') {
                new_data[i].pop_back();
            }
        }
        // print
        for (int i = 0; i < max_len; i++) {
            cout << new_data[i] << '\n';
        }
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

