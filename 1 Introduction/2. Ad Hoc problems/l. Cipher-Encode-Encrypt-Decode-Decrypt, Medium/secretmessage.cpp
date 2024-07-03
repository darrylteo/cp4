#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int n;
    cin >> n;
    while (n--){
        string s, ans;
        cin >> s;
        int M = ceil(sqrt(s.length()));
        char arr[M][M];
        int k = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < M; ++j) {
                if (k < s.length()) {
                    arr[i][j] = s[k++];
                } else {
                    arr[i][j] = '*';
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = M - 1; j >= 0; --j) {
                if (arr[j][i] != '*') {
                    ans += arr[j][i]; // i fixes the column and j means we go up the column
                }
            }
        }
        cout << ans;



        cout << endl;
    }

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


