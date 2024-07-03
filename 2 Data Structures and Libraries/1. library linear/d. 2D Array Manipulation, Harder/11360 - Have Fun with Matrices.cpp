#include <bits/stdc++.h>

using namespace std;


int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << endl;
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                matrix[i][j] = s[j] - '0';
            }
        }
        int m;
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            if (s == "row") {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                swap(matrix[a], matrix[b]);
            } else if (s == "col") {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                for (int i = 0; i < n; i++) {
                    swap(matrix[i][a], matrix[i][b]);
                }
            } else if (s == "inc") {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        matrix[i][j] = (matrix[i][j] + 1) % 10;
                }
            } else if (s == "dec") {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        matrix[i][j] = (matrix[i][j] + 9) % 10;
                }
            } else if (s == "transpose") {
                vector<vector<int>> temp(n, vector<int>(n));
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++)
                        temp[i][j] = matrix[j][i];
                }
                matrix = temp;
            }
        }
        for (auto &i: matrix) {
            for (int j: i) {
                cout << j;
            }
            cout << endl;
        }
        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
