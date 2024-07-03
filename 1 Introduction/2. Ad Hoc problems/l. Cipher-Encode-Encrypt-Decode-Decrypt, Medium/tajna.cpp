#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //freopen("error.txt", "w", stderr);


    string s, ans;
    cin >> s;
    int M = ceil(sqrt(s.length()));
    int x = 10000, y; // x col, y row
    for (int i = 1; i <= M; ++i) {
        if (s.length() % i == 0) {
            y = s.length() / i;
            x = i;
        }
    }
    if (x < y) swap(x, y);
    char arr[1000][1000];
    int k = 0;
    // arrange 1 col at a time
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            arr[j][i] = s[k++];
        }
    }
    // read 1 row at a time
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            ans += arr[i][j];
        }
    }
    cout << ans;
    cout << endl;

    cerr << "time taken : " << (float) clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}


