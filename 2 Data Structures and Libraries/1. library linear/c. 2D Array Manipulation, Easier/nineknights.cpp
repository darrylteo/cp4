#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);

    char board[5][5];
    string s;
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        cin >> s;
        for (int j = 0; j < 5; j++) {
            board[i][j] = s[j];
            if (board[i][j] == 'k') cnt++;
        }
    }
    if (cnt != 9) {
        cout << "invalid" << endl;
        return 0;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            if (board[i][j] == 'k') {
                if (i - 2 >= 0 && j - 1 >= 0 && board[i - 2][j - 1] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i - 2 >= 0 && j + 1 < 5 && board[i - 2][j + 1] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i - 1 >= 0 && j - 2 >= 0 && board[i - 1][j - 2] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i - 1 >= 0 && j + 2 < 5 && board[i - 1][j + 2] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i + 1 < 5 && j - 2 >= 0 && board[i + 1][j - 2] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i + 1 < 5 && j + 2 < 5 && board[i + 1][j + 2] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i + 2 < 5 && j - 1 >= 0 && board[i + 2][j - 1] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
                if (i + 2 < 5 && j + 1 < 5 && board[i + 2][j + 1] == 'k') {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "valid" << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
