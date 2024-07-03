#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        vector<string> v(a);
        string s;
        for (int i = 0; i < a; i++) {
            cin >> s;
            v[i] = s;
        }
        // keep track for each col, how many of each letter is there
        vector<vector<int>> count(b, vector<int>(4, 0)); // A, C, G, T
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < a; j++) {
                if (v[j][i] == 'A') count[i][0]++;
                else if (v[j][i] == 'C') count[i][1]++;
                else if (v[j][i] == 'G') count[i][2]++;
                else if (v[j][i] == 'T') count[i][3]++;
            }
        }
        // collect the most common letter of each column
        vector<char> ans;
        for (int i = 0; i < b; i++) {
            int max = 0;
            for (int j = 0; j < 4; j++) {
                if (count[i][j] > max) {
                    max = count[i][j];
                }
            }
            char c;
            for (int j = 0; j < 4; j++) {
                if (count[i][j] == max) {
                    if (j == 0) ans.push_back('A');
                    else if (j == 1) ans.push_back('C');
                    else if (j == 2) ans.push_back('G');
                    else if (j == 3) ans.push_back('T');
                    break;
                }
            }
        }

        for (int i = 0; i < b; i++) {
            cout << ans[i];
        }
        cout << endl;

        int consensus = 0;
        for (int i = 0; i < b; i++) {
            if (ans[i] == 'A') {
                consensus += a - count[i][0]; // count how many differ from the "best" char in col i
            } else if (ans[i] == 'C') {
                consensus += a - count[i][1];
            } else if (ans[i] == 'G') {
                consensus += a - count[i][2];
            } else if (ans[i] == 'T') {
                consensus += a - count[i][3];
            }
        }
        cout << consensus << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
