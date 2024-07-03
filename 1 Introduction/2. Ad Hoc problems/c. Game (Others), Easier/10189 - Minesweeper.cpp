#include <bits/stdc++.h>

using namespace std;

int n, m, x = 1;
string line;
vector<string> board;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    while (scanf("%d %d", &n, &m), n) {
        board.clear();
        for (int i = 0; i < n; i++) {
            cin >> line;
            board.push_back(line);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == '*') {
                    continue;
                }
                int count = 0;
                for (int k = i - 1; k <= i + 1; ++k) {
                    for (int l = j - 1; l <= j + 1; ++l) {
                        if (k < 0 || k >= n || l < 0 || l >= m) {
                            continue;
                        }
                        if (board[k][l] == '*') {
                            count++;
                        }
                    }
                }
                board[i][j] = count + '0';
            }
        }

        if (x > 1) {
            cout << endl;
        }
        printf("Field #%d:\n", x);
        for (int i = 0; i < n; i++) {
            cout << board[i] << endl;
        }

        x++;
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}

