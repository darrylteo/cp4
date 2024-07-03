#include <bits/stdc++.h>

using namespace std;

// for each letter have to check up down left right and find manhattan distance

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> grid(4, vector<char>(4));
    vector<vector<char>> original(4, vector<char>(4));
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 4; j++) {
            grid[i][j] = s[j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            original[i][j] = 'A' + 4 * i + j;
        }
    }
    original[3][3] = '.';

    int ans = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (grid[x][y] == '.') continue;
            for (int i = -3; i <= 3; i++) {
                for (int j = -3; j <= 3; j++) {
                    if (i == 0 && j == 0) continue; // no need to check itself (count as don't add to ans)
                    int nx = x + i;
                    int ny = y + j;
                    if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
                    if (original[nx][ny] == grid[x][y]) {
                        ans += abs(i) + abs(j);
                    }
                }
            }
        }
    }
    cout << ans << '\n';


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << '\n';
    return 0;
}
