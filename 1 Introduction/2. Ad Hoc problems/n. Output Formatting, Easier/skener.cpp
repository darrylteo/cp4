#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    int R, C, Zr, Zc;
    cin >> R >> C >> Zr >> Zc;
    char arr[R][C];
    for (int i = 0; i < R; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++) {
            arr[i][j] = s[j];
        }
    }
    for (int i = 0; i < R; i++) {
        for (int k = 0; k < Zr; k++) {
            for (int j = 0; j < C; j++) {
                for (int l = 0; l < Zc; l++) {
                    cout << arr[i][j];
                }
            }
            cout << endl;
        }
    }


    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}