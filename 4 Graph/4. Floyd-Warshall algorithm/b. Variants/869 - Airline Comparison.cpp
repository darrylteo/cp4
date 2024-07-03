#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int m1, m2, grid1[26][26] = {}, grid2[26][26] = {};
        cin >> m1;
        for (int i = 0; i < m1; i++) {
            char u, v;
            cin >> u >> v;
            grid1[u - 'A'][v - 'A'] = 1;
            grid1[v - 'A'][u - 'A'] = 1;
        }
        cin >> m2;
        for (int i = 0; i < m2; i++) {
            char u, v;
            cin >> u >> v;
            grid2[u - 'A'][v - 'A'] = 1;
            grid2[v - 'A'][u - 'A'] = 1;
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    grid1[i][j] |= grid1[i][k] & grid1[k][j];
                }
            }
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    grid2[i][j] |= grid2[i][k] & grid2[k][j];
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (i == j) continue;
                if (grid2[i][j] != grid1[i][j]) {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
        if (T) cout << '\n';
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}




